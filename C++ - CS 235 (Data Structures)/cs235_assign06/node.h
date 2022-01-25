/***********************************************************************
 * Header:
 *    Linked List
 * Summary:
 *    This is a list structure that's implemented using a sorted list.
 * Author
 *    John Batty
 *    Jordon Thompson
 *    Brian Thompson
 *    Emmanuel Gatica
 *    Zach Caldwell
 ************************************************************************/

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cassert>
using namespace std;

/*******************************************
 * Node struct
 * Purpose: this is your building block 
 ******************************************/
template <class T>
class Node    // the basic building block of the linked-list
{
  public:
   T data;
   Node* pNext;
   Node* pPrev;
   
   //Default Constructor
   Node(): pNext(NULL), pPrev(NULL) { }
   
   //Non-Default Constructor
   Node(T t)
   {        
      data = t;
      pNext = NULL;
      pPrev = NULL;
   }
};

/*******************************************
 * Insert(): Insert a new Node at the given location in an 
 * existing linked list. Returns a pointer to the newly created Node.
 ******************************************/
template <class T>
Node <T> * insert (Node <T> * & pCurrent, T data, bool after = false)
{
   Node <T> * pNew = new Node<T>(data);

   if (pCurrent != NULL && after == false)
   {
      pNew->pNext = pCurrent;
      pNew->pPrev = pCurrent->pPrev;
      pCurrent->pPrev = pNew;
      
      if (pNew->pPrev)
         pNew->pPrev->pNext = pNew;
   }
   if (pCurrent != NULL && after == true)
   {
      pNew->pNext = pCurrent->pNext;
      pNew->pPrev = pCurrent;
      pCurrent->pNext = pNew;

      if(pNew->pNext)
         pNew->pNext->pPrev = pNew;                                                                              
   }
   return pNew;
}

/***************************************************
* copy(): Copy a linked-list. Takes a pointer to a Node as 
* a parameter and returns a newly created linked-list containing
* a copy of all the nodes below the list represented by the 
* parameter. This should be a non-member function.
*****************************************************/
template <class T>
Node <T> * copy (Node <T> * pList)
{
   //Defensive Programming
   if(!pList) return NULL; 

   Node <T> * pHead = new Node<T>(pList->data);
   Node <T> * pCurrent = pHead;
   Node <T> * i = pList->pNext;

   for( ; i != NULL; i = i->pNext, pCurrent = pCurrent->pNext)
      insert(pCurrent,i->data,true);

   return pHead;
}

/*******************************************
 * Find (): Searches a linked list for a given value. Takes two 
 * parameters, a pointer to the head of the list and the value to
 * search for. Returns a pointer to the node if found, otherwise 
 * returns NULL
 ******************************************/
template <class T>
Node <T> * find (Node <T> * pHead, T value)
{
   if (pHead == NULL)
      return NULL;
            
   if(pHead->data == value)
      return pHead;

   return find(pHead->pNext,value);      
}

/*******************************************
 * Free Data (): Deletes the entire contents of a linked list and 
 * releases all allocated memory. Requires a pointer to the head of
 * the list as a parameter.
 ******************************************/
template <class T>
void freeData(Node <T> * & pHead)
{
   if(pHead)
   {
      freeData(pHead->pNext);
      delete pHead;
      pHead = NULL;
   }
}

/*******************************************
 * Remove (): Removes a single Node from a linked list. Returns a 
 * pointer to the Node preceeding the one deleted if a Node exists,
 * otherwise returns the proceeding Node.
 ******************************************/
template <class T>
Node <T> * remove (Node <T> * pDelete)
{
   if (pDelete != NULL)
   {            
      Node <T> * pTemp = NULL;
      
      if(pDelete->pNext != NULL)
         pDelete->pNext->pPrev = pDelete->pPrev;
                                 
      if (pDelete->pPrev == NULL)      
         pTemp = pDelete->pNext;  
      else
      {
         pDelete->pPrev->pNext = pDelete->pNext;                        
         pTemp = pDelete->pPrev;
      }
                        
      delete pDelete;
      return pTemp;
   } else {
      return NULL;
   }                                            
}

/*******************************************
 * << operator (): Displays the content of the list 
 ******************************************/
template <class T>
ostream & operator << (ostream & out, Node <T> * pHead)
{
   if(pHead)
   {
      out << pHead->data;
      if(pHead->pNext) 
         out << ", " << pHead->pNext; 
   }        
   return out;      
}

#endif
