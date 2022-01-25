/***************************************************************
 * File: product.cpp
 * Author: Zachary Caldwell
 * Purpose: Contains the method implementations for the Product class.
 ***************************************************************/

#include "product.h"

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

/***********************************************************************
* Prompt the user for product details.
************************************************************************/
void Product::prompt()
{
   cout << "Enter name: ";
   getline(cin, this->name);
   cout << "Enter description: ";
   getline(cin, this->description);

   cout << "Enter weight: ";
   cin >> this->weight;
   while (cin.fail() || (this->weight < 0))
   {
      cin.clear();
      cin.ignore(256, '\n');
      cout << "Enter weight: ";
      cin >> this->weight;
   }

   cout << "Enter price: ";
   cin >> this->basePrice;
   while (cin.fail() || (this->basePrice < 0))
   {
      cin.clear();
      cin.ignore(256, '\n');
      cout << "Enter price: ";
      cin >> this->basePrice;
   }
}

/***********************************************************************
* Get the sales tax value
************************************************************************/
Cost Product::getSalesTax()
{
   return 0.06 * this->basePrice;
}

/***********************************************************************
* Calculate the shipping cost based on the weight
************************************************************************/
Cost Product::getShippingCost()
{
   Cost shipCost = 2.0;

   if (this->weight > 5)
      shipCost += (this->weight - 5) * 0.1;

   return shipCost;
}

/***********************************************************************
* Calculate the total end cost.
************************************************************************/
Cost Product::getTotalPrice()
{
   return (this->basePrice + getSalesTax() + getShippingCost());
}

/***********************************************************************
* Display the advertisement profile.
************************************************************************/
void Product::displayAdvertProfile()
{
   cout.setf(ios::fixed);
   cout.precision(2);
   cout << this->name << " - $" << this->basePrice << endl
        << "(" << this->description << ")\n";
}

/***********************************************************************
* Display the product as an inventory line item.
************************************************************************/
void Product::displayLineItem()
{
   cout.setf(ios::fixed);
   cout.precision(2);
   cout << "$" << this->basePrice << " - " << this->name;
   cout.precision(1);
   cout << " - " << this->weight << " lbs\n";
}

/***********************************************************************
* Display a receipt for the item.
************************************************************************/
void Product::displayReceipt()
{
   cout.setf(ios::fixed);
   cout.precision(2);
   cout << this->name << endl
        << "  Price:         $" << setw(8) << this->basePrice << endl
        << "  Sales tax:     $" << setw(8) << getSalesTax() << endl
        << "  Shipping cost: $" << setw(8) << getShippingCost() << endl
        << "  Total:         $" << setw(8) << getTotalPrice() << endl;
}
