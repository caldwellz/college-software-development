/***********************************************************************
* Program:
*    Assignment 30, Array Syntax
*    Brother Ridges, CS124
* Author:
*    Zachary Caldwell
* Summary: 
*    Ask the user for 10 grades and display the average.
*
*    Estimated:  0.5 hrs
*    Actual:     0.66 hrs
*      The hardest part was just figuring out how to best handle the
*      error checking.
************************************************************************/

#include <iostream>
#include <math.h>
using namespace std;

/***********************************************************************
 * Asks the user for 10 grades and puts them in an array.
 ***********************************************************************/
void getGrades(int* grades)
{
   int grade;
   for (int num = 0; num <= 9; ++num)
   {
      cout << "Grade " << num + 1 << ": ";
      cin >> grade;
      grades[num] = grade;
   }
}

/***********************************************************************
 * Returns the average of an array of 10 grades.
 ***********************************************************************/
int averageGrades(int* grades)
{
   float total = 0;
   for (int num = 0; num <= 9; ++num)
   {
      total += grades[num];
   }

   return round (total / 10.0);
}

/***********************************************************************
 * Orchestrate the main logic of the program through delegation and then
 * displays the average grade.
 ***********************************************************************/
int main()
{
   int grades[10];
   getGrades(grades);

   int average = averageGrades(grades);
   cout << "Average Grade: " << average << "%" << endl;

   return 0;
}
