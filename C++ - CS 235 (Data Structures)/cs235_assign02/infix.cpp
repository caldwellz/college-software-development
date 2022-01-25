/***********************************************************************
 * Module:
 *    Week 02, Stack
 *    Brother Jonesl, CS 235
 * Author:
 *    Brian Thompson
 *    Zach Caldwell
 *    John Batty
 *    Jordon Thompson
 * Summary:
 *    A program that converts an infix function to postfix. And also 
 *    postfix to assembly
 ************************************************************************/

#include <iostream>    // for ISTREAM and COUT
#include <string>      // for STRING
#include <sstream>     // for STRINGSTREAM
#include <cassert>     // for ASSERT
#include "stack.h"     // for STACK
//#include <stack>
using namespace std;
using namespace custom;

/**********************************************************************
 * Function: isOp
 * Purpose: Determines if the input string is an operation (i.e. +,-,*,/,etc.)
 *	and returns an integer representing it's order of operation. Larger int
 *	means higher order. Returns 0 if it is not an operation.
 ***********************************************************************/
int isOp(string input)
{
   if (input.length() != 1)
	  return 0;
   char op = input[0];
   switch (op)
   {
   case '^':
	  return 3;
   case '*':
   case '/':
   case '%':
	  return 2;
   case '+':
   case '-':
	  return 1;
   default:
	  return 0;
   }
}

/**********************************************************************
 * Function: prep
 * Purpose: Prepares the input by makeing certain all valid operations
 *  are seperated by a space
 ***********************************************************************/
string prep(string input)
{
   string output = "";
   // previous character was an operation/perenthesis?
   bool wasop = false;
   for (int i = 0;i < input.length();i++)
   {
	  if (input[i] != ' ') // skip spaces
	  {
		 // current character is an operation/perenthesis?
		 bool isop = isOp(string(1, input[i])) ||
			input[i] == '(' || input[i] == ')';

		 // put a space before an operation
		 if (isop && !wasop)
			output += " ";

		 // transfer character
		 output += input[i];

		 // put a space after an operation
		 if (isop)
			output += " ";

		 // update previous character status
		 wasop = isop;
	  }
   }
   return output;
}

/**********************************************************************
 * Function: postfixEval
 * Purpose: Takes an infix formatted input as a string stream and
 *   evaluates the stream recursively. Returns a postfix formated string
 ***********************************************************************/
string postfixEval(stringstream & ss)
{
   string hold;
   string output;
   //stack<string> ops;
   stack<string> ops;
   
   // loop through the string stream
   while (ss >> hold)
   {

	  if (hold == ")") // we're at the end of this perenthesis evaluation. leave.
		 break;

	  if (hold == "(") // time to start a new parenthesis evaluation
		 output += postfixEval(ss); // recursive call, append to our output.

	  int order = isOp(hold);
	  if (order)
	  { // handle an operation
			while ((!ops.empty()) && order <= isOp(ops.top())) { // take of higher order operations before
				  output += ops.top() + " ";
				  ops.pop();
			}
		 ops.push(hold);
	  }
	  else
	  {
		 if (hold != "(") // special case: don't include any parentheses
			output += hold + " "; // Add the value
	  }
   }

   // put any remaining operations on the end
   while (!ops.empty())
   {
	  output += ops.top() + " ";
	  ops.pop();
   }

   return output;
}

/**********************************************************************
 * Function: opToAsm
 * Purpose: returns the assembly opcode for an operation
 ***********************************************************************/
string opToAsm(string input)
{
   if (input.length() != 1)
	  return "\tLOD"; // load data that isn't an operation
   char op = input[0];
   switch (op)
   {
   case '^':
	  return "\tEXP";
   case '*':
	  return "\tMUL";
   case '/':
	  return "\tDIV";
   case '%':
	  return "\tMOD";
   case '+':
	  return "\tADD";
   case '-':
	  return "\tSUB";
   default:
	  return "\tLOD"; // load data that isn't an operation
   }
}

/*****************************************************
 * CONVERT INFIX TO POSTFIX
 * Convert infix equation "5 + 2" into postifx "5 2 +"
 *****************************************************/
string convertInfixToPostfix(const string & infix)
{
   stringstream ss;
   ss << " " << prep(infix);
   string output = postfixEval(ss);
   output.erase(output.end() - 1);			 // needed to remove the last space after postfix
   return output;
}

/*****************************************************
 * TEST INFIX TO POSTFIX
 * Prompt the user for infix text and display the
 * equivalent postfix expression
 *****************************************************/
void testInfixToPostfix()
{
   string input;
   cout << "Enter an infix equation.  Type \"quit\" when done.\n";

   do
   {
	  // handle errors
	  if (cin.fail())
	  {
		 cin.clear();
		 cin.ignore(256, '\n');
	  }

	  // prompt for infix
	  cout << "infix > ";
	  getline(cin, input);

	  // generate postfix
	  if (input != "quit")
	  {
		 string postfix = convertInfixToPostfix(input);
		 cout << "\tpostfix:  " << postfix << endl << endl;
	  }
   } while (input != "quit");
}

/**********************************************
 * CONVERT POSTFIX TO ASSEMBLY
 * Convert postfix "5 2 +" to assembly:
 *     LOAD 5
 *     ADD 2
 *     STORE VALUE1
 **********************************************/
string convertPostfixToAssembly(const string & postfix)
{
   string assembly;

   stringstream ss;
   ss << postfix;

   string output;

   //stack<string> program;
   stack<string> program;

   char letter = 'A';

   for (string hold;ss >> hold;)
	  if (isOp(hold) && !program.empty())
	  {
		 string rhs = program.top();
		 program.pop();
		 string lhs = program.top();
		 program.pop();
		 program.push(string(1, letter));

		 output += (!isalpha(lhs[0]) ? "\tSET " : "\tLOD ") + lhs + "\n";
		 output += opToAsm(hold) + " " + rhs + "\n";
		 output += "\tSAV " + string(1, letter) + "\n";
		 letter++;
	  }
	  else
		 program.push(hold);

   return output;
}

/*****************************************************
 * TEST INFIX TO ASSEMBLY
 * Prompt the user for infix text and display the
 * resulting assembly instructions
 *****************************************************/
void testInfixToAssembly()
{
   string input;
   cout << "Enter an infix equation.  Type \"quit\" when done.\n";

   do
   {
	  // handle errors
	  if (cin.fail())
	  {
		 cin.clear();
		 cin.ignore(256, '\n');
	  }

	  // prompt for infix
	  cout << "infix > ";
	  getline(cin, input);

	  // generate postfix
	  if (input != "quit")
	  {
		 string postfix = convertInfixToPostfix(input);
		 cout << convertPostfixToAssembly(postfix);
	  }
   } while (input != "quit");

}
