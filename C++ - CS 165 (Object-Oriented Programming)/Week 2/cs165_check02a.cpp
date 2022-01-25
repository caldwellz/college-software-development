/***********************************************************************
* Program:
*    Checkpoint 02a, Structs
*    Brother Barney, CS165
* Author:
*    Zachary Caldwell
* Summary: 
*    Weekly Checkpoint
************************************************************************/

#include <iostream>
#include <string>
using namespace std;

struct Student
{
   string firstName;
   string lastName;
   int studentID;
};

/***********************************************************************
* Display a formatted student record.
************************************************************************/
void displayStudent(Student &student)
{
   cout << "\nYour information:\n" << student.studentID << " - "
        << student.firstName << " " << student.lastName << endl;
}

/***********************************************************************
* Main entry point for the program.
************************************************************************/
int main()
{
   Student student;

   cout << "Please enter your first name: ";
   cin >> student.firstName;
   cout << "Please enter your last name: ";
   cin >> student.lastName;
   cout << "Please enter your id number: ";
   cin >> student.studentID;
   displayStudent(student);

   return 0;
}
