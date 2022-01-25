/***********************************************************************
* Program:
*    Checkpoint 03a, Exceptions
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
   if (!(cin >> num))
   {
      throw string("Value entered was not a number.");
   }

   if (num < 0)
   {
      throw string("The number cannot be negative.");
   }

   if (num > 100)
   {
      throw string("The number cannot be greater than 100.");
   }

   if ((num % 2) != 0)
   {
      throw string("The number cannot be odd.");
   }

   return num;
}

/***********************************************************************
* Program entry point.
************************************************************************/
int main()
{
   int num;

   try
   {
      num = prompt();
   }
   catch (string message)
   {
      cout << "Error: " << message << endl;
      return 0;
   }

   cout << "The number is " << num << ".\n";
   return 0;
}
