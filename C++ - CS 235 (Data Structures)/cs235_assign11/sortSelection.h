/***********************************************************************
 * Module:
 *    Week 11, Sort Select
 *    Brother Helfrich, CS 235
 * Author:
 *    John Batty
 *    Jordon Thompson
 *    Brian Thompson
 *    Emmanuel Gatica
 *    Zach Caldwell
 * Summary:
 *    This program will implement the Selection Sort
 ************************************************************************/

#ifndef SORT_SELECTION_H
#define SORT_SELECTION_H

/*****************************************************
 * SORT SELECTION
 * Perform the selection sort
 ****************************************************/
template <class T>
void sortSelection(T array[], int num)
{
   // pivot loop
   for (int iPivot = num -1; iPivot >= 1; iPivot--)
   {
      int iLargest = 0;
      // inner loop
      for (int iCheck = 1; iCheck < iPivot; iCheck++)
      {
         if (array[iLargest] < array[iCheck])
            iLargest = iCheck;
      }
      if (array[iLargest] > array[iPivot])
      {
         T temp = array[iPivot];
         array[iPivot] = array[iLargest];
         array[iLargest] = temp;
      }
   }
}


#endif // SORT_SELECTION_H
