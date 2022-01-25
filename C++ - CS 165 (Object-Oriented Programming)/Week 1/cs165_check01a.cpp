/***********************************************************************
* Program:
*    Checkpoint 01a, C++ Basics
*    Brother Barney, CS165
* Author:
*    Zach Caldwell
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   unsigned int age;
   string name;

   cout << "Hello CS 165 World!" << endl
        << "Please enter your first name: ";
   cin >> name;
   cout << "Please enter your age: ";
   cin >> age;
   cout << endl << "Hello " << name << ", you are " << age << " years old.\n";

   return 0;
}
