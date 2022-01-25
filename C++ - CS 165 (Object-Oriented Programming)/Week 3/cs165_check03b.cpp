/***********************************************************************
* Program:
*    Checkpoint 03b, Errors
*    Brother Barney, CS165
* Author:
*    Zachary Caldwell
* Summary: 
*    Weekly Checkpoint
************************************************************************/

#include <iostream>
#include <string>
using namespace std;

/***********************************************************************
* Prompt the user for a number.
************************************************************************/
int prompt()
{
   int num;

   cout << "Enter a number: ";
   cin >> num;
   while (cin.fail())
   {
      cout << "Invalid input.\nEnter a number: ";
      cin.clear();
      cin.ignore(256, '\n');
      cin >> num;
   }

   return num;
}

/***********************************************************************
* Program entry point.
************************************************************************/
int main()
{
   int num;

   num = prompt();
   cout << "The number is " << num << ".\n";
   return 0;
}
