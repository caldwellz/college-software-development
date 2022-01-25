/***********************************************************************
* Program:
*    Assignment 12, Input & Variables
*    Brother Ridges, CS124
* Author:
*    Zachary Caldwell
* Summary: 
*    Demonstrates how to get input, store it, and print it back out.
*
*    Estimated:  0.5 hrs
*    Actual:     0.5 hrs
*      The hardest part was naturally the input validation, but I went
*      that route because it's code that I'm sure I will reuse at some point.
************************************************************************/

#include <iomanip>
#include <iostream>
using namespace std;

/**********************************************************************
 * Asks the user for their monthly income, validates it, then pretty-prints it
 ***********************************************************************/
int main()
{
   // Initialize variables
   float monthlyIncome = 0.0;
   bool isInputInvalid = true;

   // Get/validate input
   while (isInputInvalid)
   {
      cout << "\tYour monthly income: ";
      cin >> monthlyIncome;
      isInputInvalid = cin.fail();
      cin.clear();
      cin.ignore(80, '\n');
   }

   // Set cout options and print the income
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   cout << "Your income is: $" << setw(9) << monthlyIncome << endl;

   return 0;
}
