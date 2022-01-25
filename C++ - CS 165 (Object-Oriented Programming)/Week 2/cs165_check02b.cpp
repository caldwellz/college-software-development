/***********************************************************************
* Program:
*    Checkpoint 02b, Complex Numbers
*    Brother Barney, CS165
* Author:
*    Zachary Caldwell
* Summary: 
*    Weekly Checkpoint
************************************************************************/

#include <iostream>
#include <string>
using namespace std;

struct Complex
{
   double realPart;
   double imaginaryPart;
};

/**********************************************************************
 * Function: addComplex
 * Purpose: Adds two complex numbers together and returns the sum.
 ***********************************************************************/
Complex addComplex(const Complex & x, const Complex & y)
{
   Complex sum;
   sum.realPart = x.realPart + y.realPart;
   sum.imaginaryPart = x.imaginaryPart + y.imaginaryPart;

   return sum;
}

/**********************************************************************
 * Function: prompt
 * Purpose: Gets a complex number from the user and returns it.
 ***********************************************************************/
Complex prompt()
{
   Complex num;

   cout << "Real: ";
   cin >> num.realPart;
   cout << "Imaginary: ";
   cin >> num.imaginaryPart;

   return num;
}

/**********************************************************************
 * Function: display
 * Purpose: Displays a complex number in a normalized format.
 ***********************************************************************/
void display(Complex &num)
{
   cout << num.realPart << " + " << num.imaginaryPart << "i";
}

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   Complex c1;
   Complex c2;
   Complex sum;
 
   c1 = prompt();
   c2 = prompt();
   sum = addComplex(c1, c2);

   cout << "\nThe sum is: ";
   display(sum);
   cout << endl;
 
   return 0;
}
