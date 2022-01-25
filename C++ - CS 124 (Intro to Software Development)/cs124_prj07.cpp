/***********************************************************************
* Program:
*    Project 07, Calendar
*    Brother Ridges, CS124
* Author:
*    Zachary Caldwell
* Summary: 
*    Ask the user for a month and year and display a formatted calendar.
*
*    Estimated:  3-4 hrs
*    Actual:     Unknown (4+ hrs total)
*      The hardest part was probably figuring out the displayTable algorithm.
*      I wrote it while putting together the pseudo-code though and forgot
*      to keep track of how long it took.
************************************************************************/

#include <cassert>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

const int REFERENCE_YEAR = 1753;

/****************************************************************************
 * Determines whether the given year is a leap year.
 ****************************************************************************/
bool isLeapYear(int year)
{
   if (year % 4 == 0)
   {
      if ((year % 100 == 0) && (year % 400 != 0))
         return false;
      else
         return true;
   }
   else
      return false;
}

/****************************************************************************
 * Returns the number of days in the given year.
 ****************************************************************************/
int numDaysInYear(int year)
{
   if (isLeapYear(year))
      return 366;
   else
      return 365;
}

/****************************************************************************
 * Calculates the number of days in the given month.
 ****************************************************************************/
int numDaysInMonth(int year, int month)
{
   assert((month > 0) && (month <= 12));

   int monthDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
   int numDays = monthDays[month];
   if ((month == 2) && isLeapYear(year))
      numDays++;

   return numDays;
}

/****************************************************************************
 * Computes the day-of-week offset for the given month relative to Jan. 1
 * of the reference year.
 ****************************************************************************/
int computeOffset(int month, int year)
{
   int numYear = REFERENCE_YEAR; 
   int numMonth = 1;
   int numDays = 0;

   // Sanity checks
   assert((month > 0) && (month <= 12));
   assert(year >= REFERENCE_YEAR);

   // Add days from Jan. 1, 1753 to Jan. 1 of given year
   while (numYear < year)
   {
      numDays += numDaysInYear(numYear);
      numYear++;
   }

   // Add any preceding months in the given year
   while (numMonth < month)
   {
      numDays += numDaysInMonth(year, numMonth);
      numMonth++;
   }

   int offset = numDays % 7;
   return offset;
}

/**********************************************************************
 * Gets a valid month number from the user and returns it.
 ***********************************************************************/
int getMonth()
{
   bool isInputValid = false;
   int month = 0;

   // Loop until input is valid
   while (!isInputValid)
   {
      // Get user input
      cout << "Enter a month number: ";
      cin >> month;

      // Verify that the input was a valid month
      isInputValid = !(cin.fail());
      if ((!isInputValid) || (month < 1) || (month > 12))
      {
         cout << "Month must be between 1 and 12." << endl;
 
         // Clear any error status and ignore the rest of an invalid line
         cin.clear();
         cin.ignore(500, '\n');
         isInputValid = false;
      }
   }

   return month;
}

/**********************************************************************
 * Gets a valid year number from the user and returns it.
 ***********************************************************************/
int getYear()
{
   bool isInputValid = false;
   int year = 0;

   // Loop until input is valid
   while (!isInputValid)
   {
      // Get user input
      cout << "Enter year: ";
      cin >> year;

      // Verify that cin was able to put it in the variable
      isInputValid = !(cin.fail());
      if ((!isInputValid) || (year < REFERENCE_YEAR))
      {
         cout << "Year must be " << REFERENCE_YEAR << " or later." << endl;

         // Clear any error status and ignore the rest of an invalid line
         cin.clear();
         cin.ignore(500, '\n');
         isInputValid = false;
      }
   }

   return year;
}

/**********************************************************************
 * Displays a calendar table with the given number of days
 ***********************************************************************/
void displayTable(int numDays, int offset)
{
   // Adjust offset to be Sunday based rather than Monday, assuming that
   // the reference year starts on a Monday.
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
 * Displays the month, year, and weekday header for the calendar
 ***********************************************************************/
void displayHeader(int year, int month)
{
   const char* monthNames[] = {"", "January", "February", "March", "April",
                               "May", "June", "July", "August", "September",
                               "October", "November", "December"};

   assert((month > 0) && (month <= 12));
   cout << endl << monthNames[month] << ", " << year << endl
        << "  Su  Mo  Tu  We  Th  Fr  Sa" << endl;
}

/**********************************************************************
 * Displays the calendar using displayHeader() and displayTable()
 ***********************************************************************/
void display(int year, int month, int offset)
{
   int numDays = numDaysInMonth(year, month);

   displayHeader(year, month);
   displayTable(numDays, offset);
}

/**********************************************************************
 * Orchestrate the main logic of the program through delegation.
 ***********************************************************************/
int main()
{
   int month = getMonth();
   int year = getYear();
   int offset = computeOffset(month, year);

   display(year, month, offset);

   return 0;
}
