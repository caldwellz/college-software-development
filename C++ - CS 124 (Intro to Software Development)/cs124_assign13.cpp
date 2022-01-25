/***********************************************************************
* Program:
*    Assignment 13, Expressions
*    Brother Ridges, CS124
* Author:
*    Zachary Caldwell
* Summary: 
*    Demonstrates how to convert a user-given Fahrenheit value to Celsius.
*
*    Estimated:  0.5 hrs
*    Actual:     0.25 hrs
*      The integer division did indeed throw me off at first, like the
*      textbook said it might, so that was probably the hardest part.
************************************************************************/

#include <iomanip>
#include <iostream>
using namespace std;

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
 * Gets a Fahrenheit value from the user, then converts and displays it
 * in Celsius.
 ***********************************************************************/
int main()
{
   // Get the Fahrenheit value and convert it
   double fahrenheit = getDouble("Please enter Fahrenheit degrees: ");
   double celsius = (5.0 / 9.0) * (fahrenheit - 32);

   // Set cout options and display the converted value 
   cout.setf(ios::fixed);
   cout.precision(0);
   cout << "Celsius: " << celsius << endl;

   return 0;
}
