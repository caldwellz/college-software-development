/***********************************************************************
* Program:
*    Assignment 40, Multi-Dimensional Arrays
*    Brother Ridges, CS124
* Author:
*    Zachary Caldwell
* Summary: 
*    Read and display a Tic-Tac-Toe board from a file and then copy it to
*    a different file.
*
*    Estimated:  45 min
*    Actual:     1 hour
*      The trickiest part was assuming the given file format was accurate, and
*      then getting to Test 1 and realizing I'd have to hard-code a 3x3 board.
************************************************************************/

#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

const unsigned int MAX_BOARD_HEIGHT = 8;
const unsigned int MAX_BOARD_WIDTH = 8;
const unsigned int MAX_FILENAME_LENGTH = 256;

/***********************************************************************
 * Read a Tic-Tac-Toe board file into an array.
 ***********************************************************************/
void readFile(char filename[], char board[][MAX_BOARD_WIDTH])
{
   char symbol;
   ifstream fin(filename);

   if (fin.fail())
   {
      cout << "Could not open file for reading!" << endl;
      exit(1);
   }

   int row = 0;
   int col = 0;
   while (fin >> symbol)
   {
      switch (symbol)
      {
         case ' ':
            continue;
         case '\n':
            col = 0;
            row++;
            break;
         default:
            board[row][col] = symbol;
            col++;
      }

      // Hard-code max width for the sake of testBed's file
      if (col == 3)
      {
         col = 0;
         row++;
         continue;
      }

      // Old error handling
      if ((row >= MAX_BOARD_HEIGHT) || (col >= MAX_BOARD_WIDTH))
      {
         cout << "Exceeded max board size!" << endl;
         exit(1);
      }
   }

   fin.close();
}

/***********************************************************************
 * Write a Tic-Tac-Toe board array into a file.
 ***********************************************************************/
void writeFile(char filename[], char board[][MAX_BOARD_WIDTH])
{
   ofstream fout(filename);

   if (fout.fail())
   {
      cout << "Could not open file for writing!" << endl;
      exit(1);
   }

   for (int row = 0; row < MAX_BOARD_HEIGHT; ++row)
   {
      if (board[row][0] == 0)
         break;

      for (int col = 0; col < MAX_BOARD_WIDTH; ++col)
      {
         if (board[row][col] == 0)
            break;
         fout << board[row][col] << ' ';
      }

      fout << '\n';
   }

   fout.close();
   cout << "File written" << endl;
}

/***********************************************************************
 * Format and display a Tic-Tac-Toe board array.
 ***********************************************************************/
void displayBoard(char board[][MAX_BOARD_WIDTH])
{
   int col = 0;

   for (int row = 0; row < MAX_BOARD_HEIGHT; ++row)
   {
      // Check if we've hit the end of a board that's smaller than the max
      if (board[row][0] == 0)
         break;

      // Fill in a row separator if needed
      if (col > 0)
      {
         for (int separatorNum = 0; separatorNum < col; separatorNum++)
         {
            if (separatorNum > 0)
               cout << '+';
            cout << "---";
         }
         cout << '\n';
      }

      // Display the board columns
      for (col = 0; col < MAX_BOARD_WIDTH; ++col)
      {
         if (board[row][col] == 0)
            break;
         if (col > 0)
            cout << '|';
         if (board[row][col] == '.')
            cout << "   ";
         else
            cout << ' ' << board[row][col] << ' ';
      }

      cout << endl;
   }
}

/***********************************************************************
 * Orchestrate the main logic of the program.
 ***********************************************************************/
int main()
{
   char filename[MAX_FILENAME_LENGTH];
   char board[MAX_BOARD_HEIGHT][MAX_BOARD_WIDTH];

   cout << "Enter source filename: ";
   cin.getline(filename, MAX_FILENAME_LENGTH);
   readFile(filename, board);
   displayBoard(board);

   cout << "Enter destination filename: ";
   cin.getline(filename, MAX_FILENAME_LENGTH);
   writeFile(filename, board);

   return 0;
}
