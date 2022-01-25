/***********************************************************************
 * Module:
 *    Week 11, Sort Insertion
 *    Brother Helfrich, CS 235
 * Author:
 *    John Batty
 *    Jordon Thompson
 *    Brian Thompson
 *    Emmanuel Gatica
 *    Zach Caldwell
 * Summary:
 *    This program will implement the Insertion Sort
 ************************************************************************/

#ifndef SORT_INSERTION_Hrun
#define SORT_INSERTION_H

#include <cassert>

/*********************************************************
* BINARY SEARCH
* a recursive function that finds the location to insert 
*********************************************************/
template <class T>
int bianarySearch(T array[], T search, int iBegin, int iEnd)
{
   int iMiddle = (iBegin + iEnd) / 2;
   if (iBegin > iEnd)
      return iBegin;
   if (array[iMiddle] == search)
      return iMiddle;
   if (search > array[iMiddle])
      return bianarySearch(array, search, iMiddle + 1, iEnd);
   else
      return bianarySearch(array, search, iBegin, iMiddle - 1);      
}

/*****************************************************
 * SORT INSERTION
 * Perform the insertion sort
 ****************************************************/
template <class T>
void sortInsertion(T array[], int num)
{
   // Pivot loop
   for (int iPivot = num -2; iPivot >= 0; iPivot--)
   {
      T valuePivot = array[iPivot];
      int iInsert = bianarySearch(array, valuePivot, iPivot + 1, num - 1);
      iInsert--;
      
      //inner loop
      int iShift = iPivot;
      for (; iShift < iInsert; iShift++)
         array[iShift] = array[iShift + 1];
      array[iShift] = valuePivot;
   }
}



#endif // SORT_INSERTION_H
