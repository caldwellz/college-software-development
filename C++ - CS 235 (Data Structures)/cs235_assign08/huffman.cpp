/***********************************************************************
 * Module:
 *    Week 08, Huffman
 *    Brother Helfrich, CS 235
 * Author:
 *    John Batty
 *    Jordon Thompson
 *    Brian Thompson
 *    Emmanuel Gatica
 *    Zach Caldwell
 * Summary:
 *    This program will implement the huffman() function
 ************************************************************************/

#include <iostream>        // for CIN and COUT
#include <fstream>         // for IFSTREAM
#include <cassert>         // for ASSERT
#include <string>          // for STRING: binary representation of codes
#include "bnode.h"         // for BINARY_NODE class definition
#include "list.h"         // for list container
#include "vector.h"        // for vector to display huffman code in order
#include "huffman.h"       // for HUFFMAN() prototype

using std::cout;
using std::cin;
using std::ifstream;
using std::endl;
using std::string;
using std::bad_alloc;
using namespace custom;



/*******************************************
 * HUFFMAN
 * Driver program to exercise the huffman generation code
 *******************************************/
void huffman(const string & fileName)
{
   string                              token;
   float                               frequency;
   ifstream                            codeFile(fileName);
   list<BNode<Huffman> *>              sortedList;
   BNode<Huffman>                      *node;
   vector<BNode<Huffman> *>            displayList;

   if(!codeFile)
      throw "Unable to open File";
   // For the first pass, just create each code as it own tree and store it in the sorted tree array
   bool first = true;
   while (codeFile >> token >> frequency)
   {   
      BNode <Huffman> * tempNode = new BNode<Huffman> (Huffman(token, frequency));
      if(first)
         sortedList.push_back(tempNode);
      else
         sortInsert(tempNode,sortedList);
      displayList.push_back(tempNode);
      first = false;
   }
   codeFile.close();

   // put the data into a binary tree structured for Huffman encoding
   while (sortedList.size() > 1)
   {
      BNode<Huffman> * first = sortedList.front();
      sortedList.pop_front();
      BNode<Huffman> * second = sortedList.front();
      sortedList.pop_front();
      assert(first->data <= second->data);
      sortInsert(merge(first, second),sortedList);
   }

   //encode the Huffman objects
   encode("",sortedList.front());

   // display the data
   for(int i = 0;i < displayList.size();i++)
   {
      Huffman temp = displayList[i]->data;
      cout << temp.token << " = " << temp.code << endl;                  
   }
}

// inserts into a frequency sorted list of binary Huffman trees
void sortInsert(BNode <Huffman> * inputNode, list<BNode<Huffman>*> & sortedList)
{
   list<BNode<Huffman>*>::iterator it = sortedList.begin();
   while(it != sortedList.end() && inputNode->data >= (*it)->data)
      it++;
   sortedList.insert(it,inputNode); 
}

// merges two binary Huffman trees
BNode<Huffman> * merge (BNode<Huffman> * lowest, BNode<Huffman> * nextLowest)
{
   BNode<Huffman> * intersection = new BNode<Huffman>;

   intersection->data.frequency = lowest->data.frequency + nextLowest->data.frequency;

   intersection->pLeft = lowest;
   intersection->pRight = nextLowest;
   
   return intersection;
}

// does the actual huffman encoding
void encode (std::string code, BNode<Huffman> * pNode)
{
   if (pNode == NULL)
       return;
          
   encode(code + '0', pNode->pLeft);
   encode(code + '1', pNode->pRight);

   if (pNode->pLeft == NULL && pNode->pRight == NULL)
      pNode->data.code = code;   
}