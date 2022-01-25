/***********************************************************************
* Program:
*    Assignment 32, Strings
*    Brother Ridges, CS124
* Author:
*    Zachary Caldwell
* Summary: 
*    Ask the user for a letter and a text string and count how often the
*    letter occurs.
*
*    Estimated:  0.5 hrs
*    Actual:     0.33 hrs
*      I think the hardest part was prompting for the letter and string.
************************************************************************/

#include <iostream>
using namespace std;

const unsigned int MAX_TEXT_SIZE = 256;

/***********************************************************************
 * Count the number of times the given letter occurs in the given string.
 ***********************************************************************/
int countLetters(char letter, char* text)
{
   int count = 0;

   for (int position = 0; position < MAX_TEXT_SIZE; ++position)
   {
      if (text[position] == letter)
         count++;
   }

   return count;
}

/***********************************************************************
 * Orchestrate the main logic of the program.
 ***********************************************************************/
int main()
{
   char letter;
   char text[MAX_TEXT_SIZE];
   int numLetters;

   // Get letter and text string
   cout << "Enter a letter: ";
   cin >> letter;
   cin.ignore();
   cout << "Enter text: ";
   cin.getline(text, MAX_TEXT_SIZE);

   // Display the occurrence of the letter
   numLetters = countLetters(letter, text);
   cout << "Number of '" << letter << "'s: " << numLetters << endl;

   return 0;
}
