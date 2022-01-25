/***********************************************************************
* Program:
*    Checkpoint 09a, Virtual Functions
*    Brother Barney, CS165
* Author:
*    Zachary Caldwell
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Car
{
   public:
      Car():
         name("Unknown model")
      { }
      string getName() { return name; }
      void setName(string newName) { name = newName; }
      virtual string getDoorSpecs() { return string("Unknown doors"); }

   protected:
      string name;
};

class Civic: public Car
{
   public:
      Civic() { name = "Civic"; }
      string getDoorSpecs() { return string("4 doors"); }
};

class Odyssey: public Car
{
   public:
      Odyssey() { name = "Odyssey"; }
      string getDoorSpecs() { return string("2 front doors, 2 sliding doors, 1 tail gate"); }
};

class Ferrari: public Car
{
   public:
      Ferrari() { name = "Ferrari"; }
      string getDoorSpecs() { return string("2 butterfly doors"); }
};

/**********************************************************************
 * Function: attachDoors
 * Purpose: This function can accept any type of Car object. It will
 *  call the appropriate functions to display the name and the doors info.
 ***********************************************************************/
void attachDoors(Car &car)
{
   cout << "Attaching doors to " << car.getName() << " - "
        << car.getDoorSpecs() << endl;
}

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // You should not change main

   Civic civic;
   Odyssey odyssey;
   Ferrari ferrari;

   attachDoors(civic);
   attachDoors(odyssey);
   attachDoors(ferrari);

   return 0;
}


