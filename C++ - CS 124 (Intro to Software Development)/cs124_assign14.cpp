/***********************************************************************
* Program:
*    Assignment 14, Matthew 18:21-22
*    Brother Ridges, CS124
* Author:
*    Zachary Caldwell
* Summary: 
*    This program will address Peter's question to the Lord in 
*    Matthew 18:21-22
*
*    Estimated:  0.25 hrs
*    Actual:     0.17 hrs
*      The most difficult part was just filling in the function contents.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
* Display Peter's question.
***********************************************************************/
void questionPeter()
{
   cout << "Lord, how oft shall my brother sin against me, and I forgive him?"
        << endl << "Till seven times?" << endl;
}

/**********************************************************************
* Return the Lord's answer.
***********************************************************************/
int responseLord()
{
   return 70 * 7;
}

/**********************************************************************
* You are not allowed to change MAIN in any way; just implement the two
* functions: questionPeter() and responseLord()
***********************************************************************/
int main()
{
   // ask Peter's question
   questionPeter();

   // the first part of the Lord's response
   cout << "Jesus saith unto him, I say not unto thee, Until seven\n";
   cout << "times: but, Until " << responseLord() << ".\n";

   return 0;
}
