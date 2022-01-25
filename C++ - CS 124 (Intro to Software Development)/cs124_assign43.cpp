/***********************************************************************
* Program:
*    Assignment 43, Command Line
*    Brother Ridges, CS124
* Author:
*    Zachary Caldwell
* Summary: 
*    This program will convert the command-line feet parameters to meters.
*
*    Estimated:  30 min
*    Actual:     27 min
*      The trickiest part was starting out with a function and then realizing
*      that it would actually be simpler to just put everything in main
************************************************************************/

#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

const double METER_RATIO = 0.3048;

/**********************************************************************
 * Convert feet passed as command-line parameters to meters and display them.
 **********************************************************************/
int main(int argc, char ** argv)
{
   // Set cout options
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(1);

   // Start at 1 to skip the program name argument
   for (int i = 1; i < argc; ++i)
   {
      // According to the Internet strtod is supposedly more robust than atof
      double feet;
      feet = strtod(argv[i], NULL);
      double meters = feet * METER_RATIO;
      cout << feet << " feet is " << meters << " meters\n";
   }

   return 0;
}
