/***********************************************************************
* Program:
*    Assignment 35, Advanced Conditionals
*    Brother Ridges, CS124
* Author:
*    Zachary Caldwell
* Summary: 
*    Ask the user for a number grade and display a letter grade.
*
*    Estimated:  30 min
*    Actual:     40 min
*      The hardest part was remembering to use conditionals in computeGradeSign
*      for the edge cases instead of if statements.
************************************************************************/

#include <iostream>
using namespace std;

/***********************************************************************
 * Computes a letter grade (without sign) from a number grade.
 ***********************************************************************/
char computeLetterGrade(int numGrade)
{
   int gradeBracket = numGrade / 10;
   switch (gradeBracket)
   {
      case 10:
      case 9:
         return 'A';
      case 8:
         return 'B';
      case 7:
         return 'C';
      case 6:
         return 'D';
      default:
         return 'F';
   }
}

/***********************************************************************
 * Computes the sign of a letter grade from a number grade.
 ***********************************************************************/
char computeGradeSign(int numGrade)
{
   int letterBracket = numGrade % 10;
   switch (letterBracket)
   {
      case 0:
      case 1:
      case 2:
         return (((numGrade >= 60) && (numGrade < 100)) ? '-' : '*');
      case 7:
      case 8:
      case 9:
         return (((numGrade >= 60) && (numGrade < 90)) ? '+' : '*');
      default:
         return '*';
   }
}

/***********************************************************************
 * Orchestrate the main logic of the program.
 ***********************************************************************/
int main()
{
   int numGrade;

   // Get a grade number
   cout << "Enter number grade: ";
   cin >> numGrade;
   cin.ignore();

   // Display the letter grade
   char letter = computeLetterGrade(numGrade);
   char sign = computeGradeSign(numGrade);
   cout << numGrade << "% is " << letter;
   if (sign != '*')
      cout << sign;
   cout << endl;

   return 0;
}
