/***********************************************************************
* Program:
*    Assignment 11, Display Budget
*    Brother Ridges, CS124
* Author:
*    Zachary Caldwell
* Summary: 
*    Displays an example monthly budget.
*
*    Estimated:  0.66 hrs
*    Actual:     1.25 hrs
*      I think the hardest part was probably getting the column spacing
*       to work right.
************************************************************************/

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

/***********************************************************************
 * displayBudgetLine
 * Formats a budget line with the given input according to the number
 * of spaces given and prints the formatted string.
 ***********************************************************************/
void displayBudgetLine(string budgetItemName, float budgetedAmount)
/* const unsigned int ITEM_WIDTH, const unsigned int COLUMN_SPACING,
   const unsigned int AMOUNT_WIDTH) */
{
   // Spacing rules; maybe refactor constants into parameters for project
   // Also the style checker complains about the naming convention, but the
   //   style guide says to do all constants this way, so I went with that...
   const unsigned int ITEM_WIDTH = 13;
   const unsigned int COLUMN_SPACING = 2;
   const unsigned int AMOUNT_WIDTH = 9;

   unsigned int itemSpacing = (ITEM_WIDTH - budgetItemName.length()) + 1
                               + COLUMN_SPACING;

   cout << '\t' << budgetItemName << setw(itemSpacing) << "$"
        << setw(AMOUNT_WIDTH) << budgetedAmount << endl;
}

/***********************************************************************
 * MAIN
 * Displays a monthly budget.
 ***********************************************************************/
int main()
{
   // Set cout parameters
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   // Display each line
   cout << "\tItem           Projected"  << endl
        << "\t=============  ==========" << endl;
   displayBudgetLine("Income", 1000);
   displayBudgetLine("Taxes", 100);
   displayBudgetLine("Tithing", 100);
   displayBudgetLine("Living", 650);
   displayBudgetLine("Other", 90);
   cout << "\t=============  ==========" << endl;
   displayBudgetLine("Delta", 60);

   return 0;
}
