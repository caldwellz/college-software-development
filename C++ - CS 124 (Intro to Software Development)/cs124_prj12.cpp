/***********************************************************************
* Program:
*    Project 12, Sudoku
*    Brother Ridges, CS124
* Author:
*    Zachary Caldwell
* Summary: 
*    Load, play, and save a Sudoku puzzle.
*
*    Estimated:  2 hrs
*    Actual:     2.75 hrs
*      The hardest part was just getting all the whitespace and board
*      dividers working correctly.
************************************************************************/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int BOARD_LENGTH = 9;
const int BLOCK_LENGTH = 3;
const int MAX_FILENAME_SIZE = 256;

/****************************************************************************
 * Display the possible user options
 ****************************************************************************/
void displayOptions()
{
   cout << "Options:\n"
      << "   ?  Show these instructions\n"
      << "   D  Display the board\n"
      << "   E  Edit one square\n"
      << "   S  Show the possible values for a square\n"
      << "   Q  Save and Quit\n"
      << endl;
}

/****************************************************************************
 * Display the current state of the Sudoku board
 ****************************************************************************/
void displayBoard(int board[][BOARD_LENGTH])
{
   cout << "   A B C D E F G H I\n";

   for (int row = 0; row < BOARD_LENGTH; ++row)
   {
      // Add row divider if needed
      if (row > 0 && (row % BLOCK_LENGTH) == 0)
         cout << "   -----+-----+-----\n";

      cout << row + 1 << "  ";
      for (int col = 0; col < BOARD_LENGTH; ++col)
      {
         if (board[row][col] > 0)
            cout << board[row][col];
         else
            cout << ' ';

         // Handle spacing
         if ((col > 0) && col < (BOARD_LENGTH - 1)
                        && ((col + 1) % BLOCK_LENGTH) == 0)
            cout << '|';
         else if (col < BOARD_LENGTH - 1)
            cout << ' ';
      }
      cout << endl;
   }
}

/****************************************************************************
 * Get coordinates from the user and return whether they are valid
 ****************************************************************************/
bool getCoordinates(int &row, int &column, int board[][BOARD_LENGTH])
{
   char colChar;
   string rowString;

   // One of those rare times where the behavior of reading a single char
   // comes in handy...
   cout << "What are the coordinates of the square: ";
   cin >> colChar;
   cin >> rowString;

   // Do int conversions
   row = atoi(rowString.c_str()) - 1;
   colChar = toupper(colChar);
   column = colChar - 65;

   if (row < 0 || column < 0 || row >= BOARD_LENGTH || column >= BOARD_LENGTH)
   {
      cout << "ERROR: Square '" << colChar << rowString << "' is invalid\n";
      return false;
   }

   if (board[row][column] != 0)
   {
      cout << "ERROR: Square '" << colChar << rowString << "' is filled\n";
      return false;
   }

   return true;
}

/****************************************************************************
 * Edit a board square based on user input
 ****************************************************************************/
void editSquare(int board[][BOARD_LENGTH])
{
   int row;
   int column;
   int value;
   char colChar;

   if (!getCoordinates(row, column, board))
      return;

   colChar = column + 65;
   cout << "What is the value at '" << colChar << row + 1 << "': ";
   cin >> value;

   // TO DO: Validate value using computeValues
   board[row][column] = value;
}

/****************************************************************************
 * Carry out the game loop and interaction with the user.
 ****************************************************************************/
void interact(int board[][BOARD_LENGTH])
{
   displayOptions();
   displayBoard(board);

   bool done = false;
   char option = '-';
   while (!done)
   {
      cout << "\n> ";
      cin >> option;
      option = toupper(option);
      cin.ignore();

      switch (option)
      {
         case '?':
            displayOptions();
            break;
         case 'D':
            displayBoard(board);
            break;
         case 'E':
            editSquare(board);
            break;
         // TO DO: Add 'S' option here
         case 'Q':
            done = true;
            break;
         default:
            cout << "ERROR: Invalid command" << endl;
            break;
      }
   }
}

/****************************************************************************
 * Read a Sudoku board from a file
 ****************************************************************************/
bool readFile(int board[][BOARD_LENGTH])
{
   char filename[MAX_FILENAME_SIZE];
   ifstream fin;
   char symbol;

   cout << "Where is your board located? ";
   cin.getline(filename, MAX_FILENAME_SIZE);
   fin.open(filename);
   if (!fin.is_open())
   {
      cout << "Could not open input file!" << endl;
      return false;
   }

   int row = 0;
   int col = 0;
   while (fin >> symbol)
   {
      switch (symbol)
      {
         case '0':
         case '1':
         case '2':
         case '3':
         case '4':
         case '5':
         case '6':
         case '7':
         case '8':
         case '9':
            if (col == BOARD_LENGTH)
            {
               if (row == BOARD_LENGTH)
               {
                  cout << "Exceeded max board size!" << endl;
                  return false;
               }
               col = 0;
               row++;
            }
            // We know it's a valid digit from the case so just do a cheap
            // ASCII-to-int conversion. Wouldn't work for numbers > 9
            // but we don't have to worry about that for this project...
            board[row][col] = symbol - 48;
            col++;
         default: // Just skip any other characters
            continue;
      }
   }
   fin.close();

   // Make sure we have read a full board
   if ((row < BOARD_LENGTH - 1) || (col < BOARD_LENGTH))
   {
      cout << "Didn't read a full board!" << endl;
      return false;
   }

   return true;
}

/****************************************************************************
 * Write a Sudoku board to a file
 ****************************************************************************/
bool writeFile(int board[][BOARD_LENGTH])
{
   char filename[MAX_FILENAME_SIZE];
   ofstream fout;

   cout << "What file would you like to write your board to: ";
   cin.getline(filename, MAX_FILENAME_SIZE);
   fout.open(filename);
   if (!fout.is_open())
   {
      cout << "Could not open output file!" << endl;
      return false;
   }

   int row;
   int col;
   for (row = 0, col = 0; row < (BOARD_LENGTH - 1)
                        || col < BOARD_LENGTH; ++col)
   {
      if (col == BOARD_LENGTH)
      {
         row++;
         col = 0;
         // Back up and write a newline
         fout.seekp(-1, ios_base::cur);
         fout.put('\n');
      }

      fout << board[row][col] << ' ';
   }
   fout.seekp(-1, ios_base::cur);
   fout.put('\n');

   fout.close();
   cout << "Board written successfully\n";
   return true;
}

/***********************************************************************
 * Orchestrate the main logic of the program through delegation
 ***********************************************************************/
int main()
{
   int board[BOARD_LENGTH][BOARD_LENGTH];

   if (readFile(board))
   {
      interact(board);
      writeFile(board);
   }

   return 0;
}
