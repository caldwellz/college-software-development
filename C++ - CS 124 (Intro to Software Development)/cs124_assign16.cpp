/***********************************************************************
* Program:
*    Assignment 16, If Statements
*    Brother Ridges, CS124
* Author:
*    Zachary Caldwell
* Summary: 
*    This program will determine and display the user's tax bracket based
*    on their income.
*
*    Estimated:  0.5 hrs 
*    Actual:     0.3 hrs
*      The most difficult part was probably just putting together the
*      if-else block.
************************************************************************/

#include <iostream>
using namespace std;

/****************************************************************************
 * Calculates an income tax bracket based on the given income.
 ****************************************************************************/
int computeTax(double income)
{
   if (income < 0)
      return 0;
   else if (income <= 15100)
      return 10;
   else if (income <= 61300)
      return 15;
   else if (income <= 123700)
      return 25;
   else if (income <= 188450)
      return 28;
   else if (income <= 336550)
      return 33;
   else
      return 35;
}

/**********************************************************************
 * Asks the user for a double using the given prompt string,
 *  then validates it and returns it or asks again if needed.
 ***********************************************************************/
double getDouble(string promptMessage)
{
   // Initialize variables
   bool isInputValid = false;
   double inputValue = 0.0;

   // Loop until input is valid
   while (!isInputValid)
   {
      // Get the input; cin automatically keeps the newline
      cout << promptMessage;
      cin >> inputValue;

      // Validate the input
      isInputValid = !(cin.fail());
      if (!isInputValid)
      {
         // Clear the error status and ignore the rest of the invalid line
         cin.clear();
         cin.ignore(500, '\n');
      }
   }

   return inputValue;
}

/**********************************************************************
 * Gets the income from the user and displays the tax bracket it falls in.
 ***********************************************************************/
int main()
{
   // Initialize variables
   double income;
   int taxBracket;

   // Get the income and tax bracket
   income = getDouble("Income: ");
   taxBracket = computeTax(income);

   // Display the tax bracket
   cout << "Your tax bracket is " << taxBracket << "%\n";

   return 0;
}
