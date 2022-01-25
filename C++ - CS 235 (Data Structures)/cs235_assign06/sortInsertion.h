/***********************************************************************
 * Header:
 *    INSERTION SORT
 * Summary:
 *    This will contain just the prototype for insertionSortTest(). You may
 *    want to put other class definitions here as well.
 * Author
 *    John Batty
 *    Jordon Thompson
 *    Brian Thompson
 *    Emmanuel Gatica
 *    Zach Caldwell
 ************************************************************************/

#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "node.h"

/***********************************************
 * INSERTION SORT
 * Sort the items in the array
 **********************************************/
template <class T>
void sortInsertion(T array[], int num)
{
   
   if(array == NULL)
      return;

   Node <T> * pCurrent = new Node<T>(array[0]);

   for(int i = 1; i < num; ++i)
   {
      while(pCurrent->pPrev != NULL)
      {
         pCurrent = pCurrent->pPrev;
      }
      while(array[i] > pCurrent->data && pCurrent->pNext != NULL)
      {
         pCurrent = pCurrent->pNext;
      }
   
      if(pCurrent->pNext == NULL)  //if you have reached the end of the list
      {
         if(pCurrent->data < array[i]) //compare where we are at the list to array[i]
         {
            insert(pCurrent, array[i], true  /* insert after */);
         }
         else 
         {
            insert(pCurrent, array[i], false  /* insert before */);
         } 
      }
      else
      {
         insert(pCurrent, array[i], false);
      }
  
   }
   while(pCurrent->pPrev != NULL)
   {
      pCurrent = pCurrent->pPrev;
   }

   int i = 0;
   while(pCurrent != NULL)
   {
      array[i] = pCurrent->data;
      pCurrent = pCurrent->pNext;
      i++;
   }
   
}
#endif // INSERTION_SORT_H

