#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <cassert>


namespace custom
{
    /**************************************************
     * queue
     * First-in-First-out data structure
     *************************************************/
   template <class T>
   class queue
   {
      public:
         // constructors, destructors, and assignment operator
         queue() : data(NULL), numCapacity(0), numPush(0), numPop(0) { }
         queue(int max) throw(const char *);
         queue(const queue <T> & rhs) throw(const char *);
         ~queue() { if (numCapacity != 0) delete [] data; }
         queue <T> & operator = (const queue <T> & rhs) throw (const char *);
        
         // standard container interfaces
         int size() const { return numPush - numPop; }
         int capacity() const { return numCapacity; }
         bool empty() const { return size() == 0; }
         void clear() { numPush = numPop = 0; }
          
         // queue-specific interfaces
         void push(const T & t) throw(const char *);
         void pop();
         T & front() throw(const char *);
         T & back() throw(const char *);
        
         void display() const;
        
      private:
         // grow the queue as necessary. This will double the size
         void resize(int newCapacity = 0) throw(const char *);
        
         // find the index of the head or the tail in the data array
         int iTail() const
         {
            assert(numCapacity != 0);
            return (numPush - 1) % numCapacity;
         }
         int iHead() const
         {
            assert(numCapacity != 0);
            return numPop % numCapacity;
         }
        
         // member variables
         T * data; // dynamically allocated data for the queue
         int numCapacity; // the size of the data array
         int numPush; // number of items ever pushed to the queue
         int numPop; // number of items ever popped from the queue        
   };
    
   /**********************************************************************
    * QUEUE :: ASSIGNMENT = OPERATOR
    * Assignment Operator
    ***********************************************************************/
   template <class T>
   queue <T> & queue<T>::operator = (const queue <T> & rhs) throw (const char *)
   {
      this->clear();
        
      if (this->numCapacity < rhs.size())
         this->resize(rhs.size());
            
      for(int i = rhs.numPop; i < rhs.numPush; i++)
         this->push(rhs.data[i % rhs.numCapacity]);
                
      return *this;
   }
    
   /**********************************************************************
    * QUEUE :: QUEUE
    * Non-default constructor
    ***********************************************************************/
   template<class T>
   queue<T>::queue(int max) throw(const char *)
   {
      numPush = 0;
      numPop = 0;
      numCapacity = 0;
      data = NULL;
      if(max > 0)
         resize(max);
   }
    
   /**********************************************************************
    * QUEUE :: QUEUE
    * Copy constructor
    ***********************************************************************/
   template<class T>
   queue<T>::queue(const queue <T> & rhs) throw(const char *)
   {
      numPush = 0;
      numPop = 0;
      numCapacity = 0;
      data = NULL;
      if(rhs.size() > 0)
         *this = rhs;
   }
    
   /**********************************************************************
    * QUEUE :: PUSH
    * Push an element on to the tail of the queue
    ***********************************************************************/
   template<class T>
   void queue<T>::push(const T & t) throw(const char *)
   {
      if (size() == capacity())
         resize();
      numPush++;
      data[iTail()] = t;
   }
    
   /**********************************************************************
    * QUEUE :: POP
    * Pop the head element off of the queue
    ***********************************************************************/
   template<class T>
   void queue<T>::pop()
   {
      if (!empty())
         numPop++;
   }
    
   /**********************************************************************
    * QUEUE :: FRONT
    * Access the element at the front of the queue
    ***********************************************************************/
   template<class T>
   T & queue<T>::front() throw(const char *)
   {
      if (empty())
         throw "ERROR: attempting to access an element in an empty queue";
      else
         return data[iHead()];
   }
    
   /**********************************************************************
    * QUEUE :: BACK
    * Access the element at the back of the queue
    ***********************************************************************/
   template<class T>
   T & queue<T>::back() throw(const char *)
   {
      if (empty())
         throw "ERROR: attempting to access an element in an empty queue";
      else
         return data[iTail()];
   }
    
   /**********************************************************************
    * QUEUE :: DISPLAY
    * Display information about the contents of the queue
    ***********************************************************************/
   template<class T>
   void queue<T>::display() const
   {
      std::cout << "queue info:\n";
      std::cout << size() << ":";
      for(int i = iHead();i <= iTail();i++)
      {
         if(i != iHead())
            std::cout << ",";
         std::cout << data[i];
      }
      std::cout << '\n';
   }
        
   /*********************************************************
    * QUEUE :: RESIZE
    * Grow the size of the queue to (at a minimum) of a given
    * size. If the size is set to zero, then the capacity will
    * be doubled. If the stack is currently not empty, the contents
    * will be copied over to the new buffer
    *********************************************************/
   template <class T>
   void queue <T> :: resize(int newCapacity) throw(const char *)
   {
      assert(newCapacity >= 0);
        
      // determine the new buffer size
      if (newCapacity == 0)
         newCapacity = (numCapacity != 0 ? numCapacity * 2 : 1);
            
      // allocate the new buffer
      T * newData = new(std::nothrow) T[newCapacity];
      if (NULL == newData)
         throw "ERROR: Unable to allocate a new buffer for queue";
        
      // copy the data
      int iDestination = 0;
      for (int iSource = numPop; iSource < numPush; iSource++)
         newData[iDestination++] = data[iSource % numCapacity];
            
      // set the new capacity, numPush, and numPop
      numCapacity = newCapacity;
      numPop = 0;
      numPush = iDestination;
            
      // free the old
      if (NULL != data)
         delete [] data;
      data = newData;
   }    
};

#endif
