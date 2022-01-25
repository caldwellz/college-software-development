/***********************************************************************
 * Module:
 *    Week 12, Hash
 *    Brother JonesL, CS 235
 * Author:
 *    John Batty
 *    Jordon Thompson
 *    Brian Thompson
 *    Emmanuel Gatica
 *    Zach Caldwell
 * Summary:
 *    This program will contain the pure virtual Hash class.
 ************************************************************************/

#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <iomanip>
#include <cassert>

#include "list.h"
using namespace std;

namespace custom {

/*********************************************************
* HASH
* An abstact Hash base class
*********************************************************/
template <class T>
class Hash 
{
   protected:
      list<T> * table;
      int numElements;
      int numBuckets;

   public:
      // Constructors
      Hash(int numBuckets)
      {
         this->numBuckets = numBuckets;
         this->numElements = 0;
         this->table = new list<T>[numBuckets];
      }
      Hash(const Hash <T> & rhs) :
      table(NULL), numElements(0), numBuckets(0)
      { *this = rhs; }
      ~Hash() { clear(); }

      //Member functions
      Hash <T> & operator = (const Hash <T> & rhs)
      {
         clear();         
         numElements = rhs.numElements;
         numBuckets = rhs.numBuckets;
         if (rhs.table != NULL)
         {                  
            this->table = new list<T>[numBuckets];
            for (unsigned int i = 0; i < numBuckets; ++i)
               this->table[i] = rhs.table[i];        
         } 
         return *this;
      }
      
      int size() const { return numElements; }
      int capacity() const { return numBuckets; }
      bool empty() const { return numElements == 0; }
      void clear()
      {
         delete [] table;
         table = NULL;
         numElements = 0;
         numBuckets = 0;
      }
      bool find(const T & t) const
      {
         return table[hash(t)].find(t) != table[0].end();
      }
      void insert(const T & t)
      {
         assert(hash(t) >= 0 && hash(t) < capacity());
         table[hash(t)].push_back(t);
         numElements++;
      }
      virtual int hash(const T & t) const = 0;

      // display the bucket sizes
      void display ()
      {
         int numEmpty = 0;
         int sizeLargest = 0;
         int sizeTotal = 0;
         for (int i = 0; i < capacity(); i++)
         {
            if (table[i].size() == 0)
               numEmpty++;
            else
               sizeTotal += table[i].size();
            if (table[i].size() > sizeLargest)
               sizeLargest = table[i].size();
            cout << setw(5) << i
                 << " : " << table[i].size()
                 << endl;
         }
         std::cerr << "Number of empty buckets: " << numEmpty << std::endl;
         std::cerr << "Size of the largest bucket: " << sizeLargest << std::endl;
         std::cerr << "Total number of elements: " << sizeTotal << std::endl;
      }     
};
}
#endif