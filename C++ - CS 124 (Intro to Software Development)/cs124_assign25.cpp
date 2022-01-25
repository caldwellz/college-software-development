/***********************************************************************
* Program:
*    Assignment 25, displayTable() Driver Program
*    Brother Ridges, CS124
* Author:
*    Zachary Caldwell
* Summary: 
*    Ask the user for an offset and days and display a formatted calendar.
*
*    Estimated:  0.2 hrs
*    Actual:     0.2 hrs
*      I had already finished the calendar project, so the hardest part
*      was just gutting it back down to a driver program for displayTable.
************************************************************************/

#include <cassert>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

/**********************************************************************
 * Asks the user for an int using the given prompt string,
 *  then validates it and returns it or asks again if needed.
 ***********************************************************************/
int getInt(string promptMessage)
{
   // Initialize variables
   bool isInputValid = false;
   int inputValue = 0;

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
 * Displays a calendar table with the given number of days
 ***********************************************************************/
void displayTable(int numDays, int offset)
{
   // Display weekday header
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa" << endl;

   // Adjust offset to be Sunday based rather than Monday
   assert((offset >= 0) && (offset <= 6));
   offset++;
   if (offset == 7)
      offset = 0;

   // Apply initial offset spacing
   cout << string(offset * 4, ' ');

   // Display the days
   for (int day = 1; day <= numDays; ++day)
   {
      cout << setw(4) << day;
      if ((day + offset) % 7 == 0)
         cout << endl;
      else
         if (day == numDays)
            cout << endl;
   }
}

/**********************************************************************
 * Orchestrate the main logic of the program through delegation.
 ***********************************************************************/
int main()
{
   int days = getInt("Number of days: ");
   int offset = getInt("Offset: ");

   displayTable(days, offset);

   return 0;
}
