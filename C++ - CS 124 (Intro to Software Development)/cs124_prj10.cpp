/***********************************************************************
* Program:
*    Project 10, MadLib
*    Brother Ridges, CS124
* Author:
*    Zachary Caldwell
* Summary: 
*    Play a looping game of MadLib with the user.
*
*    Estimated:  20 min
*    Actual:      1 hr
*      The hardest part was figuring out why the next file wouldn't open
*      on a replay.
************************************************************************/

#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

const int MAX_FILENAME_LENGTH = 256;
const int MAX_OUTPUT_LENGTH = 2048;
const int MAX_LINE_LENGTH = 80;
const int MAX_FILE_LINES = 32;
const int MAX_QUESTION_LENGTH = MAX_LINE_LENGTH - 2;
const int MAX_USER_INPUT_LENGTH = 64;

/****************************************************************************
 * Format a question, display it, and then insert the response into the story.
 ****************************************************************************/
void askQuestion(char question[], char buffer[], int &bufferPos)
{
   // Convert question to be more user friendly if needed (sentence case,
   // replace underscores with spaces)
   for (int i = 0; (i < MAX_QUESTION_LENGTH) && (question[i]); ++i)
   {
      if ((i == 0) && (question[i] >= 'a') && (question[i] <= 'z'))
         question[i] -= 32;
      else if (question[i] == '_')
         question[i] = ' ';
   }

   // Prompt for a response
   char userResponse[MAX_USER_INPUT_LENGTH];
   cout << '\t' << question << ": ";
   cin.getline(userResponse, MAX_USER_INPUT_LENGTH);

   // Copy the response to the output buffer
   for (int i = 0; (i < MAX_USER_INPUT_LENGTH) && (userResponse[i]); ++i)
   {
      // Make sure we haven't run out of buffer space
      if ((bufferPos) >= MAX_OUTPUT_LENGTH)
      {
         cerr << "Exhausted output buffer space!" << endl;
         exit(1);
      }

      buffer[bufferPos] = userResponse[i];
      bufferPos++;
   }

   // Add a space at the end
   buffer[bufferPos] = ' ';
   bufferPos++;
}

/****************************************************************************
 * Parse control tokens (passing questions to askQuestion) and update the
 * given line position and buffer position.
 ****************************************************************************/
void parseToken(char line[], int &linePos, char buffer[], int &bufferPos)
{
   switch (line[ ++linePos ])
   {
      case '{':
         buffer[bufferPos] = '\"';
         bufferPos++;
         break;
      case '}':
         // Overwrite any preceding spaces before the token
         for (; buffer[bufferPos - 1] == ' '; --bufferPos);
         buffer[bufferPos] = '\"';
         buffer[ ++bufferPos ] = ' ';
         bufferPos++;
         break;
      case '[':
         buffer[bufferPos] = '\'';
         bufferPos++;
         break;
      case ']':
         // Overwrite any preceding spaces before the token
         for (; buffer[bufferPos - 1] == ' '; --bufferPos);
         buffer[bufferPos] = '\'';
         buffer[ ++bufferPos ] = ' ';
         bufferPos++;
         break;
      case '#':
         // Don't need a space right before a newline
         if (buffer[bufferPos - 1] == ' ')
            bufferPos--;
         buffer[bufferPos] = '\n';
         bufferPos++;
         break;
      default:
         // If it's not a control char, must be part of a question
         // Extract questions but let askQuestion format them
         char question[MAX_QUESTION_LENGTH];
         int qPos;
         for (qPos = 0; (linePos < MAX_LINE_LENGTH) && (line[linePos] != '>')
                      && (qPos < MAX_QUESTION_LENGTH); ++linePos, ++qPos)
         {
            question[qPos] = line[linePos];
         }
         question[qPos] = '\0';
         askQuestion(question, buffer, bufferPos);
   }

   // Skip to the end of the token. Could just do a -- under default and then
   // a ++ here to handle all current cases, but this is the safer way...
   for (; (linePos < MAX_LINE_LENGTH) && (line[linePos] != '>'); ++linePos);

   // Skip any space after the token too (it'll be added in switch if needed)
   if ((linePos + 1 < MAX_LINE_LENGTH) && (line[linePos + 1] == ' '))
      linePos++;
}

/****************************************************************************
 * Read from the given MadLib filename and put the completed story into the
 * output buffer.
 ****************************************************************************/
void readFile(char filename[], char outputBuffer[])
{
   ifstream fin;
   fin.open(filename);
   if (!fin.is_open())
   {
      cerr << "Could not open file: " << filename << endl;
      exit(1);
   }

   char line[MAX_LINE_LENGTH];
   int lineCount = 0;
   int outputPos = 0;
   // Fetch lines until we either reach the file's end or hit the max below
   while (fin.getline(line, MAX_LINE_LENGTH))
   {
      lineCount++;
      if (lineCount > MAX_FILE_LINES)
      {
         cerr << "Too many lines in file, not handling unlimited length..."
              << endl;
         exit(1);
      }

      // Assume we need a space after each file newline unless we actually
      // output a newline or space already
      if ((lineCount > 1) && (outputBuffer[outputPos - 1] != '\n')
                          && (outputBuffer[outputPos - 1] != ' '))
      {
         outputBuffer[outputPos] = ' ';
         outputPos++;
      }

      // Process the line
      for (int n = 0; (n < MAX_LINE_LENGTH) && (line[n] != '\0'); ++n)
      {
         if (outputPos >= MAX_OUTPUT_LENGTH)
         {
            cerr << "Exhausted output buffer space!" << endl;
            exit(1);
         }

         // Check for control tokens and those silly cases where there's just
         // a punctuation mark floating out awkwardly all by itself...
         switch (line[n])
         {
            case '<':
               parseToken(line, n, outputBuffer, outputPos);
               continue;
            case '.':
            case ',':
            case '!':
            case '?':
               if (outputBuffer[outputPos - 1] == ' ')
               {
                  outputBuffer[outputPos - 1] = line[n];
                  break;
               }
            default:
               // Assume a normal word and copy the character over
               outputBuffer[outputPos] = line[n];
               outputPos++;
         }
      }
   }

   // Clean up
   outputBuffer[outputPos] = '\0';
   fin.close();
}

/****************************************************************************
 * Get a MadLib filename from the user.
 ****************************************************************************/
void askFilename(char filename[])
{
   cout << "Please enter the filename of the Mad Lib: ";
   cin.getline(filename, MAX_FILENAME_LENGTH);
}

/****************************************************************************
 * Ask the user if they want to play again and return the result.
 ****************************************************************************/
bool askPlayAgain()
{
   char answer;
   cout << "Do you want to play again (y/n)? ";
   cin >> answer;
   cin.ignore();

   // Lowercase it if needed
   if (answer < 'a')
      answer += 32;

   // Assume anything besides a yes is a no
   if (answer == 'y')
      return true;

   return false;
}

/**********************************************************************
 * Orchestrate the main logic of the program through delegation.
 ***********************************************************************/
int main()
{
   char filename[MAX_FILENAME_LENGTH];
   char outputBuffer[MAX_OUTPUT_LENGTH];

   do
   {
      askFilename(filename);
      readFile(filename, outputBuffer);
      cout << endl << outputBuffer << endl;
   } while (askPlayAgain());
   cout << "Thank you for playing." << endl;

   return 0;
}
