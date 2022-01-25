/***********************************************************************
 * Module:
 *    Assignment 12, Spell Check
 *    Brother Helfrich, CS 235
 * Author:
 *    John Batty
 *    Jordon Thompson
 *    Brian Thompson
 *    Emmanuel Gatica
 *    Zach Caldwell
 * Summary:
 *    This program will implement the spellCheck() function
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <cctype>
#include "spellCheck.h"
#include "hash.h"
#include "bst.h"
using namespace std;

/****************************************
 * STR HASH
 * A simple string hash
 ****************************************/
class StrHash : public custom::Hash <string>
{
public:
   StrHash(int numBuckets)      : Hash <string> (numBuckets) {}
   StrHash(const StrHash & rhs) : Hash <string> (rhs)        {}
   
   int hash(const string & value) const
   {
      int seed = 139; //random arbitrary starting seed. Must be odd.
      unsigned long hash = 0;
      for(int i = 0; i < value.length(); i++)
      {
         hash = (hash * seed) + value[i];
      }
      return hash % numBuckets;
   }
};

/*****************************************
 * SPELL CHECK
 * Prompt the user for a file to spell-check
 ****************************************/
void spellCheck()
{
   // After significant testing, determined that this yelided the
   // most favorable maximum bucket size to empty bucket ratio.
   // Under this implimentation, almost all buckets have less than 3 items.
   int buckets = 2001;
   StrHash table(buckets);

   // If we're on the Linux lab, get the dictionary from the CS235 home folder
#ifdef __unix__
   ifstream dictfile("/home/cs235/week12/dictionary.txt");
#else // Otherwise get it from the current directory
   ifstream dictfile("dictionary.txt");
#endif

   // Verify the dictionary was opened successfully
   if (dictfile.fail())
   {
      cout << "Error, unable to open dictionary for reading.\n";
      return;
   }

   // Read it into the table; dictionary is already all lowercase
   string line;
   while (getline(dictfile, line))
   {
      table.insert(line);
   }
   dictfile.close();

   /*// Debugging stats
   cout << "DEBUG: Filled dictionary, bucket size: " << buckets << endl;
   table.display();
   */

   // Open the user file for checking
   string userFilename;
   cout << "What file do you want to check? ";
   cin >> userFilename;
   ifstream userfile(userFilename);
   if (userfile.fail())
   {
      cout << "Error, unable to open user file for spell-checking.\n";
      return;
   }

   // Check each word, and if not found add it to a sorted list (BST) for alphabetical display
   string word, lcWord;
   custom::BST<string> invalidWords;
   while (userfile >> word)
   {
      // Lowercase the first letter since the dictionary words are all lowercase
      lcWord = word;
      lcWord[0] = tolower(lcWord[0]);
 
      if (!table.find(lcWord))
         invalidWords.insert(word);
   }

   // Display results
   if (invalidWords.empty())
   {
      assert(invalidWords.size() == 0);
      cout << "File contains no spelling errors\n";
   } else {
      cout << "Misspelled: ";
      custom::BST<string>::iterator it;
      for (it = invalidWords.begin(); it != invalidWords.end(); ++it)
         if (it == invalidWords.begin())
            cout << *it;
         else
            cout << ", " << *it;
      cout << endl;
   }
}
