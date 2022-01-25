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

#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <string>
#include "bnode.h"         // for BINARY_NODE class definition
#include "list.h"         // for list container
#include "vector.h"        // for vector to display huffman code in order

using namespace custom;

struct Huffman {

   std::string token;
   float frequency;
   std::string code;
   
   Huffman() { 
      frequency = 0;
      token = '\0';
      code = '\0';
   }

   Huffman(string token, float frequency) {

      this->token = token;
      this->frequency = frequency;   
   }

   bool operator >  (const Huffman & rhs) const { return frequency >  rhs.frequency; }
   bool operator >= (const Huffman & rhs) const { return frequency >= rhs.frequency; }
   bool operator <  (const Huffman & rhs) const { return frequency <  rhs.frequency; }
   bool operator <= (const Huffman & rhs) const { return frequency <= rhs.frequency; }
   bool operator == (const Huffman & rhs) const { return frequency == rhs.frequency; }
   bool operator != (const Huffman & rhs) const { return frequency != rhs.frequency; }
};

void huffman(const std::string & fileName);
void encode (std::string code, BNode<Huffman> * pNode);
void sortInsert(BNode <Huffman> * node, custom::list<BNode<Huffman>*> & sortedList);
BNode<Huffman> * merge (BNode<Huffman> * lowest, BNode<Huffman> * nextLowest);

#endif // HUFFMAN_h