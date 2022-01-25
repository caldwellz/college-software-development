/***********************************************************************
* Program:
*    Assignment 02, Digital Forensics
*    Brother Barney, CS165
* Author:
*    Zachary Caldwell
* Summary: 
*    Parse an access record file and display the entries that occurred
*    within a user-specified time frame.
*
*    Estimated:  1.5 hrs
*    Actual:     1.0 hrs
*      The hardest part was deciding how to best divide tasks, finally
*      settling with matchRecords and displayRecord.
************************************************************************/

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct AccessRecord
{
   string username;
   string filename;
   long timestamp;
};

const unsigned int MAX_RECORDS = 500;

/***********************************************************************
* Get the name of an access record file from the user and parse it into
* an array.
************************************************************************/
long readRecords(AccessRecord records[])
{
   string logFilename;
   ifstream log;
   long i = 0;

   cout << "Enter the access record file: ";
   cin >> logFilename;
   log.open(logFilename.c_str());

   while ((log >> records[i].filename) && (log >> records[i].username)
       && (log >> records[i].timestamp))
   {
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
void matchRecords(AccessRecord records[], long nRecords, long start, long end)
{
   cout << "\nThe following records match your criteria:\n\n"
        << "      Timestamp                File                User\n"
        << "--------------- ------------------- -------------------\n";

   for (int i = 0; i < nRecords; ++i)
   {
      if ((records[i].timestamp >= start) && (records[i].timestamp <= end))
         displayRecord(records[i]);
   }
   cout << "End of records\n";
}

/***********************************************************************
* Main entry point for the program.
************************************************************************/
int main()
{
   AccessRecord records[MAX_RECORDS];
   long numRecords;
   long startTime;
   long endTime;

   numRecords = readRecords(records);
   cout << "\nEnter the start time: ";
   cin >> startTime;
   cout << "Enter the end time: ";
   cin >> endTime;
   matchRecords(records, numRecords, startTime, endTime);

   return 0;
}
