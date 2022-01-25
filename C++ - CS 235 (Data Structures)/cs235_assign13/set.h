/***********************************************************************
 * Header:
 *    Set
 * Summary:
 *    This is a set structure that stores unique sorted values.
 * Author
 *    John Batty
 *    Jordon Thompson
 *    Brian Thompson
 *    Emmanuel Gatica
 *    Zach Caldwell
 ************************************************************************/

#ifndef SET_H
#define SET_H

#include <iostream>
#include <cassert>
using namespace std;

namespace custom
{
   /**************************************************
    * set
    * Data structure for storing unique elements
    *************************************************/
   template <class T>
   class set
   {
    public:
      // constructors, destructors, and assignment operator
      set(): numSize(0), data(NULL), numCapacity(0) { }
      // constructor with a size      
      set(int capacity)
      {
         numCapacity = 0;
         numSize = 0;
         data = NULL;
         resize(capacity);
      }
      // copy contructor
      set(const set <T> & rhs)
      {
         data = NULL;
         numCapacity = 0;
         *this = rhs;            
      }
      // decontructor
      ~set() { /*this->clear(); */ }
       
       //Operators
       set <T> & operator = (const set <T> & rhs);
       set<T> operator || (const set<T>& rhs);
       set<T> operator && (const set<T>& rhs);
       set<T> operator - (const set<T>& rhs) const;

      //standard container interfaces
      int  size()  const { return numSize;      }
      bool empty() const { return size() == 0;  }
      void clear() {
         numCapacity = 0;
         numSize = 0;
//         if (data != NULL) {
           // delete [] data;
            data = NULL;
//         }            
      }
       
      // these classes need to be defined before they are used in the class
      class iterator;
      class const_iterator;
       
      // while in set<T>, set<T>::iterator does not have to be used
      iterator find(const T & element) const;
      void     insert(const T & element);
      iterator erase(iterator &it);
      void addToEnd(const T & t);
      

      // the various iterator interfaces
      iterator begin()               { return iterator(data); }
      iterator end()                 { return iterator(data + numSize); }
      const_iterator cbegin() const  { return const_iterator(data); }
      const_iterator cend()   const  { return const_iterator(data + numSize); }

      //Display for debugging purposes.
      void display() const;

    private:
      // member variables
      unsigned int numSize; // the total number of elements
      int numCapacity;
      T * data;

      // member functions
      void resize(unsigned int capacity);
      int findIndex(T & t);
      int findIndex(const T & t) const;
   };


/***** End of class definition, start of function bodies *****/


   /**********************************************************************
    * SET :: ASSIGNMENT = OPERATOR
    * Assignment Operator
    ***********************************************************************/
   template <class T>
   set <T> & set<T>::operator = (const set <T> & rhs)
   {
      this->clear();                                 
      this->resize(rhs.numCapacity);
      for (unsigned int i = 0; i < rhs.size(); ++i)
          data[i] = rhs.data[i];
      numSize = rhs.size();
      return *this;
   }

   /**********************************************************************
    * SET :: RESIZE
    * Resize the total capacity of the set
    ***********************************************************************/
   template<class T>
   void set<T>::resize(unsigned int capacity)
   {
      if (capacity >= numCapacity) //If parameter passed is not less than current capactiy
      {
         // Just to be safe
         //  Debug(if(data == NULL) assert((numSize == 0) && (numCapacity == 0)));
         if (capacity == 0)
           capacity = (numCapacity == 0) ? 1 : numCapacity * 2;

         //Allocate New Memory
         T* newdata;
         try
         {
            newdata = new T[capacity];
         }
         catch(...) //Catch if bad allocation.
         {
            throw "ERROR: Unable to allocate a new buffer for set.";
         }

         //Copy over data from the old memory.
         for (unsigned int i = 0; i < numSize; ++i)
            newdata[i] = data[i];
         if (data) delete [] data;
         data = newdata;
         numCapacity = capacity;
    }
    else //If parameter passed was less than current capacity.
    {
    // If the new capacity is smaller, assume we're intending to clear elements
    if (numSize > capacity)
        numSize = capacity;
      }
   }

   /**********************************************************************
    * SET :: Find Index
    * Recieves an element as a parameter and searches the array. If the element
    * is found, this method returns the index where the element is located. Otherwise
    * returns numSize (one above top of the array);
    ***********************************************************************/
   template <class T>
   int set<T>::findIndex(const T & t) const
   {
      int iFront = 0;
      int iBack = numSize - 1;
      int iMiddle;
      //Binary Search Algorithm
      while(iFront <= iBack)
      {
         iMiddle = (iFront + iBack) / 2;    //Check element in middle of array
            if (t == data[iMiddle])         //If element is match, stop searching.
               return iMiddle;
            else if (t > data[iMiddle])     //If element is smaller than target, only search higher.
               iFront = iMiddle + 1;
            else                            //Otherwise, element must be larger than target. Only search lower.
               iBack = iMiddle - 1;
      }
      return numSize;
   }              

   /**************************************************
    * SET :: FIND
    * Returns an iterator to the element being searched for
    *************************************************/
   template <class T>
   typename set<T>::iterator set<T>::find(const T & element) const
   {         
      iterator location = cbegin() + findIndex(element);         
      return location;
   }

   /**************************************************
    * SET :: INSERT
    * Searches for the passed in element if it does not
    * exist it is then inserted
    *************************************************/
   template <class T>
   void set<T>::insert(const T & element)
   {
      // check to see if element is already in set
      int iInsert = findIndex(element);

      if (iInsert == numSize)
      {
         //Resize if needed
         if (numSize == numCapacity)
            resize(numCapacity * 2);
                  
         // find where the new index will be
         for(iInsert = 0;iInsert < numSize && data[iInsert] < element;
            iInsert++);

         // push everything behind the iterator back one
         for (int i = numSize; i >= iInsert; i--)
            if (i +1 < numCapacity)
               data[i + 1] = data[i];
         data[iInsert] = element;
         numSize++;
      }            
   }

   /**************************************************
    * SET :: Erase
    * Erase the element at the passed in index
    *************************************************/
   template <class T>
   typename set<T>::iterator set<T>::erase(set <T>::iterator &it)
   {
      // Shift the rest of the array back, over the top of the passed iterator
      if(it < begin() || it > end())
         throw "Error: in function set::erase(iterator) iterator index out of bounds";
      for(iterator iErase = it;iErase < end() - 1;iErase++)
         *iErase = *(iErase + 1);
      numSize--;
      return it;
   }

   /**************************************************
    * SET :: AddToEnd
    * Adds a value to the end of the function just like
    * a push function on a stack
    *************************************************/
    // This function can't be const because numSize changes
   template <class T>
   void set<T>::addToEnd(const T & t)
   {
      if (numCapacity == numSize)
         resize(numCapacity * 2);

      this->data[numSize++] = t;
   }

   /**************************************************
    * SET :: Union
    * Return a set containing a union of this and rhs.
    *************************************************/
   template <class T>
   set<T> set<T>::operator || (const set<T>& rhs)
   {
      int iLhs = 0;
      int iRhs = 0;
      set<T> setReturn(numSize + rhs.numSize); //The new Set to be returned.

      //Keep adding elements until we have checked all elements in both arrays.
      while (iLhs < this->numSize || iRhs < rhs.numSize)
         {
            if (iLhs == this->numSize)      //If we are out of elements in the left hand side.
               setReturn.addToEnd(rhs.data[iRhs++]); //Finish adding right hand side.
            else if (iRhs == rhs.numSize)   //If we are out of elements in the right hand side.
               setReturn.addToEnd(this->data[iLhs++]); //Finish adding left hand side.
            else if (this->data[iLhs] == rhs.data[iRhs]) //If the data is found in both
               {
                  setReturn.addToEnd(this->data[iLhs]);  //add to end and increment both.
                  iLhs++;
                  iRhs++;
               }
            else if (this->data[iLhs] < rhs.data[iRhs]) //If LHS is less than RHS.
               setReturn.addToEnd(this->data[iLhs++]);  //Add value found in LHS and increment
            else                                        //if RHS is less than RHS
               setReturn.addToEnd(rhs.data[iRhs++]);    //Add value found in RHS and increment
         }
      return setReturn;
   }

   /**************************************************
    * SET :: Intersection
    * Return a set containing an intersection of this and rhs.
    *************************************************/
   template <class T>
   set<T> set<T>::operator && (const set<T>& rhs)
   {
      int iLhs = 0;
      int iRhs = 0;
      set<T> setReturn(numSize + rhs.numSize);
      
       //Keep adding elements until we have checked all elements in both arrays.
      while (iLhs < this->numSize || iRhs < rhs.numSize)
         {
            //Return if one side is at end
            if (iLhs == this->numSize)
               return setReturn;
            else if (iRhs == rhs.numSize)
               return setReturn;
            //If both are equal, add value to end and increment both.
            else if (this->data[iLhs] == rhs.data[iRhs])
               {
                  setReturn.addToEnd(this->data[iLhs]);
                  iLhs++;
                  iRhs++;
               }
             //Otherwise, increment the side with the lowest value at current index.
            else if (this->data[iLhs] < rhs.data[iRhs])
               iLhs++;
            else
               iRhs++;
         }
      return setReturn;
   }

   /**************************************************
    * SET :: Difference
    * Return a set containing the difference of this and rhs.
    *************************************************/
   template <class T>
   set<T> set<T>::operator - (const set& rhs) const
   {
      int iLhs = 0;
      int iRhs = 0;
      set<T> setReturn(numSize + rhs.numSize);
       
    //Keep looping until all elements have been checked.
      while (iLhs < this->numSize || iRhs < rhs.numSize)
         {
            //End if LHS is at end
            if (iLhs == this->numSize)
               return setReturn;
            //If RHS is at end, finish adding elements in LHS.
            else if (iRhs == rhs.numSize && iLhs != this->numSize)
               setReturn.addToEnd(this->data[iLhs++]);
            //If values at current indexes are the same, do NOT add value to new array and increment both.
            else if (this->data[iLhs] == rhs.data[iRhs])
               {
                  iLhs++;
                  iRhs++;
               }
             //If value in LHS was not found in RHS, add it to the array.
            else if (this->data[iLhs] < rhs.data[iRhs])
               setReturn.addToEnd(this->data[iLhs++]);
            else
               iRhs++;
         }
      return setReturn;
   }

   /**************************************************
    * SET :: Display
    * Displays Debugging information
    *************************************************/
   template <class T>
   void set<T>::display() const
   {
     #ifdef DEBUG
     for(iterator it = begin();it < end();it++)
     {
       if(it != begin())
        cout << " ";
      cout << *it;
     }
     #endif
   }

/***** End of SET methods, start of iterators *****/


   /**************************************************
    * SET ITERATOR
    * An iterator through set
    *************************************************/
   template <class T>
   class set <T> :: iterator
   {
   public:
      // constructors, destructors, and assignment operator
      iterator()      : p(NULL)      {              }
      iterator(T * p) : p(p)         {              }
      iterator(const iterator & rhs) { *this = rhs; }
      iterator & operator = (const iterator & rhs)
      {
         this->p = rhs.p;
         return *this;
      }

      // equals, not equals operator
      bool operator != (const iterator & rhs) const { return rhs.p != this->p; }
      bool operator == (const iterator & rhs) const { return rhs.p == this->p; }

      // dereference operator
            T & operator * ()       { return *p; }
      const T & operator * () const { return *p; }

      // addition and subtration operators
      iterator operator + (int i) { return p + i;}
      iterator operator + (iterator & rhs) { return p + rhs.p;}

      iterator operator - (int i) { return p - i;}
      iterator operator - (iterator & rhs) { return p - rhs.p;}

      // greater and less than operators
      bool operator < (iterator it) { return p < it.p; }
      bool operator > (iterator it) { return p > it.p; }

      // prefix increment
      iterator & operator ++ ()
      {
         p++;
         return *this;
      }

      // postfix increment
      iterator operator ++ (int postfix)
      {
         iterator tmp(*this);
         p++;
         return tmp;
      }

      // prefix decrement
      iterator & operator -- ()
      {
         p--;
         return *this;
      }

      // postfix decrement
      iterator operator -- (int postfix)
      {
         iterator tmp(*this);
         p--;
         return tmp;
      }
      
   private:
      T * p;
   };

   template <class T>
   class set <T> :: const_iterator
   {
   public:
      // constructors, destructors, and assignment operator
      const_iterator()      : p(NULL)      {              }
      const_iterator(T * p) : p(p)         {              }
      const_iterator(const iterator & rhs) { *this = rhs; }
      const_iterator & operator = (const iterator & rhs)
      {
         this->p = rhs.p;
         return *this;
      }

      // equals, not equals operator
      bool operator != (const const_iterator & rhs) const { return rhs.p != this->p; }
      bool operator == (const const_iterator & rhs) const { return rhs.p == this->p; }

      // dereference operator
            T & operator * ()       { return *p; }
      const T & operator * () const { return *p; }

      // addition and subtration operators
      iterator operator + (int i) const { return p + i;}
      iterator operator + (iterator & rhs) const { return p + rhs.p;}

      iterator operator - (int i) const { return p - i;}
      iterator operator - (iterator & rhs) const { return p - rhs.p;}

      // greater and less than operators
      bool operator < (iterator it) const { return p < it.p; }
      bool operator > (iterator it) const { return p > it.p; }
      
      // prefix increment
      const_iterator & operator ++ ()
      {
         p++;
         return *this;
      }

      // postfix increment
      const_iterator operator ++ (int postfix)
      {
         iterator tmp(*this);
         p++;
         return tmp;
      }

      // prefix decrement
      const_iterator & operator -- ()
      {
         p--;
         return *this;
      }

      // postfix decrement
      const_iterator operator -- (int postfix)
      {
         iterator tmp(*this);
         p--;
         return tmp;
      }
      
   private:
      T * p;
   };
};

#endif
