/***********************************************************************
 * Header:
 *    Deque
 * Summary:
 *    This is built to act like the deque class in the STL
 * Author
 *    John Batty
 *    Jordon Thompson
 *    Brian Thompson
 *    Emmanuel Gatica
 *    Zach Caldwell
 ************************************************************************/

#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <cassert>
using namespace std;


namespace custom
{
   /**************************************************
    * deque
    * Double-ended Queue data structure
    *************************************************/
   template <class T>
      class deque
   {
     public:
      // constructors, destructors, and assignment operator
      deque() : data(NULL), numCapacity(0), iBack(-1), iFront(0) { }
      deque(int max);
      deque(const deque <T> & rhs);
      ~deque() { if (numCapacity != 0) delete [] data; }
      deque <T> & operator = (const deque <T> & rhs);

      // standard container interfaces
      int size() const { return iBack - iFront + 1; }
      int capacity() const { return numCapacity; }
      bool empty() const { return size() == 0; }
      void clear() { iBack = -1; iFront = 0; }

      // deque-specific interfaces
      void pop_front();
      void push_front(const T & t);
      void pop_back();
      void push_back(const T & t);
      T & front();
      T & back();

      void display() const;

     private:
      // grow the deque as necessary. This will double the size
      void resize(int newCapacity = 0);

      // find the index of the head or the tail in the data array
      int iHead() const { return iNormalize(iFront); }
      int iTail() const { return iNormalize(iBack); }

      // Normalizes value passed in
      int iNormalize(int i) const
      {
         return (i >= 0) ? (i % capacity()) :
         (capacity() - ((-1 - i) % capacity()) - 1);
      }

      // member variables
      T * data; // dynamically allocated data for the deque
      int numCapacity; // the size of the data array
      int iBack; // location of the back of the deque
      int iFront; // location of the front of the deque
      // used to normalize iBack and IFront
      int getIBack() const { return iNormalize(iBack); }
      int getIFront() const { return iNormalize(iFront); }
   };

   /**********************************************************************
    * DEQUE :: ASSIGNMENT = OPERATOR
    * Assignment Operator
    ***********************************************************************/
   template <class T>
      deque <T> & deque<T>::operator = (const deque <T> & rhs)
      {
         this->clear();

         if (this->numCapacity < rhs.capacity())
            this->resize(rhs.capacity());

         for(int i = 0; i < rhs.capacity(); i++)
            this->data[i] = rhs.data[i];
         iFront = rhs.iFront;
         iBack  = rhs.iBack;

         return *this;
      }

   /**********************************************************************
    * DEQUE :: DEQUE
    * Non-default constructor
    ***********************************************************************/
   template<class T>
      deque<T>::deque(int max)
   {
      clear();
      numCapacity = 0;
      data = NULL;
      resize(max);
   }

   /**********************************************************************
    * DEQUE :: DEQUE
    * Copy constructor
    ***********************************************************************/
   template<class T>
      deque<T>::deque(const deque <T> & rhs)
   {
      data = NULL;
      numCapacity = 0;
      *this = rhs;
   }

   /**********************************************************************
    * DEQUE :: POP_FRONT
    * Pop the head element off of the deque
    ***********************************************************************/
   template<class T>
      void deque<T>::pop_front()
   {
      if (!empty())
         iFront++;
   }

   /**********************************************************************
    * DEQUE :: PUSH_FRONT
    * Push an element on to the tail of the deque
    **********************************************************************/
   template<class T>
      void deque<T>::push_front(const T & t)
   {
      //cout << "iFront: " << iFront << ", iNormalize(--iFront): " << iNormalize(iFront - 1) << ", size(): " << size() << ", capacity(): " << capacity() << endl;
      if (size() == capacity())
         resize(capacity() * 2);
      iFront--;
      data[iNormalize(iFront)] = t;      
   }

   /**********************************************************************
    * DEQUE :: POP_BACK
    * Pop the head element off of the deque
    ***********************************************************************/
   template<class T>
      void deque<T>::pop_back()
   {
      if (!empty())
         iBack--;
   }

   /**********************************************************************
    * DEQUE :: PUSH_BACK
    * Push an element on to the tail of the deque
    ***********************************************************************/
   template<class T>
      void deque<T>::push_back(const T & t)
   {
      //cout << "iBack: " << iBack << ", iNormalize(++iBack): " << iNormalize(iBack + 1) << ", size(): " << size() << ", capacity(): " << capacity() << endl;
      if (size() == capacity())
         resize(capacity() * 2);
      iBack++;
      data[iNormalize(iBack)] = t;
   }

   /**********************************************************************
    * DEQUE :: FRONT
    * Access the element at the front of the deque
    ***********************************************************************/
   template<class T>
      T & deque<T>::front()
   {
      if (empty())
         throw "ERROR: unable to access data from an empty deque";
      else
         return data[iNormalize(iFront)];
   }

   /**********************************************************************
    * DEQUE :: BACK
    * Access the element at the back of the deque
    ***********************************************************************/
   template<class T>
      T & deque<T>::back()
   {
      if (empty())
         throw "ERROR: unable to access data from an empty deque";
      else
         return data[iNormalize(iBack)];
   }

   /**********************************************************************
    * DEQUE :: DISPLAY
    * Display information about the contents of the deque
    ***********************************************************************/
   template<class T>
      void deque<T>::display() const
   {
      std::cout << "deque info:\n";
      std::cout << size() << ":";
      for(int i = iHead();i <= iTail();i++)
      {
         if(i != iHead())
            std::cout << ",";
         std::cout << data[i % capacity()];
      }
      std::cout << '\n';
   }

   /*********************************************************
    * DEQUE :: RESIZE
    * Grow the size of the deque to (at a minimum) of a given
    * size. If the size is set to zero, then the capacity will
    * be doubled. If the stack is currently not empty, the contents
    * will be copied over to the new buffer
    *********************************************************/
   template <class T>
      void deque <T> :: resize(int newCapacity)
   {
      assert(newCapacity >= 0);

      // determine the new buffer size
      if (newCapacity <= 0 || newCapacity < numCapacity)
         newCapacity = (numCapacity ? numCapacity * 2 : 1);

      // allocate the new buffer
      T * newData = new(std::nothrow) T[newCapacity];
      if (NULL == newData)
         throw "ERROR: Unable to allocate a new buffer for deque";

      // copy the data
      int iDestination = -1;
      if (data != NULL)
      {
         for (int i = iFront; i <= iBack; i++)
            newData[++iDestination] = data[iNormalize(i)];
         delete [] data;
      }

      // set the new capacity, iBack, iFront, and the new array
      iFront = 0;
      iBack = iDestination;
      numCapacity = newCapacity;
      data = newData;
   }
};

#endif