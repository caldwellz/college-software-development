/***********************************************************************
* Program:
*    Assignment 26, Files
*    Brother Ridges, CS124
* Author:
*    Zachary Caldwell
* Summary: 
*    Ask the user for a filename and display the average of 10 grades from it.
*
*    Estimated:  0.5 hrs
*    Actual:     0.6 hrs
*      The hardest part was just figuring out how to best handle the
*      error checking.
************************************************************************/

#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

/***********************************************************************
 * Asks the user for a file name.
 ***********************************************************************/
void getFileName(char fileName[])
{
   cout << "Please enter the filename: ";
   cin >> fileName;
}

/***********************************************************************
 * Reads ten scores from the given file and returns the average.
 ***********************************************************************/
float readFile(char fileName[])
{
   int counter = 0;
   float score = 0;
   float scoresTotal = 0;
   ifstream fin(fileName);

   // Read the file (could check is_open() to see if it actually opened,
   // but the counter check can take care of that case too, so...)
   for (; fin >> score; ++counter)
      scoresTotal += score;

   // Make sure there was the right number of scores
   if (counter != 10)
   {
      cout << "Error reading file \"" << fileName << "\"\n";
      return -1;
   }

   return scoresTotal / 10.0;
}

/***********************************************************************
 * Displays the averaged grade.
 ***********************************************************************/
void display(float average)
{
   // < 0 indicates an error happened somewhere
   if (average >= 0)
   {
      // Set cout to round the output
      cout.setf(ios::fixed);
      cout.precision(0);

      cout << "Average Grade: " << average << "%\n";
   }
}

/***********************************************************************
 * Orchestrate the main logic of the program through delegation.
 ***********************************************************************/
int main()
{
   char fileName[256];
   getFileName(fileName);

   float average = readFile(fileName);
   display(average);

   return 0;
}
