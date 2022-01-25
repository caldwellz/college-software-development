/***********************************************************************
 * Module:
 *    Week 10, WORD COUNT
 *    Brother Helfrich, CS 235
 * Author:
 *    Zach Caldwell
 * Summary:
 *    This program will implement the wordCount() function
 ************************************************************************/

#include "wordCount.h" // for wordCount() prototype
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// MAP include
#ifndef WCTEST
   #include "map.h"
   using namespace custom;
#else // WCTEST enables unit test if defined in special Makefile target
   #include <map>  
#endif

bool readFile(map <string, unsigned int> & counts, const string & fileName)
{
   // Make sure we can open the file
   ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "Error, unable to open file "
           << fileName
           << " for reading.\n";
      return false;
   }

   // Read the words
   string word;
   unsigned int readcount = 0;
   while (fin >> word)
   {
      counts[word] = counts[word] + 1;
      #ifdef WCTEST
         readcount++;
         if ((readcount % 10) == 0) cout << '.';
      #endif
   }

   // Debugging stats
   #ifdef WCTEST
      cout << endl << "Total words read from file: " << readcount
           << endl << "Size of map: " << counts.size() << endl;
   #endif

   fin.close();
   return true;
}

/*****************************************************
 * WORD COUNT
 * Prompt the user for a file to read, then prompt the
 * user for words to get the count from
 *****************************************************/
void wordCount()
{
   string input;

   // Create the word map
   map<string, unsigned int> counts;
   cout << "What is the filename to be counted? ";
   cin >> input;
   if(!readFile(counts, input)) return;

   // Get user words and display counts
   cout << "What word whose frequency is to be found. Type ! when done" << endl;
   while (true)
   {
      // Clear input buffer
      cin.clear();
      cin.ignore();

      // Get next word
      cout << "> ";
      cin >> input;
      if (input == "!") return;

      // Display the word count
      cout << '\t' << input << " : " << counts[input] << endl;
   }
}

// Independent main for unit testing wordCount separately
#ifdef WCTEST
int main(int argc, char const *argv[])
{
   wordCount();
   return 0;
}
#endif
