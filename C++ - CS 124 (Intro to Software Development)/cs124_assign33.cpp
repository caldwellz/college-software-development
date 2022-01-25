/***********************************************************************
* Program:
*    Assignment 33, Pointers
*    Brother Ridges, CS124
* Author:
*    Zachary Caldwell
* Summary: 
*    This program will get account balances from the user and the costs
*    of a date, then subtract the costs from the largest account and display
*    the adjusted balances.
*
*    Estimated:  0.5 hrs
*    Actual:     0.66 hrs
*      The most difficult part was getting the const arrays to pass around.
************************************************************************/

#include <cassert>
#include <iomanip>
#include <iostream>
using namespace std;

/****************************************************************************
 * Get the balances of the given accounts from the user and return a pointer
 * to the largest account balance.
 ****************************************************************************/
double* getBalances(int numAccounts, const char* accountNames[],
                    double accounts[])
{
   double *pLargestAccount = NULL;
   double highestBalance = 0;

   for (int n = 0; n < numAccounts; ++n)
   {
      cout << "What is " << accountNames[n] << "'s balance? ";
      cin >> accounts[n];
      cin.ignore();
      if (accounts[n] > highestBalance)
      {
         pLargestAccount = &accounts[n];
         highestBalance = accounts[n];
      }
   }

   return pLargestAccount;
}

/****************************************************************************
 * Ask the user for the costs of a certain date and debit them from the
 * given account.
 ****************************************************************************/
void date(double *pAccount)
{
   double costDinner;
   double costMovie;
   double costIceCream;
   assert(pAccount != NULL);

   cout << "Cost of the date:" << endl
        << "\tDinner:    ";
   cin >> costDinner;
   cout << "\tMovie:     ";
   cin >> costMovie;
   cout << "\tIce cream: ";
   cin >> costIceCream;

   *pAccount = *pAccount - costDinner - costMovie - costIceCream;
}

/****************************************************************************
 * Display the current balances of the given accounts.
 ****************************************************************************/
void displayBalances(int numAccounts, const char* accountNames[],
                     const double accounts[])
{
   // Set cout to show two decimal places
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   for (int n = 0; n < numAccounts; ++n)
   {
      cout << accountNames[n] << "'s balance: $" << accounts[n] << endl;
   }
}

/**********************************************************************
 * Orchestrate the main logic through delegation.
 ***********************************************************************/
int main()
{
   int numAccounts = 2;
   double accounts[2];
   const char *accountNames[] = {"Sam", "Sue"};

   double *largestBalance = getBalances(numAccounts, accountNames, accounts);
   date(largestBalance);
   displayBalances(numAccounts, accountNames, accounts);

   return 0;
}
