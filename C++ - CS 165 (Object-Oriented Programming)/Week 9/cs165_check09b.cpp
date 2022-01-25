/***********************************************************************
* Program:
*    Checkpoint 09b, Pure Virtual Functions
*    Brother Barney, CS165
* Author:
*    Zachary Caldwell
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// For this assignment, for simplicity, you may put all of your classes
// in this file.

class Shape
{
protected:
   string name;

public:
   virtual ~Shape() { }
   string getName() const { return name; }
   void setName(string name) { this->name = name; }
   virtual float getArea() = 0;
};

class Circle : public Shape
{
private:
   float radius;

public:
   ~Circle()
   {
      cout << "Cleaning up " << getName() << endl;
   }

   float getRadius() const { return radius; }
   void setRadius(float radius) { this->radius = radius; }
   Circle() { name = "Circle"; }
   float getArea() { return 3.14 * radius * radius; }
};

class Rectangle : public Shape
{
private:
   float length;
   float width;

public:
   ~Rectangle()
   {
      cout << "Cleaning up " << getName() << endl;
   }

   float getLength() const { return length; }
   float getWidth() const { return width; }
   void setLength(float length) { this->length = length; }
   void setWidth(float width) {this->width = width; }
   Rectangle() { name = "Rectangle"; }
   float getArea() { return length * width; }
};

const int MAX_SIZE = 10;

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // We will put all of our code in main for this one, just to keep
   // the focus on the virtual functions and not on passing items
   // between functions.

   Shape **shapes = new Shape*[MAX_SIZE];
   char letter;
   int count = 0;

   do
   {
      cout << "Please enter 'c' for circle, 'r' for rectangle or 'q' to quit: ";
      cin >> letter;

      if (letter == 'c')
      {
         float radius;
         cout << "Enter the radius: ";
         cin >> radius;

         Circle *c = new Circle;
         c->setRadius(radius);
         shapes[count] = c;
         count++; // we have seen another shape
      }
      else if (letter == 'r')
      {
         float length;
         float width;

         cout << "Enter the length: ";
         cin >> length;

         cout << "Enter the width: ";
         cin >> width;

         Rectangle *r = new Rectangle;
         r->setLength(length);
         r->setWidth(width);
         shapes[count] = r;
         count++; // we have seen another shape
      }

   } while (letter != 'q');

   // Set the precision for our decimals
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   // Now we will display each shape
   for (int i = 0; i < count; i++)
   {
      Shape *shape = shapes[i];
      cout << shape->getName() << " - " << shape->getArea() << endl;
   }

   for (int i = 0; i < count; i++)
   {
      delete shapes[i];
   }
   delete shapes;

   return 0;
}


