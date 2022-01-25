/***********************************************************************
 * Implementation:
 *    FIBONACCI
 * Summary:
 *    This will contain the implementation for fibonacci() as well as any
 *    other function or class implementations you may need
 * Author
 *    John Batty
 *    Jordon Thompson
 *    Brian Thompson
 *    Emmanuel Gatica
 *    Zach Caldwell
 **********************************************************************/

#include <iostream>
#include "fibonacci.h"   // for fibonacci() prototype
#include "list.h"        // for LIST
#include "wholeNumber.h" // to deal with large numbers
using namespace std;


/************************************************
 * FIBONACCI
 * The interactive function allowing the user to
 * display Fibonacci numbers
 ***********************************************/
void fibonacci()
{
   // show the first serveral Fibonacci numbers
   int number;
   cout << "How many Fibonacci numbers would you like to see? ";
   cin  >> number;

   // your code to display the first <number> Fibonacci numbers
   custom::WholeNumber a = 0, b = 1,c;
   if(number > 0)
      cout << '\t' << b << endl;
   for(int i = 2;i <= number;i++)
   {
      c = a + b;
      a = b;
      b = c;
      cout << '\t' << b << endl;
   }
   // prompt for a single large Fibonacci
   cout << "Which Fibonacci number would you like to display? ";
   cin  >> number;

   // your code to display the <number>th Fibonacci number
   
   a = 0, b = 1;
   if(number == 0)
      cout << '\t' << a << endl;
   else if(number == 1)
      cout << '\t' << b << endl;
   else{
    for(int i = 2;i <= number;i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    cout << '\t' << b << endl;
   }
}


