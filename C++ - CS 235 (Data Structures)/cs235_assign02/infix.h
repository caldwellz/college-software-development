/***********************************************************************
* Header:
*    INFIX
* Summary:
*    This will contain just the prototype for the convertInfixToPostfix()
*    function
* Author
*    Brian Thompson
*    Zach Caldwell
*    John Batty
*    Jordon Thompson
************************************************************************/

#include <string>
#include <sstream>
using namespace std;

#ifndef INFIX_H
#define INFIX_H

/**********************************************************************
 * Function: isOp
 * Purpose: Determines if the input string is an operation (i.e. +,-,*,/,etc.)
 *	and returns an integer representing it's order of operation. Larger int
 *	means higher order. Returns 0 if it is not an operation.
 ***********************************************************************/
int isOp(string input);

/**********************************************************************
 * Function: prep
 * Purpose: Prepares the input by makeing certain all valid operations
 *  are seperated by a space
 ***********************************************************************/
string prep(string input);

/**********************************************************************
 * Function: postfixEval
 * Purpose: Takes an infix formatted input as a string stream and
 *   evaluates the stream recursively. Returns a postfix formated string
 ***********************************************************************/
string postfixEval(stringstream & ss);

/**********************************************************************
 * Function: opToAsm
 * Purpose: returns the assembly opcode for an operation
 ***********************************************************************/
string opToAsm(string input);

/*****************************************************
 * TEST INFIX TO POSTFIX
 * Prompt the user for infix text and display the
 * equivalent postfix expression
 *****************************************************/
void testInfixToPostfix();

/*****************************************************
 * TEST INFIX TO ASSEMBLY
 * Prompt the user for infix text and display the
 * resulting assembly instructions
 *****************************************************/
void testInfixToAssembly();

#endif // INFIX_H

