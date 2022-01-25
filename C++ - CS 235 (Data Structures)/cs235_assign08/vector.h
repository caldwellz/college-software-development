/***********************************************************************
* Header:
* VECTOR
* Summary:
* This will contain the class definition of:
* vector : A class that represents a Vector
* vector::iterator : An interator through Vector
* vector::const_iterator : A constant iterator
* Author
* Br. Helfrich
************************************************************************/

#ifndef VECTOR_H
#define VECTOR_H

#include <cassert>

namespace custom
{

/*****************************************
* VECTOR
* Just like the std :: vector <T> class
****************************************/
template <class T>
class vector
{
public:
// constructors and destructors
vector( ) :
data(NULL), numElements(0), numCapacity(0) {}
vector(int numElements ) throw (const char *);
vector(int numElements, const T & t) throw (const char *);
vector(const vector <T> & rhs ) throw (const char *);
~vector();
vector <T> & operator = (const vector <T> & rhs) throw (const char *);

// standard container interfaces
int size() const { return numElements; }
int capacity() const { return numCapacity; }
bool empty() const { return numElements == 0; }
void clear() { numElements = 0; }

// vector-specific interfaces
void push_back(const T & t) throw (const char *);
T & operator [] (int index) throw (const char *);
T operator [] (int index) const throw (const char *);

// the various iterator interfaces
class iterator;
class const_iterator; 
iterator begin() { return iterator (data); }
iterator end() { return iterator (data + numElements);}
const_iterator cbegin() const { return const_iterator (data); }
const_iterator cend() const { return const_iterator (data + numElements);}

private:
T * data; // user data, a dynamically-allocated array
int numCapacity; // the capacity of the array
int numElements; // the number of items currently used
void resize(int newCapacity, const T & t) throw (const char *);
void resize(int newCapacity) throw (const char *);
};


/*****************************************
* NON-DEFAULT constructors
* non-default constructor: set the capacity initially
****************************************/
template <class T>
vector <T> :: vector(int numElements) throw (const char *) :
data(NULL), numElements(0), numCapacity(0)
{
if (numElements > 0)
{
resize(numElements);
this->numElements = numElements;
}
}

/*****************************************
* NON-DEFAULT constructors
* non-default constructor: set the capacity initially
****************************************/
template <class T>
vector <T> :: vector(int numElements, const T & t) throw (const char *) :
data(NULL), numElements(0), numCapacity(0)
{
if (numElements > 0)
{
resize(numElements, t);
this->numElements = numElements;
}
}

/*****************************************
* COPY CONSTRUCTOR
****************************************/
template <class T>
vector <T> :: vector (const vector <T> & rhs) throw (const char *) :
data(NULL), numElements(0), numCapacity(0)
{
if (!rhs.empty())
*this = rhs; // call the assignment operator
}

/*****************************************
* DESTRUCTOR
****************************************/
template <class T>
vector <T> :: ~vector()
{
if (numCapacity != 0)
delete [] data;
}

/*****************************************
* ARRAY - ACCESS
* Read-Write acess
****************************************/
template <class T>
T & vector <T> :: operator [] (int index) throw (const char *)
{
// sanity check
if (index < 0 || index >= numElements)
throw "ERROR: Invalid index";
return data[index]; // return-by-reference
}

/******************************************
* ARRAY - ACCESS
* READ-ONLY ACCESS
*****************************************/
template <class T>
T vector <T> :: operator [] (int index) const throw (const char *)
{
// sanity check
if (index < 0 || index >= numElements)
throw "ERROR: Invalid index";
return data[index]; // return-by-reference
}


/**************************************************
* VECTOR ITERATOR
* An iterator through vector. You only need to
* support the following:
* 1. Constructors (default and copy)
* 2. Not equals operator
* 3. Increment (prefix and postfix)
* 4. Dereference
* This particular iterator is a bi-directional meaning
* that ++ and -- both work. Not all iterators are that way.
*************************************************/
template <class T>
class vector <T> :: iterator
{
public:
// constructors, destructors, and assignment operator
iterator() : p(NULL) {}
iterator(T * p) : p(p) {}
iterator(const iterator & rhs) { *this = rhs; }
iterator & operator = (const iterator & rhs)
{
this->p = rhs.p;
return *this;
}

// equals, not equals operator
bool operator != (const iterator & rhs) const { return rhs.p != this->p; }
bool operator == (const iterator & rhs) const { return rhs.p == this->p; }

// dereference operator
T & operator * ()
{
if (p)
return *p;
else
throw "ERROR: Trying to dereference a NULL pointer";
}

// prefix increment
iterator & operator ++ ()
{
p++;
return *this;
}

// postfix increment
iterator operator ++ (int postfix)
{
iterator tmp(*this);
p++;
return tmp;
}

// prefix decrement
iterator & operator -- ()
{
p--;
return *this;
}

// postfix decrement
iterator operator -- (int postfix)
{
iterator tmp(*this);
p--;
return tmp;
}

private:
T * p;
};

/**************************************************
* VECTOR CONSTANT ITERATOR
* An iterator through vector where we cannot change
* the vector with *it
*
* The only difference between this and vectorIterator
* is that the pointer member variable is a const and
* the dereference operator returns const by-reference
*************************************************/
template <class T>
class vector <T> :: const_iterator
{
public:
// constructors, destructors, and assignment operator
const_iterator() : p(NULL) {}
const_iterator(T * p) : p(p) {}
const_iterator(const const_iterator & rhs) { this->p = rhs.p; }
const_iterator & operator = (const const_iterator & rhs)
{
this->p = rhs.p;
return *this;
}

// not equals operator
bool operator != (const const_iterator & rhs) const
{
return rhs.p != this->p;
}

// equals operator
bool operator == (const const_iterator & rhs) const
{
return rhs.p == this->p;
}

// dereference operator
const T operator * () const
{
return *p; 
}

// prefix increment
const_iterator & operator ++ ()
{
p++;
return *this;
}

// postfix increment
const_iterator operator ++ (int postfix)
{
vector <T> :: const_iterator tmp(*this);
p++;
return tmp;
}
// prefix decrement
const_iterator & operator -- ()
{
p--;
return *this;
}

// postfix decrement
const_iterator operator -- (int postfix)
{
const_iterator tmp(*this);
p--;
return tmp;
}

private:
const T * p;
};

/***************************************
* VECTOR <T> :: RESIZE
* This method will grow the current buffer
* to newCapacity. It will also copy all
* the data from the old buffer into the new
* INPUT : newCapacity the size of the new buffer
* OUTPUT :
* THROW : ERROR: Unable to allocate a new buffer for vector
**************************************/
template <class T>
void vector <T> :: resize(int newCapacity, const T & t) throw (const char *)
{
assert(newCapacity > 0 && newCapacity > numCapacity);

// allocate the new array
T * pNew;
try
{
pNew = new T[newCapacity]; // could throw bad_alloc
}
catch (std::bad_alloc)
{
throw "ERROR: Unable to allocate a new buffer for vector";
}

// copy over the data from the old array
for (int i = 0; i < numElements; i++)
pNew[i] = data[i];
for (int i = numElements; i < newCapacity; i++)
pNew[i] = t;

// delete the old and assign the new
if (NULL != data)
delete [] data;
data = pNew;
numCapacity = newCapacity;
}


/***************************************
* VECTOR <T> :: RESIZE
* This method will grow the current buffer
* to newCapacity. It will also copy all
* the data from the old buffer into the new
* INPUT : newCapacity the size of the new buffer
* OUTPUT :
* THROW : ERROR: Unable to allocate a new buffer for vector
**************************************/
template <class T>
void vector <T> :: resize(int newCapacity) throw (const char *)
{
assert(newCapacity > 0 && newCapacity > numCapacity);

// allocate the new array
T * pNew;
try
{
pNew = new T[newCapacity]; // could throw bad_alloc
}
catch (std::bad_alloc)
{
throw "ERROR: Unable to allocate a new buffer for vector";
}

// copy over the data from the old array
for (int i = 0; i < numElements; i++)
pNew[i] = data[i];

// delete the old and assign the new
if (NULL != data)
delete [] data;
data = pNew;
numCapacity = newCapacity;
}

/***************************************
* VECTOR <T> :: push_back
* This method will add the element 't' to the
* end of the current buffer. It will also grow
* the buffer as needed to accomodate the new element
* INPUT : 't' the new element to be added
* OUTPUT : *this 
* THROW : "ERROR: Unable to allocate a new buffer for vector
**************************************/
template <class T>
void vector <T> :: push_back (const T & t) throw (const char *)
{
assert(numElements <= numCapacity);

// grow if necessary
if (numCapacity == 0)
resize(1);
else if (numElements == numCapacity)
resize(numCapacity * 2); // could throw bad_alloc
assert(numElements < numCapacity);

// actually add on to the end of the list
data[numElements++] = t;
}

/***************************************
* VECTOR <T> :: assigment operator
* This operator will copy the contents of the
* rhs onto *this, growing the buffer as needed
* INPUT : rhs the vector to copy from
* OUTPUT : *this
* THROW : "ERROR: Unable to allocate a new buffer for vector
**************************************/
template <class T>
vector <T> & vector <T> :: operator = (const vector <T> & rhs)
throw (const char *)
{
if (&rhs == this)
return *this;

// blow away anything that was in this->data previously
numElements = 0;

// make sure we are big enough to handle the new data
if (rhs.numElements > numCapacity)
resize(rhs.numElements);
assert(numCapacity >= rhs.numElements);

// copy over the data from the right-hand-side
numElements = rhs.numElements;
for (int i = 0; i < rhs.numElements; i++)
data[i] = rhs.data[i];

// return self
return *this;
}

} // namespace vector

#endif // VECTOR_H