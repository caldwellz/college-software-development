/***********************************************************************
* Program:
*    Checkpoint 10a, Vectors
*    Brother Barney, CS165
* Author:
*    Zach Caldwell
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   vector<int>    ints;
   vector<string> strings;
   int num = -1;
   string text;

   // Get ints
   while (true) {
      cout << "Enter int: ";
      cin >> num;
      if (num == 0)
         break;
      ints.push_back(num);
   }

   // Display ints
   cout << "Your list is:\n";
   for (vector<int>::iterator it = ints.begin(); it != ints.end(); ++it) {
      cout << (*it) << endl;
   }
   cout << endl;

   // Get strings
   while (true) {
      cout << "Enter string: ";
      cin >> text;
      if (text == "quit")
         break;
      strings.push_back(text);
   }

   // Display strings
   cout << "Your list is:\n";
   for (vector<string>::iterator it = strings.begin(); it != strings.end(); ++it) {
      cout << (*it) << endl;
   }

   return 0;
}


