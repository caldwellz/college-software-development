/***********************************************************************
* Program:
*    Assignment 03, Digital Forensics (with corrupt files)
*    Brother Barney, CS165
* Author:
*    Zachary Caldwell
* Summary: 
*    Parse an access record file and display the entries that occurred
*    within a user-specified time frame, ignoring any corrupt lines.
*
*    Estimated:  1.0 hrs
*    Actual:     1.0 hrs
*      The hardest part was figuring out how to properly organize the main
*      while loop in parseFile.
************************************************************************/

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct AccessRecord
{
   string username;
   string filename;
   long long timestamp;
};

const unsigned int MAX_RECORDS = 500;

/***********************************************************************
* Parse an access record line into a structure.
************************************************************************/
void parseLine(string &line, AccessRecord &record)
{
   stringstream ss;
   ss.str(line);

   // Make sure all expected data is at least readable
   if ((ss >> record.filename) && (ss >> record.username)
      && (ss >> record.timestamp))
   {
      // Verify the timestamp is within range
      if (record.timestamp >= 1000000000 && record.timestamp <= 10000000000)
      {
         // Passed all tests
         return;
      }
   }

   // If we haven't returned already, must have had an error somewhere
   string error("Error parsing line: ");
   error.append(line);
   throw error;
}

/***********************************************************************
* Parse an access record file into an array, line by line.
************************************************************************/
unsigned int parseFile(string &filename, AccessRecord records[])
{
   ifstream log;
   string line;
   unsigned int i = 0;

   log.open(filename.c_str());

   while (true)
   {
      getline(log, line);
      if (log.fail())
         break;

      try
      {
         parseLine(line, records[i]);
      }
      catch (string error)
      {
         cout << error << endl;
         continue;
      }

      i++;
      if (i >= MAX_RECORDS)
         break;
   }

   log.close();
   return i;
}

/***********************************************************************
* Display a single access record.
************************************************************************/
void displayRecord(AccessRecord &record)
{
   cout << setw(15) << record.timestamp << setw(20) << record.filename
        << setw(20) << record.username << endl;
}

/***********************************************************************
* Match and display access records from within the given timestamp bounds.
************************************************************************/
void matchRecords(AccessRecord records[], unsigned int nRecords,
                  long long start, long long end)
{
   cout << "\nThe following records match your criteria:\n\n"
        << "      Timestamp                File                User\n"
        << "--------------- ------------------- -------------------\n";

   for (unsigned int i = 0; i < nRecords; ++i)
   {
      if ((records[i].timestamp >= start) && (records[i].timestamp <= end))
         displayRecord(records[i]);
   }
   cout << "End of records\n";
}

/***********************************************************************
* Get the name of an access record file from the user.
************************************************************************/
string getFilename()
{
   string filename;
   cout << "Enter the access record file: ";
   cin >> filename;

   return filename;
}

/***********************************************************************
* Main entry point for the program.
************************************************************************/
int main()
{
   AccessRecord records[MAX_RECORDS];
   unsigned int numRecords;
   long long startTime;
   long long endTime;
   string filename;

   filename = getFilename();
   numRecords = parseFile(filename, records);
   cout << "\nEnter the start time: ";
   cin >> startTime;
   cout << "Enter the end time: ";
   cin >> endTime;
   matchRecords(records, numRecords, startTime, endTime);

   return 0;
}
