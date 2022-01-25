/***********************************************************************
* Program:
*    Project 02, Monthly Budget (Prompt & Display Only)
*    Brother Ridges, CS124
* Author:
*    Zachary Caldwell
* Summary: 
*    Prompt for several monthly budget figures and print them in a nice table.
*
*    Estimated:  2.0 hrs
*    Actual:     2.0 hrs
*      The hardest part was probably just dividing out and filling in all
*        the different functions.
************************************************************************/

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

/**********************************************************************
 * Asks the user for a double using the given prompt string,
 *  then validates it and returns it or asks again if needed.
 ***********************************************************************/
double getDouble(string promptMessage)
{
   // Initialize variables
   bool isInputValid = false;
   double inputValue = 0.0;

   // Loop until input is valid
   while (!isInputValid)
   {
      // Get the input; cin automatically keeps the newline
      cout << promptMessage;
      cin >> inputValue;

      // Validate the input
      isInputValid = !(cin.fail());
      if (!isInputValid)
      {
         // Clear the error status and ignore the rest of the invalid line
         cin.clear();
         cin.ignore(500, '\n');
      }
   }

   return inputValue;
}

/**********************************************************************
 * Prompt for the user's income and return it.
 ***********************************************************************/
double getIncome()
{
   double income = getDouble("\tYour monthly income: ");
   return income;
}

/**********************************************************************
 * Prompt for the user's living expense budget and return it.
 ***********************************************************************/
double getBudgetLiving()
{
   double livingBudget = getDouble("\tYour budgeted living expenses: ");
   return livingBudget;
}

/**********************************************************************
 * Prompt for the user's actual living expenses value and return it.
 ***********************************************************************/
double getActualLiving()
{
   double livingActual = getDouble("\tYour actual living expenses: ");
   return livingActual;
}

/**********************************************************************
 * Prompt for the user's actual tax amount and return it.
 ***********************************************************************/
double getActualTax()
{
   double taxesActual = getDouble("\tYour actual taxes withheld: ");
   return taxesActual;
}

/**********************************************************************
 * Prompt for the user's actual tithing amount and return it.
 ***********************************************************************/
double getActualTithing()
{
   double tithingActual = getDouble("\tYour actual tithe offerings: ");
   return tithingActual;
}

/**********************************************************************
 * Prompt for the user's actual other expense value and return it.
 ***********************************************************************/
double getActualOther()
{
   double otherActual = getDouble("\tYour actual other expenses: ");
   return otherActual;
}

/**********************************************************************
 * Calculate the user's tithing amount and return it.
 ***********************************************************************/
double computeTithing()
{
   return 0.0;
}

/**********************************************************************
 * Calculate the user's estimated tax amount and return it.
 ***********************************************************************/
double computeTax()
{
   return 0.0;
}

/***********************************************************************
 * Format the given item name and amount as a budget line and display it.
 ***********************************************************************/
void displayBudgetItem(string budgetItemName, double budgetedAmount,
                       double actualAmount)
{
   // Spacing rules; yeah I know the style checker complains about the naming
   //   convention, but the style guide says to do all constants this way, so
   //   I ended up going with that...
   const unsigned int COLUMN_WIDTH = 15;
   const unsigned int COLUMN_SPACING = 1;
   const unsigned int NUMBER_PADDING_RIGHT = 3;
   unsigned int itemSpacing = (COLUMN_WIDTH - budgetItemName.length())
                              + 1 + COLUMN_SPACING;

   // Print the budget line
   cout << '\t' << budgetItemName << setw(itemSpacing)
               // Subtract the extra 1 and add back later to account for '$'
        << "$" << setw(COLUMN_WIDTH - NUMBER_PADDING_RIGHT - 1)
        << budgetedAmount << setw(NUMBER_PADDING_RIGHT + COLUMN_SPACING + 1)
        << "$" << setw(COLUMN_WIDTH - NUMBER_PADDING_RIGHT - 1) << actualAmount
        << endl;
}

/**********************************************************************
 * Format the budget and display it.
 ***********************************************************************/
void display(double monthlyIncome, double livingBudget, double taxesActual,
             double tithingActual, double livingActual, double otherActual)
{
   // Set cout options to show two decimal points
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   // Display the budget
   cout << endl << "The following is a report on your monthly expenses"
        << endl << "\tItem                  Budget          Actual"
        << endl << "\t=============== =============== ===============" << endl;
   displayBudgetItem("Income", monthlyIncome, monthlyIncome);
   displayBudgetItem("Taxes", computeTax(), taxesActual);
   displayBudgetItem("Tithing", computeTithing(), tithingActual);
   displayBudgetItem("Living", livingBudget, livingActual);
   displayBudgetItem("Other", 0, otherActual);
   cout << "\t=============== =============== ===============" << endl;
   displayBudgetItem("Difference", 0, 0);
}

/**********************************************************************
 * Orchestrate the main logic of the program through delegation.
 ***********************************************************************/
int main()
{
   // Initialize variables
   double monthlyIncome;
   double livingBudget;
   double livingActual;
   double taxesActual;
   double tithingActual;
   double otherActual;

   // Display header and get needed numbers from user
   cout << "This program keeps track of your monthly budget" << endl
        << "Please enter the following:" << endl;
   monthlyIncome = getIncome();
   livingBudget = getBudgetLiving();
   livingActual = getActualLiving();
   taxesActual = getActualTax();
   tithingActual = getActualTithing();
   otherActual = getActualOther();

   // Display the budget
   display(monthlyIncome, livingBudget, taxesActual, tithingActual,
           livingActual, otherActual);

   return 0;
}
