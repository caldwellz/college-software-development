#include "velocity.h"

#include <iostream>
using namespace std;

// TODO: Put your method bodies here



void Velocity :: prompt()
{
   cout << "dx: ";
   cin >> dx;

   cout << "dy: ";
   cin >> dy;
}

void Velocity :: display() const 
{
   cout << "(dx=" << dx << ", dy=" << dy << ")";
}
