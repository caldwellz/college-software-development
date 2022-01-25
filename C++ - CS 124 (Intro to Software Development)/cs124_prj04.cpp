/***********************************************************************
* Program:
*    Project 04, Monthly Budget
*    Brother Ridges, CS124
* Author:
*    Zachary Caldwell
* Summary: 
*    Prompt the user for several budget and expense figures, then calculate
*    and display their monthly budget in a nice table.
*
*    Estimated:  0.2 hrs
*    Actual:     0.3 hrs
*      The hardest part was just refactoring the computeTax function a bit.
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
double computeTithing(double income)
{
   return income / 10;
}

/****************************************************************************
 * Calculates estimated monthly income tax based on the given income.
 ****************************************************************************/
double computeTax(double monthlyIncome)
{
   // Initialize and figure out annual income
   double income = monthlyIncome * 12;
   double annualTax;

   // Estimate annual tax burden
   if (income < 0)
      annualTax = 0;
   else if (income <= 15100)
      annualTax = income * 0.1;
   else if (income <= 61300)
      annualTax = ((income - 15100) * 0.15) + 1510;
   else if (income <= 123700)
      annualTax = ((income - 61300) * 0.25) + 8440;
   else if (income <= 188450)
      annualTax = ((income - 123700) * 0.28) + 24040;
   else if (income <= 336550)
      annualTax = ((income - 188450) * 0.33) + 42170;
   else
      annualTax = ((income - 336550) * 0.35) + 91043;

   return annualTax / 12;
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
   // Initialize variables and perform calculations
   double taxesBudget      = computeTax(monthlyIncome);
   double tithingBudget    = computeTithing(monthlyIncome);
   double otherBudget      = monthlyIncome - taxesBudget - tithingBudget
                             - livingBudget;
   double differenceBudget = 0;
   double differenceActual = monthlyIncome - taxesActual - tithingActual
                             - livingActual - otherActual;

   // Set cout options to show two decimal points
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   // Display the header and budget
   cout << endl << "The following is a report on your monthly expenses"
        << endl << "\tItem                  Budget          Actual"
        << endl << "\t=============== =============== ===============" << endl;
   displayBudgetItem("Income", monthlyIncome, monthlyIncome);
   displayBudgetItem("Taxes", taxesBudget, taxesActual);
   displayBudgetItem("Tithing", tithingBudget, tithingActual);
   displayBudgetItem("Living", livingBudget, livingActual);
   displayBudgetItem("Other", otherBudget, otherActual);
   cout << "\t=============== =============== ===============" << endl;
   displayBudgetItem("Difference", differenceBudget, differenceActual);
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
