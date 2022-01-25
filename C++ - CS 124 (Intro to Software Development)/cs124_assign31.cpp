/***********************************************************************
* Program:
*    Assignment 31, Array Design
*    Brother Ridges, CS124
* Author:
*    Zachary Caldwell
* Summary: 
*    Ask the user for 10 grades and display the average.
*
*    Estimated:  0.25 hrs
*    Actual:     0.2 hrs
*      The hardest part was just adding a counter variable.
************************************************************************/

#include <iostream>
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
   int total = 0;
   int count = 0;

   for (int num = 0; num <= 9; ++num)
   {
      if (grades[num] >= 0)
      {
         total += grades[num];
         count += 1;
      }
   }

   if (count == 0)
      return 0;
   else
      return total / count;
}

/***********************************************************************
 * Orchestrate the main logic of the program through delegation and then
 * display the average grade.
 ***********************************************************************/
int main()
{
   int grades[10];
   getGrades(grades);

   int average = averageGrades(grades);
   if (average > 0)
      cout << "Average Grade: " << average << "%" << endl;
   else
      cout << "Average Grade: ---%" << endl;

   return 0;
}
