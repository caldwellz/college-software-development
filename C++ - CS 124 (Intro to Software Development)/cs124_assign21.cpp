/***********************************************************************
* Program:
*    Assignment 21, Debugging
*    Brother Ridges, CS124
* Author:
*    Zachary Caldwell
* Summary: 
*    This program outlines a potential basic structure for determining
*    regular vehicle costs.
*
*    Estimated:  0.25 hrs
*    Actual:     0.4 hrs
*      The hardest part was really just fleshing out the function signatures.
************************************************************************/

#include <iostream>
using namespace std;

/*** Dummy constant and function signatures ***/
const int DUMMY_VALUE = 0;
void display(double costPeriodic, double costUsage);
double getUsageCost();
double promptMileage();
double promptGas();
double promptRepairs();
double promptTires();
double getPeriodicCost();
double promptDevalue();
double promptInsurance();
double promptParking();

int main()
{
   double costPeriodic = getPeriodicCost();
   double costUsage = getUsageCost();

   display(costPeriodic, costUsage);

   return 0;
}

void display(double costPeriodic, double costUsage)
{
   cout << "Success\n";
}

/*** Variable usage costs ***/
double getUsageCost()
{
   double mileage = promptMileage();
   double gas = promptGas();
   double otherCosts = promptRepairs() + promptTires();

   // Math magic here...
   double costUsage = DUMMY_VALUE;

   return costUsage;
}

double promptMileage()
{
   double mileage = DUMMY_VALUE;

   return mileage;
}

double promptGas()
{
   double cost = DUMMY_VALUE;

   return cost;
}

double promptRepairs()
{
   double cost = DUMMY_VALUE;

   return cost;
}

double promptTires()
{
   double cost = DUMMY_VALUE;

   return cost;
}

/*** Periodic costs ***/
double getPeriodicCost()
{
   double costPeriodic = promptDevalue() + promptInsurance() + promptParking();

   return costPeriodic;
}

double promptDevalue()
{
   double cost = DUMMY_VALUE;

   return cost;
}

double promptInsurance()
{
   double cost = DUMMY_VALUE;

   return cost;
}

double promptParking()
{
   double cost = DUMMY_VALUE;

   return cost;
}
