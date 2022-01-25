/***********************************************************************
 * Module:
 *    Week 11, Sort Merge
 *    Brother Helfrich, CS 235
 * Author:
 *    John Batty
 *    Jordon Thompson
 *    Brian Thompson
 *    Emmanuel Gatica
 *    Zach Caldwell
 * Summary:
 *    This program will implement the Merge Sort
 ************************************************************************/

#ifndef SORT_MERGE_H
#define SORT_MERGE_H


/*********************************************************
* MERGE
* 
*********************************************************/
template <class T>
void merge(T destination[], T source1[], int size1, T source2[], int size2)
{
   int i1 = 0;
   int i2 = 0;

   for (int iDest = 0; iDest < size1 + size2; iDest++)
   {
      if (i1 < size1 && (i2 == size2 || source1[i1] < source2[i2]))
         destination[iDest] = source1[i1++];
      else
         destination[iDest] = source2[i2++];
   }
}

/*****************************************************
 * SORT MERGE
 * Perform the merge sort
 ****************************************************/
template <class T>
void sortMerge(T array[], int num)
{
   T * source = array;
   T * destination = new T[num];
   int numIterations;
   
   do
   {
      int iBegin1 = 0;
      int iBegin2 = 0;
      int iEnd1 = 0;
      int iEnd2 = 0;
      numIterations = 0;

      while (iBegin1 < num)
      {
         numIterations++;
         
         for (iEnd1 = iBegin1 + 1; iEnd1 <= num && !(source[iEnd1-1] > source[iEnd1]); iEnd1++);
         iBegin2 = iEnd1;
         for (iEnd2 = iBegin2 + 1; iEnd2 <= num && !(source[iEnd2-1] > source[iEnd2]); iEnd2++);
         
         if (iBegin2 < num)
            merge(destination + iBegin1, source + iBegin1, iEnd1 - iBegin1, source + iBegin2, iEnd2 - iBegin2);
            
         iBegin1 = iEnd2;
      }

      T* temp = source;
      source = destination;
      destination = temp;

   } while (numIterations > 1);

   if (array != source)
      for (int i = 0; i < num; i++)
         array[i] = source[i];
}


#endif // SORT_MERGE_H