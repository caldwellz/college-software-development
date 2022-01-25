/***********************************************************************
 * Header:
 *    Binary Search Tree
 * Summary:
 *    This is a sorted bianary tree structure that's implemented
 *    using a red-black tree.
 * Author
 *    John Batty
 *    Jordon Thompson
 *    Brian Thompson
 *    Emmanuel Gatica
 *    Zach Caldwell
 ************************************************************************/

#ifndef BST_H
#define BST_H
#include <cassert>   // for ASSERT
#include <iostream>  // for COUT
#include <stdexcept> // exceptions
using namespace std;

namespace custom
{
  /*****************************************************************
   * CLASS :: BST
   * The official Binary Search Tree class
   *****************************************************************/
  template <class T>
  class BST {
    public:
      // default constructor
      BST(): 
      pRoot(NULL),
      numElements(0)
      { }

      // copy constructor
      BST(const BST <T> & rhs):
        pRoot(NULL)
      { *this = rhs; }

      // destructor
      ~BST() { deleteBinaryTree(pRoot); }

      // assignment operator
      BST<T> & operator = (const BST <T> & rhs);

      // Iterator declarations
      class iterator;
      iterator begin();
      iterator end() { return iterator(NULL); }
      iterator rbegin();
      iterator rend() { return iterator(NULL); }

      // standard container interfaces
      void clear() { 
         deleteBinaryTree(pRoot);
         numElements = 0;
         pRoot = NULL;
       }
      bool empty() const { return (pRoot == 0); } // is the tree empty?
      int size() const { return numElements; } // how big is tree?
      iterator find(const T & t) const;
      iterator insert(const T & item);
      void erase(iterator & it);
      class BNode;
      
      void balance(BNode * nNode);

      BNode * getRoot() { return pRoot; }

    private:
      // nested linked list class
      void deleteNode(BNode node, bool isRight);
      void deleteBinaryTree(BNode * node);
      BNode * copyBTree (BNode * source);

      // member variables
      int numElements; // though we could count, it is faster to keep a variable
      BNode * pRoot; // pointer to the beginning of the tree

  public:      
      /*************************************************
      * BNODE
      * the node class. Since we do not validate any
      * of the setters, there is no point in making them
      * private. This is the case because only the
      * List class can make validation decisions
      *************************************************/
      //template <class T>
      class BNode
      {
         public:
         // default constructor: set pointers to NULL
         BNode():
         pLeft(NULL),
         pRight(NULL),
         pParent(NULL),
         data(),
         isRed(true)
         {}

         // non-default. Initialize data as we create the node
         BNode(const T & data):
         pLeft(NULL),
         pRight(NULL),
         pParent(NULL),
         data(data),
         isRed(true)
         {}

         ~BNode() {
         pParent = NULL;
         pLeft = NULL;
         pRight = NULL;
         }

         T data;
         BNode * pLeft;
         BNode * pRight;
         BNode * pParent;

         // Red-Black Tree vars
         bool isRed;
         bool isBlack() {return !isRed;}
         void setRed() {isRed = true;}
         void setBlack() {isRed = false;}
      };
      
    /**********************************************************
    * BINARY SEARCH TREE ITERATOR
    * Forward and reverse iterator through a BST
    *********************************************************/    
    class iterator
    {
      
    public:
      // constructors and assignment
      iterator(BNode * p = NULL) {
         pNode = p;
//         if (pNode == NULL)
//            cout << "[WARNING] BST::iterator: Creating a NULL iterator (possibly end())" << endl;
      }
      iterator(const iterator & rhs) { pNode = rhs.pNode; }
      iterator & operator = (const iterator & rhs)
      {
        pNode = rhs.pNode;
        return *this;
      }

      // compare
      bool operator == (const iterator & rhs) const
      {
        // only need to compare the leaf node 
        return rhs.pNode == pNode;
      }
      bool operator != (const iterator & rhs) const
      {
        // only need to compare the leaf node 
        return rhs.pNode != pNode;
      }

      // de-reference. Cannot change because it will invalidate the BST
      const T & operator * () const 
      {
        if (pNode == NULL)
           throw logic_error("BST::iterator::operator*: Attempted to dereference a NULL iterator");
        return pNode->data;
      }

      // iterators
      iterator & operator ++ ()
      {
         if (pNode != NULL)
         {
            //1. There's a right child
            if(pNode->pRight)
            {
               // follow right
               pNode = pNode->pRight; 

               // find leftmost child
               // TO DO: Current segfault here is probably from new erase() case 3 experiment forgetting to set a NULL / update a pointer somewhere
               while(pNode->pLeft)
                  pNode = pNode->pLeft;
            }

            //2. No right child and we are our parent's left
            else if(pNode->pParent->pLeft == pNode)
            {
               pNode = pNode->pParent;
            }

            //3. No left child and we are our parent's right
            else if(pNode->pParent->pRight == pNode)
            {
               // loop until we are no longer on the parent's right
               // or we run out of parents
               while(pNode->pParent && pNode->pParent->pRight == pNode)
                  pNode = pNode->pParent;

               pNode = pNode->pParent;
            }
         } else {
            cout << "[WARNING] BST::iterator++: Attempting to increment a NULL iterator" << endl;
         }
         return *this;
      }

      iterator operator ++ (int postfix)
      {
        iterator itReturn = *this;
        ++(*this);
        return itReturn;
      }

      iterator & operator -- ()
      {
        //same logic as the ++ operator, but backwards.
        if(pNode->pLeft)
        {
          pNode = pNode->pLeft;
          while(pNode->pRight)
            pNode = pNode->pRight;
        }
        else if(pNode->pParent->pRight == pNode)
        {
          pNode = pNode->pParent;
        }
        else if(pNode->pParent->pLeft == pNode)
        {
          while(pNode->pParent && pNode->pParent->pLeft == pNode)
            pNode = pNode->pParent;
          pNode = pNode->pParent;
        }
        return *this;
      }

      iterator operator -- (int postfix)
      {
        iterator itReturn = *this;
        --(*this);
        return itReturn;
      }

      // must give friend status to remove so it can call getNode() from it
      friend void BST<T>::erase(iterator & it);

      private:

      // get the node pointer
      BNode * getNode() { return pNode; }

      // the stack of nodes
      BNode * pNode;
      };
  };
  
  /*********************************************************
   * BST :: BEGIN
   * Returns an iterator at leftmost/smallest item in the tree
   *********************************************************/
  template <class T>
  typename BST<T>::iterator BST<T>::begin()
  {
    BNode * pOut = pRoot;
    if(!pRoot)
      return iterator(NULL);
    while(pOut->pLeft)
      pOut = pOut->pLeft;
    return iterator(pOut);
  }

  /*********************************************************
   * BST :: RBEGIN
   * Returns an iterator at rightmost/largest item in the tree
   *********************************************************/
  template <class T>
  typename BST<T>::iterator BST<T>::rbegin()
  {
    BNode * pOut = pRoot;
    if(!pRoot)
      return iterator(NULL);
    while(pOut->pRight)
      pOut = pOut->pRight;
    return iterator(pOut);
  }

  /*********************************************************
   * BST :: ASSIGNMENT OPERATOR
   * 
   *********************************************************/
    template <class T>
    BST<T> & BST<T>::operator = (const BST <T> & rhs)
    {      
      if (this->pRoot)
        deleteBinaryTree(pRoot);
      
      this->pRoot = copyBTree(rhs.pRoot); 
      this->numElements = rhs.numElements;    

      return *this;       
    }

   /*********************************************************
   * BST :: INSERT
   * Inserts an item into a sorted location in the tree
   *********************************************************/
   template <class T>
   typename BST<T> :: iterator BST <T> :: insert(const T & item)
   {
     // There are two parts to this function the first part which is the while loop
     // helps us get our pointers to where we want to insert.
     // The second part actually inserts them.
     
     try {
         BNode * tempLeaf = pRoot;  // creating a pointer that we will use to insert
 
         // we need to keep track of parent so that later we can insert the newLeaf
         BNode * parent = NULL;    
     
         // as long as there is something in the tree we want to run this code
         while (tempLeaf != NULL) 
         {
            parent = tempLeaf; 
            if (item < tempLeaf->data)
            tempLeaf = tempLeaf->pLeft;
            else
            tempLeaf = tempLeaf->pRight;
         }
 
         BNode * newLeaf = new BNode(item);
         if (parent == NULL) {
            pRoot = newLeaf;
            numElements++;
         }
         else if (item < parent->data) {
            parent->pLeft = newLeaf;
            newLeaf->pParent = parent;
            numElements++;
         } else {
            parent->pRight = newLeaf;
            newLeaf->pParent = parent;
            numElements++;
         }
         balance(newLeaf);
         return iterator(newLeaf);
     } catch (...) {
         return iterator(NULL);
         throw "ERROR: Unable to allocate a node";
     }
   }
  
   /*********************************************************
   * BST :: ERASE
   * Takes an iterator to a BNode in the tree and erases it.
   *********************************************************/
   template <class T>
   void BST<T>::erase(iterator & it)
   {
      if (it.pNode == NULL)
         return;
      // Case 1: No Children
      if (it.pNode->pRight == NULL && it.pNode->pLeft == NULL)
      {
         if (it.pNode->pParent != NULL && it.pNode->pParent->pRight == it.pNode)
            it.pNode->pParent->pRight = NULL;
         if (it.pNode->pParent != NULL && it.pNode->pParent->pLeft == it.pNode)
            it.pNode->pParent->pLeft = NULL;
         delete it.pNode;
         numElements--;
         return;
      }

      // Case 2: One Child
      if (it.pNode->pRight == NULL && it.pNode->pLeft != NULL)
      {
         it.pNode->pLeft->pParent = it.pNode->pParent;
         if (it.pNode->pParent != NULL && it.pNode->pParent->pRight == it.pNode)
            it.pNode->pParent->pRight = it.pNode->pLeft;
         if (it.pNode->pParent != NULL && it.pNode->pParent->pLeft == it.pNode)
            it.pNode->pParent->pLeft = it.pNode->pLeft;
         delete it.pNode;
         numElements--;
         return;
      }
      if (it.pNode->pLeft == NULL && it.pNode->pRight != NULL)
      {
         it.pNode->pRight->pParent = it.pNode->pParent;
         if (it.pNode->pParent != NULL && it.pNode->pParent->pRight == it.pNode)
            it.pNode->pParent->pRight = it.pNode->pRight;
         if (it.pNode->pParent != NULL && it.pNode->pParent->pLeft == it.pNode)
            it.pNode->pParent->pLeft = it.pNode->pRight;
         delete it.pNode;
         numElements--;
         return;
      }

      // Case 3: Two Children This will replace the deleted node with
      //         the in-order successor
      if (it.pNode->pLeft != NULL && it.pNode->pRight != NULL)
      {
         iterator itSuccessor = it;
         ++itSuccessor;
         BNode *pErase = it.pNode;
         BNode *pSuccessor = itSuccessor.pNode;

         // If there's no successor, we're at the last node and there's no need to move anything
         if (pSuccessor)
         {
            // Move the successor's right child into the successor's place if needed
            assert(pSuccessor->pParent);
            if(pSuccessor->pParent->pLeft == pSuccessor)
            {
               pSuccessor->pParent->pLeft = pSuccessor->pRight;
               if(pSuccessor->pRight)
                  pSuccessor->pRight->pParent = pSuccessor->pParent;
               pSuccessor->pRight = pErase->pRight;

            }
            else
            {
               pSuccessor->pParent->pRight = pSuccessor->pRight;
            }
            if (pSuccessor->pRight)
            {
               pSuccessor->pRight->pParent = pSuccessor->pParent;
            }

            // Move the successor into pErase's place
            pSuccessor->pLeft = pErase->pLeft;
            pSuccessor->pParent = pErase->pParent;
         }

         // We absolutely need to update pErase's parent
         if (pErase->pParent != NULL)
         {
            if (pErase->pParent->pLeft == pErase)
            {
               pErase->pParent->pLeft = pSuccessor;
            } else if (pErase->pParent->pRight == pErase)
            {
               pErase->pParent->pRight = pSuccessor;
            } else
               throw logic_error("BST::erase: pErase is not a child of its parent");
         }

         // We need to take care of pErase's children
         if (pErase->pRight)
            pErase->pRight->pParent = pSuccessor;
         if (pErase->pLeft)
            pErase->pLeft->pParent = pSuccessor;

         // Update pRoot too if needed
         if (pErase == pRoot)
            pRoot = pSuccessor;

         delete pErase;
         pErase = NULL;
         numElements--;
         return;
      }
   }

   /*********************************************************
   * BST :: FIND
   * Searches for a passed in value and returns an iterator to
   * it in the tree if it exists; else returns end()
   *********************************************************/
   template <class T>
   typename BST<T>::iterator BST<T>::find(const T & t) const
   {
      BNode *pCurrent = pRoot;
      while (true)
      {
         if (pCurrent == NULL)
            return BST<T>::iterator(NULL);
         if (t == pCurrent->data)
            return BST<T>::iterator(pCurrent);
         if (t < pCurrent->data)
            pCurrent = pCurrent->pLeft;
         else if (t > pCurrent->data)
            pCurrent = pCurrent->pRight;                                                
      }      
   }

   /*********************************************************
   * BST :: DELETE BINARY TREE
   * Deletes a Binary Node and all connected children.
   *********************************************************/
   template <class T>
   void BST<T>::deleteBinaryTree(BNode *node)
   {
      if (node == NULL)
         return;

      deleteBinaryTree(node->pLeft);
      deleteBinaryTree(node->pRight);
      delete node;            
   }

   /*********************************************************
   * BST :: COPY BINARY TREE
   * Copies an entire Binary Tree from a source BNode to 
   * a Destination BNode.
   *********************************************************/
   template <class T>
   typename BST<T>::BNode * BST<T>::copyBTree (BNode * source)
   {
      if (source == NULL)
         return NULL;

      BNode * destination = new BNode(source->data);

      destination->pLeft = copyBTree(source->pLeft);
      if (destination->pLeft)
         destination->pLeft->pParent = destination;

      destination->pRight = copyBTree(source->pRight);
      if (destination->pRight)
         destination->pRight->pParent = destination;

      return destination;                      
   }
   /*********************************************************
   * BST :: BALANCE
   * Balanced the tree to comply with Red-Black tree rules
   *********************************************************/
   template<class T>
   void BST<T>::balance(BNode * nNode)
   {
      BNode * granny = NULL;
      BNode * aunt = NULL;
      BNode * sibling = NULL;
      BNode * parent = nNode->pParent;
      if(parent)
      {
         if(parent->pLeft == nNode)
            sibling = parent->pRight;
         else
            sibling = parent->pLeft;
         if(parent->pParent)
         {
            granny = parent->pParent;
            if(granny->pLeft == parent)
               aunt = granny->pRight;
            else
               aunt = granny->pLeft;
         }
      }

      //Case 1: No parent, this is the root node
      if(!parent) 
      {
         nNode->setBlack();
         return;
      }      
      //Case 2: new Node's parent should be black
      if(parent->isBlack())
         return;
      //Case 3: Parent and aunt are red
      else if(granny->isBlack())
      {
         if(aunt && aunt->isRed)
         {
            parent->setBlack();
            aunt->setBlack();
            if(granny->pParent && granny->pParent->isBlack())
               granny->setRed();
            else
               granny->setBlack();
         }
      }
      //Case 4: Parent is red, aunt is black or non existant   
      if(parent->isRed)
      {
         if(!aunt || aunt->isBlack())
         {
            if(granny)
            {
               BNode * gGranny = granny->pParent;
               BNode * nextNode = NULL;
               //a: Parent right granny right
               if(parent->pLeft == nNode && granny->pLeft == parent)
               {
                  parent->pParent = granny->pParent;
                  granny->pParent = parent;
                  granny->pLeft = parent->pRight;
                  parent->pRight = granny;
                  parent->setBlack();
                  granny->setRed();
                  nextNode = parent;
               }
               //b: Parent left granny left
               if(parent->pRight == nNode && granny->pRight == parent)
               {
                  parent->pParent = granny->pParent;
                  granny->pParent = parent;
                  granny->pRight = parent->pLeft;
                  parent->pLeft = granny;
                  parent->setBlack();
                  granny->setRed();
                  nextNode = parent;
               }
               //c: Parent left granny right
               if(parent->pRight == nNode && granny->pLeft == parent)
               {
                  nNode->pParent = granny->pParent;
                  granny->pParent = nNode;
                  parent->pParent = nNode;
                  granny->pLeft = nNode->pRight;
                  parent->pRight = nNode->pLeft;
                  nNode->pRight = granny;
                  nNode->pLeft = parent;
                  nNode->setBlack();
                  granny->setRed();
                  nextNode = nNode;
               }
               //d: Parent right granny left
               if(parent->pLeft == nNode && granny->pRight == parent)
               {
                  nNode->pParent = granny->pParent;
                  granny->pParent = nNode;
                  parent->pParent = nNode;
                  granny->pRight = nNode->pLeft;
                  parent->pLeft = nNode->pRight;
                  nNode->pLeft = granny;
                  nNode->pRight = parent;
                  nNode->setBlack();
                  granny->setRed();
                  nextNode = nNode;
               }

               // Fix children's parents
               if(gGranny)
               {
                  if(gGranny->pLeft == granny)
                     gGranny->pLeft = nextNode;
                  else
                     gGranny->pRight = nextNode;
               }
            }
         }
      }
      
      // Fix pRoot
      while(pRoot->pParent)
        pRoot = pRoot->pParent;                                 
   }   
}

#endif  // BST_H