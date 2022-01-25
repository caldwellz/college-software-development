/***********************************************************************
* Program:
*    Checkpoint 01b, Arrays
*    Brother Barney, CS165
* Author:
*    Zachary Caldwell
* Summary: 
*    Checkpoint B
************************************************************************/

#include <iostream>
using namespace std;

/***********************************************************************
* Get a list size from the user.
************************************************************************/
unsigned int getSize()
{
   unsigned int size = 0;

   // size won't change until the user enters a valid number
   while (size == 0)
   {
      cout << "Enter the size of the list: ";
      cin >> size;
   }

   return size;
}

/***********************************************************************
* Get integer list items from the user.
************************************************************************/
void getList(unsigned int count, int list[])
{
   unsigned int num = 0;

   for (int i = 0; i < (int)count; ++i)
   {
      while (num == 0)
      {
         cout << "Enter number for index " << i << ": ";
         cin >> num;
      }
      list[i] = num;
      num = 0;
   }
}

/***********************************************************************
* Display all list items that are divisible by three.
************************************************************************/
void displayMultiples(unsigned int count, int list[])
{
   cout << "The following are divisible by 3:\n";
   for (int i = 0; i < (int)count; ++i)
   {
      if (list[i] % 3 == 0)
         cout << list[i] << endl;
   }
}

/***********************************************************************
* Main entry point for the program.
************************************************************************/
int main()
{
   int *list;
   int size;

   size = getSize();
   list = new int[size];
   getList(size, list);
   cout << endl;
   displayMultiples(size, list);
   delete[] list;

   return 0;
}
