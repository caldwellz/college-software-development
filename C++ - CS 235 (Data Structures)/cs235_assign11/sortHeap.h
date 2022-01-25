/***********************************************************************
 * Module:
 *    Week 11, Sort Heap
 *    Brother Helfrich, CS 235
 * Author:
 *    John Batty
 *    Jordon Thompson
 *    Brian Thompson
 *    Emmanuel Gatica
 *    Zach Caldwell
 * Summary:
 *    This program will implement the Heap Sort
 ************************************************************************/

#ifndef SORT_HEAP_H
#define SORT_HEAP_H

template <class T>
class Heap
{
private:
   T * array;
   int num;

   void swap(int i1, int i2)
   {
      T temp = array[i1];
      array[i1] = array[i2];
      array[i2] = temp;
   }

   void percolateDown(int index)
   {
      // black magic to account for 0 based index in math
      int indexLeft = ((index + 1) * 2) - 1;
      int indexRight = indexLeft + 1;

      if(indexRight < num && 
         array[indexRight] > array[indexLeft] &&
         array[indexRight] > array[index])
      {
         swap(index,indexRight);
         percolateDown(indexRight);
      }
      else if(indexLeft < num && array[indexLeft] > array[index])
      {
         swap(index,indexLeft);
         percolateDown(indexLeft);
      }
      
   }
public:
   Heap(T array[],int num):array(array),num(num) 
   {
      for (int index = num/2; index >= 0; index--)
         percolateDown(index);
   }
   T getMax() { return array[num - 1]; }
   void deleteMax() { num--; }
   void sort();
};

/*****************************************************
 * SORT
 * Perform the heap sort
 ****************************************************/
template <class T>
void Heap<T>::sort()
{
   while (num > 0)
   {
      swap(0, --num);
      percolateDown(0);
   }
}

/*********************************************************
* SORT HEAP
* Begins the heap sort
*********************************************************/
template <class T>
void sortHeap(T array[], int num)
{
   Heap<T> h(array, num);
   h.sort();
}

#endif // SORT_HEAP_H
