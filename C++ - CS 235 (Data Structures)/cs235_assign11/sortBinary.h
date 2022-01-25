/***********************************************************************
 * Module:
 *    Week 11, Sort Binary
 *    Brother Helfrich, CS 235
 * Author:
 *    John Batty
 *    Jordon Thompson
 *    Brian Thompson
 *    Emmanuel Gatica
 *    Zach Caldwell
 * Summary:
 *    This program will implement the Binary Tree Sort
 ************************************************************************/

#ifndef SORT_BINARY_H
#define SORT_BINARY_H

#include "bst.h"
#include <cassert>

/*****************************************************
 * SORT BINARY
 * Perform the binary tree sort
 ****************************************************/
template <class T>
void sortBinary(T array[], int num)
{
  // create a bst
  custom::BST<T> bst;
  // put array elements into bst
  for (int i = 0;i < num;i++){
    bst.insert(array[i]);
  }
  // copy sorted data back into array
  typename custom::BST<T>::iterator it = bst.begin();
  for (int i = 0;it != bst.end();it++,i++){
    array[i] = *it;
  }
}


#endif // SORT_BINARY_H
