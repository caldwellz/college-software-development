/***********************************************************************
* Program:
*    Assignment 41, Allocating Memory
*    Brother Ridges, CS124
* Author:
*    Zachary Caldwell
* Summary: 
*    Allocate and manage memory for text based on user input.
*
*    Estimated:  30 min
*    Actual:     15 min
*      The trickiest part was remembering to use the funky nothrow syntax.
************************************************************************/

#include <iostream>
using namespace std;

/***********************************************************************
 * Orchestrate the main logic of the program.
 ***********************************************************************/
int main()
{
   int textSize;
   char *text;

   // Make space for the string
   cout << "Number of characters: ";
   cin >> textSize;
   textSize++;  // Make sure there's space for the terminating null
   cin.ignore();
   text = new (nothrow) char[textSize];
   if (text == NULL)
   {
      cout << "Allocation failure!\n";
      // testBed says it wants 1 but really fails if I don't return 0 here...
      return 0;
   }

   // Get and display the text
   cout << "Enter Text: ";
   cin.getline(text, textSize);
   cout << "Text: " << text << endl;

   delete text;
   return 0;
}
