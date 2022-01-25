/***********************************************************************
 * Module:
 *    Week 02, Stack
 *    Brother Jonesl, CS 235
 * Author:
 *    Brian Thompson
 *    Zach Caldwell
 *    John Batty
 *    Jordon Thompson
 * Summary:
 *    A program to mimic a stack from the STL
 ************************************************************************/

#ifndef STACK_H
#define STACK_H

#include <iostream>

namespace custom
{
   template <class T>
   class stack
   {
   public:
	  // constructors and destructors
	  stack() : data(NULL), cap(0), num(0) {};
	  stack(int num);
	  stack(const stack & rhs);
	  ~stack() { if (cap) delete[] data; cap = 0; num = 0; data = NULL; }
	  stack & operator = (const stack & rhs);

	  // standard container interfaces
	  int  size()    const { return num; }
	  int capacity() const { return cap; }
	  void clear() { num = 0; }
	  bool empty()   const { return num <= 0; }
	  void push(T element);
	  void pop();

	  // stack-specific interfaces
	  // what would happen if I passed -1 or something greater than num?
	  T & top()
	  {
		 if (empty())
			throw "ERROR: Unable to reference the element from an empty Stack";
		 return data[num - 1];
	  }
	  const T & top() const
	  {
		 if (empty())
			throw "ERROR: Unable to reference the element from an empty Stack";
		 return data[num - 1];
	  }

	  // a debug utility to display the stack
	  // this gets compiled to nothing if NDEBUG is defined
	  void display() const;
   private:
	  void resize(int newCap);
	  T * data;              // dynamically allocated stack of T
	  int num;
	  int cap;
   };

   /***************************************
   * STACK :: RESIZE
   * purpose: increases size up to new capacity
   ****************************************/
   template <class T>
   void stack<T>::resize(int newCap)
   {
	  if (newCap <= 0)
	  {

		 if (cap) delete[] data;
		 cap = 0;
		 num = 0;
		 data = NULL;
		 return;
	  }
	  if (newCap <= cap)
		 return;

	  T* newData;
	  try {
		 newData = new T[newCap];
	  }
	  catch (std::bad_alloc) {
		 throw "ERROR: Unable to allocate a new buffer for Stack";
	  }
	  for (int i = 0;i < num;i++)
	  {
		 newData[i] = data[i];
	  }
	  if (cap) delete[] data;
	  data = newData;
	  cap = newCap;
   }

   /***************************************
   * STACK :: STACK
   * purpose: non-default constructor taking
   *          num as a perameter for capacity
   *          and size
   ****************************************/
   template <class T>
   stack<T>::stack(int num)
   {
	  this->num = 0;
	  this->cap = 0;
	  if (num <= 0)
	  {
		 this->data = NULL;
		 return;
	  }
	  resize(num);
   }

   /***************************************
   * STACK :: STACK
   * purpose: Copy constructor
   ****************************************/
   template <class T>
   stack<T>::stack(const stack & rhs)
   {
	  // do nothing if there is nothing to do
	  num = 0;
	  cap = 0;
	  if (rhs.empty())
	  {
		 data = NULL;
		 return;
	  }

	  resize(rhs.num);
	  num = rhs.num;
	  // copy the items over one at a time using the assignment operator
	  for (int i = 0; i < num; i++)
		 data[i] = rhs.data[i];
   }

   /***************************************
   * STACK :: ASSIGNMENT OPERATOR
   * purpose: makes lhs = rhs
   ****************************************/
   template <class T>
   stack<T> & stack<T>::operator = (const stack & rhs)
   {
	  this->cap = 0;
	  this->num = 0;
	  if (rhs.cap <= 0)
	  {
		 if (cap) delete[] data;
		 data = NULL;
	  }

	  resize(rhs.num);
	  num = rhs.num;

	  for (int i = 0; i < num; i++)
		 data[i] = rhs.data[i];

	  return *this;
   }

   /***************************************
   * STACK :: PUSH
   * purpose: pushes a value onto the end of
   *          the stack.
   ****************************************/
   template <class T>
   void stack<T>::push(T element)
   {
	  //easy way out
	  if (num + 1 <= cap)
	  {
		 data[num] = element;
		 num++;
		 return;
	  }

	  if (cap <= 0)
		 resize(1);
	  else
		 resize(cap * 2);

	  data[num] = element;
	  num++;
   }

   /***************************************
   * STACK :: POP
   * purpose: removes the last value off of 
   *          the stack
   ****************************************/
   template <class T>
   void stack<T>::pop()
   {
	  if (empty())
		 return;
	  num--;
   }

   /***************************************
   * STACK :: DISPLAY
   * purpose: displays debugging information
   *          about the stack.
   ****************************************/
   template <class T>
   void stack<T>::display() const
   {
#ifndef NDEBUG
	  std::cout << "num = " << num << ": ";
	  for (int i = 0;i < num;i++)
	  {
		 if (i != 0)
			std::cout << ",";
		 std::cout << data[i];
	  }
	  std::cout << "\n";
#endif // NDEBUG
   }

};

#endif