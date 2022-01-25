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

#ifndef BNODE_H
#define BNODE_H

#include <iostream>
#include <cassert>
#include <new>
using namespace std;

/*******************************************
 * Binary BNode class
 * Purpose: The building block for a binary tree data structure. 
 ******************************************/
template <class T>
class BNode    // the basic building block of the binary tree.
{
  public:
   T data;
   BNode* pParent;   
   BNode* pRight;
   BNode* pLeft;
   
   //Default Constructor
   BNode(): pParent(NULL), pRight(NULL), pLeft(NULL) { }
   
   //Non-Default Constructor
   BNode(T t)
   {        
      data = t;
      pParent = NULL;
      pLeft = NULL;
      pRight = NULL;
   }
};

/*******************************************
 * ADD_LEFT(): Insert a new BNode at the given location in an 
 * existing linked list. Takes a BNode pointer as a parameter.
 ******************************************/
template <class T>
void addLeft(BNode <T> * & pNode, BNode <T> * pAdd)
{
   if (pAdd != NULL)
   {
      pAdd->pParent = pNode;
   }
   pNode->pLeft = pAdd;
}

/*******************************************
 * ADD_LEFT(): takes a node to the parent and
 * data for the new left node.
 ******************************************/
template <class T>
void addLeft(BNode <T> * & pNode, T data)
{
   BNode <T> * pAdd = new (std::nothrow) BNode<T>(data);   
   pAdd->pParent = pNode;
   pNode->pLeft = pAdd;         
}

/*******************************************
 * ADD_RIGHT(): Insert a new BNode at the given location in an 
 * existing linked list. Takes a BNode pointer as a parameter.
 ******************************************/
template <class T>
void addRight(BNode <T> * & pNode, BNode <T> * pAdd)
{
   if (pAdd != NULL)
   {
      pAdd->pParent = pNode;
   }      
   pNode->pRight = pAdd;
}

/*******************************************
 * ADD_RIGHT(): takes a node to the parent and
 * data for the new right node.
 ******************************************/
template <class T>
void addRight(BNode <T> * & pNode, T data)
{
   BNode <T> * pAdd = new (std::nothrow) BNode<T>(data);
   pAdd->pParent = pNode;
   pNode->pRight = pAdd;        
}

/*********************************************
 * SIZE():
 * Re
 * *******************************************/
template <class T>
int sizeBTree(BNode <T> * pNode)
{
   if (pNode == NULL)
   {
      return 0;
   }
   
   else
   {
      return sizeBTree(pNode->pLeft) + 1 + sizeBTree(pNode->pRight);
   }   
}

/*****************************************************
* DELETE BINARY TREE
* Delete all the nodes below pThis including pThis
* using postfix traverse: LRV
****************************************************/
template <class T>
void deleteBTree(BNode <T> * & pThis)
{
   if (pThis == NULL)
      return;
   deleteBTree(pThis->pLeft);
   deleteBTree(pThis->pRight);
   delete pThis;
   pThis = NULL;
}

/*****************************************************
* COPY BINARY TREE
* copyBTree(): Takes a BNode as a parameter makes a copy of the 
* tree. The return value is the newly copied tree. This is a 
* recursive function.
****************************************************/
template <class T>
BNode <T> * copyBTree(BNode <T> * source)
{
   if (source == NULL)
      return NULL;

   BNode <T> * destination = new BNode<T>(source->data);

   destination->pLeft = copyBTree(source->pLeft);
   if (destination->pLeft)
      destination->pLeft->pParent = destination;

   destination->pRight = copyBTree(source->pRight);
   if (destination->pRight)
      destination->pRight->pParent = destination;

   return destination;   
}

/*****************************************************
* Ostream Operator
* Recursive operator function sued to display the entire contents of 
* tree in LVR order.
****************************************************/
template <class T>
ostream & operator << (ostream & os, BNode<T> * pNode)
{
   if (pNode == NULL)
      return os;
   
   cout << pNode->pLeft;
   cout << pNode->data << " ";   
   cout << pNode->pRight;   

   return os;
}

#endif