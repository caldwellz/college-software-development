/***********************************************************************
* Program:
*    Checkpoint 04a, Classes
*    Brother Barney, CS165
* Author:
*    Zachary Caldwell
* Summary: 
*    Weekly Checkpoint A
************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Book
{
   public:
      /******************************************************************
      * Prompt the user for a book title and author
      ******************************************************************/
      void prompt()
      {
         cout << "Title: ";
         getline(cin, title);
         cout << "Author: ";
         getline(cin, author);
      }

      /******************************************************************
      * Display a formatted book title and author
      ******************************************************************/
      void display()
      {
         cout << "\"" << title << "\" by " << author << endl;
      }

   private:
      string title;
      string author;
};

/***********************************************************************
* Program entry point.
************************************************************************/
int main()
{
   Book book;
   book.prompt();
   book.display();

   return 0;
}
