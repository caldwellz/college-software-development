/***************************************************************
 * File: assign04.cpp
 * Author: Zachary Caldwell
 * Purpose: Contains the main function to test the Product class.
 ***************************************************************/

#include <iostream>
#include <string>
using namespace std;

#include "product.h"

/***********************************************************************
* Program entry point.
************************************************************************/
int main()
{
   Product product;
   product.prompt();

   cout << endl;
   cout << "Choose from the following options:\n";
   cout << "1 - Advertising profile\n";
   cout << "2 - Inventory line item\n";
   cout << "3 - Receipt\n";
   cout << endl;
   cout << "Enter the option that you would like displayed: ";

   int choice;
   cin >> choice;

   cout << endl;

   if (choice == 1)
   {
      product.displayAdvertProfile();
   }
   else if (choice == 2)
   {
      product.displayLineItem();
   }
   else
   {
      product.displayReceipt();
   }

   return 0;
}
