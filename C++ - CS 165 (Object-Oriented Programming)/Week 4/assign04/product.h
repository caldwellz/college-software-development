/***************************************************************
 * File: product.h
 * Author: Zachary Caldwell
 * Purpose: Contains the definition of the Product class
 ***************************************************************/
#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

typedef double Cost;

class Product
{
   public:
      void prompt();
      Cost getSalesTax();
      Cost getShippingCost();
      Cost getTotalPrice();
      void displayAdvertProfile();
      void displayLineItem();
      void displayReceipt();

   private:
      string name;
      string description;
      Cost basePrice;
      double weight;
};

#endif
