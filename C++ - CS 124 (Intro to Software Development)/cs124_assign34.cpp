/***********************************************************************
* Program:
*    Assignment 34, Pointer Arithmetic
*    Brother Ridges, CS124
* Author:
*    Zachary Caldwell
* Summary: 
*    Ask the user for a letter and a text string and count how often the
*    letter occurs.
*
*    Estimated:  0.2 hrs
*    Actual:     0.33 hrs
*      The hardest part was getting to the end and remembering I didn't
*      need to use sizeof() for a char.
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

   for (char* position = text; position < text + MAX_TEXT_SIZE; position++)
   {
      if (*position == letter)
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
