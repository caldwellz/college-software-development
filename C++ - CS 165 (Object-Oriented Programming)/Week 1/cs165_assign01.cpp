/***********************************************************************
* Program:
*    Assignment 01, Genetic Genealogy
*    Brother Barney, CS165
* Author:
*    Zachary Caldwell
* Summary: 
*    Compare a DNA marker sequence from the user with ones from relatives
*    and display the match percentages.
*
*    Estimated:  1.0 hrs
*    Actual:     1.0 hrs
*      The hardest part was figuring out the best way to determine a
*      match percentage.
************************************************************************/

#include <iostream>
#include <string>
using namespace std;

/***********************************************************************
* Get the user's DNA marker sequence.
************************************************************************/
string getUserDNA()
{
   string sequence;

   cout << "Enter your DNA sequence: ";
   cin >> sequence;

   return sequence;
}

/***********************************************************************
* Get the number of potential relatives for matching.
************************************************************************/
unsigned int getPotentialRelatives()
{
   unsigned int relatives = 0;

   // relatives won't change until the user enters a valid number
   while (relatives == 0)
   {
      cout << "Enter the number of potential relatives: ";
      cin >> relatives;
   }

   return relatives;
}

/***********************************************************************
* Get a list of relative names from the user.
************************************************************************/
void getRelativeNames(int count, string relatives[])
{
   for (int i = 0; i < count; ++i)
   {
      cout << "Please enter the name of relative #" << (i + 1) << ": ";
      cin >> relatives[i];
   }
}

/***********************************************************************
* Get DNA sequences of relatives from the user.
************************************************************************/
void getRelativeDNA(int count, string relativeNames[], string relativeDNA[])
{
   for (int i = 0; i < count; ++i)
   {
      cout << "Please enter the DNA sequence for " << relativeNames[i] << ": ";
      cin >> relativeDNA[i];
   }
}

/***********************************************************************
* Calculate a DNA match percentage.
************************************************************************/
unsigned int calculateMatch(string userDNA, string relativeDNA)
{
   int len = (int)(userDNA.length() < relativeDNA.length() ?
                   userDNA.length() : relativeDNA.length());
   int matches = 0;
   double matchRatio = 0.0;

   for (int i = 0; i < len; ++i)
   {
      if (userDNA[i] == relativeDNA[i])
         matches++;
   }
   matchRatio = (double)matches / len;

   // Convert to a percentage
   return matchRatio * 100;
}

/***********************************************************************
* Display the match percentages of the DNA sequences.
************************************************************************/
void displayMatches(unsigned int count, string userDNA,
                    string relativeNames[], string relativeDNA[])
{
   for (int i = 0; i < (int)count; ++i)
   {
      cout << "Percent match for " << relativeNames[i] << ": "
           << calculateMatch(userDNA, relativeDNA[i]) << "%\n";
   }
}

/***********************************************************************
* Main entry point for the program.
************************************************************************/
int main()
{
   string userDNA;
   string *relativeNames;
   string *relativeDNA;
   unsigned int relatives;

   userDNA = getUserDNA();
   relatives = getPotentialRelatives();
   relativeNames = new string[relatives];
   relativeDNA = new string[relatives];
   cout << endl;

   getRelativeNames(relatives, relativeNames);
   cout << endl;
   getRelativeDNA(relatives, relativeNames, relativeDNA);
   cout << endl;

   displayMatches(relatives, userDNA, relativeNames, relativeDNA);
   delete[] relativeNames;
   delete[] relativeDNA;

   return 0;
}
