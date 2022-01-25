/***********************************************************************
 * Header:
 *    List
 * Summary:
 *    This is a list structure like the one in the STL
 * Author
 *    John Batty
 *    Jordon Thompson
 *    Brian Thompson
 *    Emmanuel Gatica
 *    Zach Caldwell
 ************************************************************************/

#ifndef LIST_H
#define LIST_H
#include <cassert> // for ASSERT
#include <iostream> // for NULL

namespace custom
{
  template <class T>
  class list
  {
    public:
      // default constructor
      list():
      numElements(0),
      pHead(NULL),
      pTail(NULL)
      { }

      // copy constructor
      list(const list <T> & rhs):
      numElements(0),
      pHead(NULL),
      pTail(NULL)
      { *this = rhs; }

      // deconstructor
      ~list() { clear(); }

      // operator
      list <T> & operator = (const list <T> & rhs);

      // standard container interfaces
      void clear();
      bool empty() const { return size() == 0; }
      int size() const { return numElements; }

      // list-specific interfaces
      void push_front(const T & data);
      void push_back (const T & data);
      void pop_front();
      void pop_back();
      T & front();
      T & back();

      // Forward declarations
      class iterator;
      class reverse_iterator;

    private:
      // nested linked list class
      class Node;

      // member variables
      int numElements; // though we could count, it is faster to keep a variable
      Node * pHead; // pointer to the beginning of the list
      Node * pTail; // pointer to the ending of the list
  
      /*************************************************
      * NODE
      * the node class. Since we do not validate any
      * of the setters, there is no point in making them
      * private. This is the case because only the
      * List class can make validation decisions
      *************************************************/
     // template <class T>
      class Node
      {
      public:
      // default constructor: set pointers to NULL. This is the only reason
      // why Node is not a structure
      Node():
      pNext(NULL),
      pPrev(NULL),
      data()
      {}

      // non-default. Initialize data as we create the node
      Node(const T & data):
      pNext(NULL),
      pPrev(NULL),
      data(data)
      {}

      ~Node() {
        pNext = NULL;
        pPrev = NULL;
      }

      T data; // user data
      Node * pNext; // pointer to next node
      Node * pPrev; // pointer to previous node
      };

    public:      
      /*************************************************
      * LIST ITERATOR
      * Iterate through a List, non-constant version
      ************************************************/
      class iterator
      {
      public:
        // default constructor
        iterator( ):
          p(NULL)
        { }

        // non-default constructor
        iterator(Node * pt):
          p(pt)
        { }

        // costructor getting passed a const reverse_iterator
        iterator(const reverse_iterator & it):
          p(it.p)
        { }

        // copy constructor
        iterator(const iterator & rhs) { *this = rhs; }

        // operator constructor
        iterator & operator = (const iterator & rhs)
        {
        p = rhs.p;
        return *this;
        }

        // equals, not equals operator
        bool operator == (const iterator & rhs) const { return rhs.p == this->p; }
        bool operator != (const iterator & rhs) const { return rhs.p != this->p; }

        // dereference operator, fetch a node
        T & operator * ()
        {
        if (p)
          return p->data;
        else
          throw "ERROR: Trying to dereference a NULL pointer";
        }

        // postfix increment
        iterator operator ++ (int postfix)
        {
        iterator old(*this);
        if (p)
          p = p->pNext;
        return old;
        }

        // prefix increment
        iterator & operator ++ ()
        {
        if (p != NULL)
          p = p->pNext;
        return *this;
        }

        iterator operator + (int a)
        {
          iterator output = *this;
          for(int i = 0;i < a && output.p;i++)
            output++;
          return output;
        }

        // postfix decrement
        iterator operator -- (int postfix)
        {
        iterator old(*this);
        if (p)
        p = p->pPrev;
        return old;
        }

        // prefix decrement
        iterator & operator -- ()
        {
        if (p)
        p = p->pPrev;
        return *this;
        }

        iterator operator - (int a)
        {
          iterator output = *this;
          for(int i = 0;i < a && output.p;i++)
            output--;
          return output;
        }

        // two friends who need to access p directly
        friend iterator list <T>
        :: insert(iterator & it, const T & data);

        friend iterator list <T> :: erase(iterator it);

        friend class reverse_iterator;
        friend class const_iterator;

        private:
        typename list <T> :: Node * p;
      };

      /*************************************************
      * LIST REVERSE_ITERATOR
      * Iterate through a List, non-constant version
      ************************************************/
      class reverse_iterator
      {
      public:
        // default constructor
        reverse_iterator( ):
          p(NULL)
        { }

        // non-default constructor
        reverse_iterator(Node * pt):
          p(pt
          )
        { }

        // costructor getting passed a const iterator
        reverse_iterator(const iterator & it):
          p(it.p)
        { }

        // copy constructor
        reverse_iterator(const reverse_iterator & rhs) { *this = rhs; }

        // operator constructor
        reverse_iterator & operator = (const reverse_iterator & rhs)
        {
        p = rhs.p;
        return *this;
        }

        // equals, not equals operator
        bool operator == (const reverse_iterator & rhs) const { return rhs.p == this->p; }
        bool operator != (const reverse_iterator & rhs) const { return rhs.p != this->p; }

        // dereference operator, fetch a node
        T & operator * ()
        {
        if (p)
        return p->data;
        else
        throw "ERROR: Trying to dereference a NULL pointer";
        }

        // postfix increment
        reverse_iterator operator -- (int postfix)
        {
        reverse_iterator old(*this);
        if (p)
        p = p->pNext;
        return old;
        }

        // prefix increment
        reverse_iterator & operator -- ()
        {
        if (p)
          p = p->pNext;
        return *this;
        }

        reverse_iterator operator - (int a)
        {
          reverse_iterator output = *this;
          for(int i = 0;i < a && output.p;i++)
            output--;
          return output;
        }

        // postfix decrement
        reverse_iterator operator ++ (int postfix)
        {
        reverse_iterator old(*this);
        if (p)
        p = p->pPrev;
        return old;
        }

        // prefix decrement
        reverse_iterator & operator ++ ()
        {
        if (p)
        p = p->pPrev;
        return *this;
        }

        reverse_iterator operator + (int a)
        {
          reverse_iterator output = *this;
          for(int i = 0;i < a && output.p;i++)
            output++;
          return output;
        }

        friend class iterator;

        private:
          typename list <T> :: Node * p;
      };


    /*************************************************
    * LIST ITERATOR
    * Iterate through a List, non-constant version
    ************************************************/
    class const_iterator
    {
    public:
      // default constructor
      const_iterator( ):
        p(NULL)
      { }

      // non-default constructor
      const_iterator(Node * pt):
        p(pt)
      { }

      // costructor getting passed a const reverse_iterator
      const_iterator(const reverse_iterator & it):
        p(it.p)
      { }

      // copy constructor
      const_iterator(const const_iterator & rhs) { *this = rhs; }
      const_iterator(const iterator & rhs) { *this = rhs; }

      // operator constructor
      const_iterator & operator = (const iterator & rhs)
      {
      p = rhs.p;
      return *this;
      }

      // equals, not equals operator
      bool operator == (const const_iterator & rhs) const { return rhs.p == this->p; }
      bool operator != (const const_iterator & rhs) const { return rhs.p != this->p; }

      // dereference operator, fetch a node
      T operator * () const
      {
        if (p)
          return p->data;
        else
          throw "ERROR: Trying to dereference a NULL pointer";
      }

      // postfix increment
      const_iterator operator ++ (int postfix)
      {
        const_iterator old(*this);
        if (p)
          p = p->pNext;
        return old;
      }

      // prefix increment
      const_iterator & operator ++ ()
      {
        if (p)
          p = p->pNext;
        return *this;
      }

      // postfix decrement
      const_iterator operator -- (int postfix)
      {
        const_iterator old(*this);
        if (p)
          p = p->pPrev;
        return old;
      }

      // prefix decrement
      const_iterator & operator -- ()
      {
        if (p)
          p = p->pPrev;
        return *this;
      }

      private:
        typename list <T> :: Node * p;
    };

    /*************************************************
    * LIST CONST_REVERSE_ITERATOR
    * Iterate through a List, non-constant version
    ************************************************/
    class const_reverse_iterator
    {
    public:
      // default constructor
      const_reverse_iterator( ):
        p(NULL)
      { }

      // non-default constructor
      const_reverse_iterator(Node * pt):
        p(pt)
      { }

      // costructor getting passed a const iterator
      const_reverse_iterator(const iterator & it):
        p(it.p)
      { }

      // copy constructor
      const_reverse_iterator(const const_reverse_iterator & rhs) { *this = rhs; }

      // operator constructor
      const_reverse_iterator & operator = (const const_reverse_iterator & rhs)
      {
        p = rhs.p;
        return *this;
      }

      // equals, not equals operator
      bool operator == (const const_reverse_iterator & rhs) const { return rhs.p == this->p; }
      bool operator != (const const_reverse_iterator & rhs) const { return rhs.p != this->p; }

      // dereference operator, fetch a node
      T & operator * () const
      {
        if (p)
          return p->data;
        else
          throw "ERROR: Trying to dereference a NULL pointer";
      }

      // postfix increment
      const_reverse_iterator operator -- (int postfix)
      {
        const_reverse_iterator old(*this);
        if (p)
          p = p->pNext;
        return old;
      }

      // prefix increment
      const_reverse_iterator & operator -- ()
      {
        if (p)
          p = p->pNext;
        return *this;
      }

      // postfix decrement
      const_reverse_iterator operator ++ (int postfix)
      {
        const_reverse_iterator old(*this);
        if (p)
          p = p->pPrev;
        return old;
      }

      // prefix decrement
      const_reverse_iterator & operator ++ ()
      {
        if (p)
          p = p->pPrev;
        return *this;
      }

      private:
        typename list <T> :: Node * p;
    };


    // List functions that use the iterator classes above
    public:
      iterator begin() { return iterator (pHead); }
      reverse_iterator rbegin() { return reverse_iterator (pTail); }
      const_iterator cbegin() const { return const_iterator (pHead); }
      const_reverse_iterator crbegin() const
      { return const_reverse_iterator (pTail); }

      iterator end() { return iterator (NULL); }
      reverse_iterator rend() { return reverse_iterator (NULL); }
      const_iterator cend() const { return const_iterator (NULL); }
      const_reverse_iterator crend() const
      { return const_reverse_iterator (NULL); }

      iterator insert(iterator & it, const T & data);
      iterator erase(iterator it);
      iterator find(const T & t) const;
  };


   /**********************************************************************
    * LIST :: ASSIGNMENT = OPERATOR
    * Assignment Operator
    ***********************************************************************/
   template <class T>
   list <T> & list<T>::operator = (const list <T> & rhs)
   {
      // Make sure there's actually things to copy
      if (rhs.empty())
      {
         this->clear();
         return *this;
      }

      // Initialize a pHead node if needed
      if (this->pHead == NULL)
          this->pHead = new Node;
          
      Node* dest = this->pHead;
      numElements = 1;

      // Traverse and copy the list until we reach the last node
      for (Node* src = rhs.pHead; (src != rhs.pTail) && (src != NULL); src = src->pNext)
      {
         // Copy data
         dest->data = src->data;

         // Create new next node if needed, or overwrite old data if this list
         // already has nodes in it. Extra node at the end will become pTail.
         if (dest->pNext == NULL)
            dest->pNext = new Node;
         
         dest = dest->pNext;
         numElements++;
      }

      // Copy rhs.pTail too since it's an end condition of the loop above
      if (rhs.pTail != NULL)
      {
         dest->data = rhs.pTail->data;
      }
      this->pTail = dest;

      // Delete the rest of the old list if needed
      Node* old;
      for (dest = dest->pNext; dest != NULL;)
      {
         old = dest;
         dest = dest->pNext;
         delete old;
         old = NULL;
      }

      this->pTail->pNext = NULL;
      return *this;
   }


   /*******************************************
    * Insert(): Insert a new element at the given location in an
    * existing linked list, and return an iterator to it.mi
    ******************************************/
   template <class T>
   typename list<T>::iterator list<T>::insert(iterator & it, const T & data)
   {
      //Node * pCurrent = it.p;
      //

      if (empty())
      {
        assert(pHead == NULL && pTail == NULL);
        pHead = pTail = new Node(data);
        return begin();        
      }
   
      // make sure pHead and pTail are correctly set
      assert(pTail && pHead);
      assert(pHead->pPrev == NULL);
      assert(pTail->pNext == NULL);
      assert(numElements >= 0);

      try
      {
        Node * pNew = new Node(data);
        
        if (it == end())                  
        {
          pNew->pPrev = pTail;          
          pTail->pNext = pNew;
          pTail = pNew;
          it = iterator(pNew);                
        }
        else
        {
          pNew->pNext = it.p;
          pNew->pPrev = it.p->pPrev;
          it.p->pPrev = pNew;
   
          if (pNew->pPrev)
            pNew->pPrev->pNext = pNew;
          else
            pHead = pNew;

          it = iterator(pNew);
        }
        numElements++;
      }
      catch(...)
      {
        throw "ERROR: unable to allocate a new node for a list";       
      }
      return it;
   }
   
   /*******************************************************
    * LIST :: CLEAR
    * PURPOSE: Empties the list of all elements
    * ****************************************************/
   template <class T>
   void list<T>::clear()
   {
      Node * pCurrent = pHead;
   
      while (pCurrent != NULL)
      {
        Node* pTemp = pCurrent;
        pCurrent = pCurrent->pNext;
        delete pTemp;
        pTemp = NULL;
      }

      numElements = 0;
      pHead = pTail = NULL;
   }
   
   /*******************************************************
    * LIST :: PUSH_FRONT
    * PURPOSE: Adds element to the front of the list
    * ****************************************************/
   template <class T>
   void list<T>::push_front(const T & t)
   {
      Node* n = new (std::nothrow) Node(t);
      if(!n)
        throw "ERROR: unable to allocate a new node for a list";
        
      if (pHead)
      {
        n->pNext = pHead;
        pHead->pPrev = n;
      }
      
      pHead = n;
      ++numElements;

      // In case this is the first element      
      if (!pTail)
        pTail = n;  
   }

   /********************************************************
    * LIST :: PUSH_BACK
    * PURPOSE: Adds element to the back of the list
    * ****************************************************/ 
   template <class T>  
   void list<T>::push_back(const T & t)
   {
      Node* n = new (std::nothrow) Node(t);
      if(!n)
        throw "ERROR: unable to allocate a new node for a list";

      if (pTail)
      {
        n->pPrev = pTail;
        pTail->pNext = n;
      }
      pTail = n;
      ++numElements;

      // In case this is the first element      
      if (!pHead)
        pHead = n;      
   }

   /*******************************************************
    * LIST :: POP_BACK
    * PURPOSE: Removes an element from the back of the list
    * ****************************************************/
   template <class T>      
   void list<T>::pop_back()
   {
     if (pTail)
     {
       Node* pDelete = pTail;
       pTail = pTail->pPrev;
       delete pDelete;
       pTail->pNext = NULL;
       pDelete = NULL;
       --numElements;
     }
   }   

   /*******************************************************
    * LIST :: POP_FRONT
    * PURPOSE: Removes an element from the front of the List
    * ****************************************************/
   template <class T>   
   void list<T>::pop_front()
   {
     if (pHead)
     {
       Node* pDelete = pHead;
       pHead = pHead->pNext;
       delete pDelete;
       pDelete = NULL;
       --numElements;
     }
   }  

   /*******************************************************
    * LIST :: FRONT
    * PURPOSE: Get a reference to the element at the front.
    * ****************************************************/ 
   template <class T>  
   T & list<T>::front()
   {
      if(pHead)
        return pHead->data;
      else
        throw "ERROR: unable to access data from an empty list";    
   }

   /*******************************************************
    * LIST :: BACK
    * PURPOSE: Get a reference to the element at the back.
    * ****************************************************/ 
   template <class T>  
   T & list<T>::back()
   {
    if(pTail)
       return pTail->data;
    else
       throw "ERROR: unable to access data from an empty list";           
   }

   /*******************************************
   * ERASE (): Removes a single Node from a linked list. Returns a 
   * pointer to the Node preceeding the one deleted if a Node exists,
   * otherwise returns the proceeding Node.
   ******************************************/
   template <class T>
   typename list<T>::iterator list<T>::erase(list <T> :: iterator it)
   {
     Node * pDelete = it.p;

     if (pDelete != NULL)
     {
        // Handle end cases
        if (pDelete == pHead)
        {
          pHead = pHead->pNext;
          delete pDelete;
          pHead->pPrev = NULL;
          return iterator(pHead);                                
        }
        else if (pDelete == pTail)
        {
          pTail = pTail->pPrev;
          delete pDelete;
          pTail->pNext = NULL;
          return iterator(pTail);  
        }        

        // All other cases              
         Node * pTemp = NULL;
         
         if(pDelete->pNext != NULL)
           pDelete->pNext->pPrev = pDelete->pPrev;
                                   
         if(pDelete->pPrev == NULL)      
           pTemp = pDelete->pNext;  
         else
         {
           pDelete->pPrev->pNext = pDelete->pNext;                        
           pTemp = pDelete->pPrev;
         }
                           
         delete pDelete;
         pDelete = NULL;
         
         return list<T>::iterator(pTemp);
      } else {
         return list<T>::iterator(NULL);
      }                                            
   }

   /*******************************************
    * Find (): Searches a linked list for a given value. Takes two 
    * parameters, a pointer to the head of the list and the value to
    * search for. Returns a pointer to the node if found, otherwise 
    * returns NULL
    ******************************************/
   template <class T>
   typename list<T>::iterator list<T>::find(const T & t) const
   {
      for(Node * p = pHead; p; p = p->pNext)
      {
         if (p->data == t)
            return iterator(p);      
      }
      return NULL;
   }
}

#endif