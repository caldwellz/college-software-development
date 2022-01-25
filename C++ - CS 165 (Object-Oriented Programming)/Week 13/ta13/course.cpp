// course.cpp

#include "course.h"
#include <string>
#include <iostream>
using namespace std;

Course::Course(int size)
{
   // TODO: Fill this in
}

Student Course::getStudent(int index) const
{
   // TODO: Fill this in
}

void Course::setStudent(int index, const Student & student)
{
   // TODO: Fill this in
}

void Course::displayList() const
{
   cout << "Class list for course: " << name << endl;

   for (int i = 0; i < size; i++)
   {
      classList[i].display();
   }
}

