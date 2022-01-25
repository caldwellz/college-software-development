/***********************************************************************
 * Header:
 *    WholeNumber.h
 * Summary:
 *    This allows a user to store large numbers
 * Author
 *    John Batty
 *    Jordon Thompson
 *    Brian Thompson
 *    Emmanuel Gatica
 *    Zach Caldwell
 ************************************************************************/
#ifndef WHOLE_NUMBER_H
#define WHOLE_NUMBER_H

#include <string>
#include <iostream>
#include "list.h"
//1000000000

#define VAR_MAX 1000000000
using custom::list;

namespace custom{

   class WholeNumber
   {
     private:
      list<int> values;
      
      int size() { return values.size(); }
      
      void fix();
      void add(int amount,list<int>::iterator);
      void add(WholeNumber amount, int i = 0);
      void multiply(WholeNumber amount);

     public:
      
      WholeNumber() { values.push_back(0); }
      WholeNumber(long value);
      WholeNumber(const WholeNumber & value);
      WholeNumber(std::string);
      
      void operator= (WholeNumber input);
      
      void operator += (WholeNumber input) { add(input);fix(); }
      void operator *= (WholeNumber input) { multiply(input);fix(); }
      void operator -= (WholeNumber input) { add(input * -1);fix(); }
      
      friend bool operator < (WholeNumber a, WholeNumber b);
      friend bool operator > (WholeNumber a, WholeNumber b) 
      { return b < a; }
      friend bool operator == (WholeNumber a, WholeNumber b);
      friend bool operator <= (WholeNumber a, WholeNumber b);
      friend bool operator >= (WholeNumber a, WholeNumber b);
      
      WholeNumber operator ++(){
         *this += 1;
         return *this;
      }
      friend WholeNumber operator ++(WholeNumber input);
      
      friend WholeNumber operator+ (WholeNumber a, WholeNumber b)
      { a += b; return a; }
      friend WholeNumber operator* (WholeNumber a, WholeNumber b)
      { a *= b; return a; }
      friend WholeNumber operator- (WholeNumber a, WholeNumber b)
      { a-= b; return a; }
      friend WholeNumber operator- (WholeNumber a)
      { return a * -1; }
      
      friend WholeNumber abs(WholeNumber value){
         return value < 0 ? -value : value;
      }
      
      friend std::ostream & operator << (std::ostream & out, WholeNumber t);
      
   };
};
#endif
