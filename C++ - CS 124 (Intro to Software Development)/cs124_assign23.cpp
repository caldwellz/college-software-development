/***********************************************************************
* Program:
*    Assignment 23, Loop Syntax
*    Brother Ridges, CS124
* Author:
*    Zachary Caldwell
* Summary: 
*    This program adds all of the multiples under 100 of a user-given value.
*
*    Estimated:  0.75 hrs
*    Actual:     0.5 hrs
*      I think the trickiest part was just choosing between a while and
*      a for loop, but I finally decided a while loop looked cleaner.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Adds up all of the multiples of baseValue that are under 100.
 ***********************************************************************/
int addMultiplesUnder100(int baseValue)
{
   int currentMultiple = baseValue;
   int sum = 0;

   while (currentMultiple < 100)
   {
      sum += currentMultiple;
      currentMultiple += baseValue;
   }

   return sum;
}

// Save the boring boilerplate function for last
int getPositiveInt(string promptMessage);

/**********************************************************************
 * Orchestrates the main logic of the program.
 ***********************************************************************/
int main()
{
   int baseValue = getPositiveInt("What multiples are we adding? ");
   int sum = addMultiplesUnder100(baseValue);

   cout << "The sum of multiples of " << baseValue
        << " less than 100 are: " << sum << endl;

   return 0;
}

/**********************************************************************
 * Asks the user for a positive int using the given prompt string,
 *  then validates it and returns it or asks again if needed.
 ***********************************************************************/
int getPositiveInt(string promptMessage)
{
   bool isInputValid = false;
   int inputValue = 0;

   // Loop until input is valid
   while ((!isInputValid) || (inputValue <= 0))
   {
      // Get user input
      cout << promptMessage;
      cin >> inputValue;

      // Verify that cin was able to put it in the variable
      isInputValid = !(cin.fail());
      if (!isInputValid)
      {
         // Clear any error status and ignore the rest of an invalid line
         cin.clear();
         cin.ignore(500, '\n');
      }
   }

   return inputValue;
}
