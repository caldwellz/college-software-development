/***********************************************************************
 * Header:
 *    Map
 * Summary:
 *    This ADT takes two parameters a key and a value. The Key will need
 *    to be referenced in order to get the value. The Map is using the 
 *    BST ADT to store the data.
 * Author
 *    John Batty
 *    Jordon Thompson
 *    Brian Thompson
 *    Emmanuel Gatica
 *    Zach Caldwell
 ************************************************************************/

#ifndef MAP_H
#define MAP_H

#include "bst.h"
#include "pair.h"
using namespace custom;

template <class K, class V>
class map
{
private:
   BST<custom::pair<K, V> > bst;
   
public:
   map() {};
   
   map & operator = (const map & rhs) { bst = rhs.bst; return *this; }
   V & operator [] (K k) const;
   V & operator [] (K k);
   
   int size() const { return bst.size(); }
   bool empty() const { return bst.empty(); }
   void clear() { bst.clear(); }

   //prototype needed for iterator functions.
   class iterator;
   iterator insert (const K & k, const V & v);
   iterator insert (const custom::pair <K,V> & input);   
   iterator find(K k) {return iterator(bst.find(custom::pair<K,V>(k))); }
   iterator find(const custom::pair <K,V> & input) { return iterator(bst.find(input)); }
   iterator end() {return iterator(bst.end());}
   iterator begin() {return iterator(bst.begin());}

   /**********************************************************
   * MAP :: ITERATOR
   * Forward and reverse iterator through a MAP.
   *********************************************************/  
   class iterator
   {
      private:
         typename BST <custom::pair<K,V> >::iterator it;

      public:
         iterator() 
         { it = typename BST<custom::pair<K,V> >::iterator(NULL); }
         iterator(const typename map<K, V>::iterator &rhs)
         { it = rhs.it; }
         iterator(const typename BST<custom::pair<K,V> >::iterator & rhs)
         { it = rhs; }
         iterator & operator = (const typename BST<custom::pair<K,V> >::iterator & rhs) {this->it = rhs; return *this;}
         iterator & operator = (const typename map<K, V>::iterator & rhs) {this->it = rhs.it; return *this;}
         bool operator == (const typename map<K, V>::iterator & it) { return this->it == it.it; }
         bool operator != (const typename map<K, V>::iterator & it) { return this->it != it.it; }
         iterator operator ++ () { iterator out = *this; it++; return out; }
         iterator & operator ++ (int postfix) { it++; return *this;}
         iterator operator -- () { iterator out = *this; it--; return out; }
         iterator & operator -- (int postfix) { it--; return *this;}
         const custom::pair<K,V> & operator * () { return *it; }
   };                              
};

/*********************************************************
* MAP :: ACCESS
* Retrieves value of a given key or inserts one if it does
* not exist
*********************************************************/
template <class K, class V>
V & map<K,V>::operator [] (K k) const
{
   typename BST<custom::pair<K,V> >::iterator it = bst.find(custom::pair<K,V>(k));
   if(it != bst.end())
   {
       return (*it).second;
   }
   else
   {
      
      it = bst.insert(custom::pair<K,V>(k));
      return (*it).second;
   }
}

template <class K, class V>
V & map<K,V>::operator [] (K k)
{
   typename BST<custom::pair<K,V> >::iterator it = bst.find(custom::pair<K,V>(k));
   if(it != bst.end())
   {
      // discard const modifier
      V *p = const_cast<V*>(&((*it).second));
      return *p;
   }
   else
   {
      it = bst.insert(custom::pair<K,V>(k));
      V *p = const_cast<V*>(&((*it).second));
      return *p;
   }
}

/*********************************************************
* MAP :: INSERT(takes a key and a value)
* Inserts a new custom::pair if the key does not currently exist
*********************************************************/
template <class K, class V>
typename map<K,V>::iterator map<K,V>::insert (const K & k, const V & v)
{
   return insert(custom::pair<K,V>(k,v));                           
}

/*********************************************************
* MAP :: INSERT(takes custom::pair)
* Inserts a new custom::pair if the key does not currently exist
*********************************************************/
template <class K, class V>
typename map<K,V>::iterator map<K,V>::insert (const custom::pair<K,V> & input)
{
   typename BST<custom::pair<K,V> >::iterator it = bst.find(input);
   if(it == bst.end())
      return iterator(bst.insert(input));
   else
   {
      long p = long(&(*it).second);
      (*(V*)p) = input.second;
      return iterator(it);
   }   
}


#endif