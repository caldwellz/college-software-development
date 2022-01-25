/***********************************************************************
* Program:
*    Checkpoint 08a, Inheritance
*    Brother Barney, CS165
* Author:
*    Zachary Caldwell
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Book
{
   public:
      void promptBookInfo()
      {
         cout << "Title: ";
         getline(cin, this->title);
         cout << "Author: ";
         getline(cin, this->author);
         cout << "Publication Year: ";
         cin >> this->publicationYear;
         cin.ignore(500, '\n');
      }

      void displayBookInfo()
      {
         cout << endl << this->title << " (" << this->publicationYear
              << ") by " << this->author << endl;
      }

   protected:
      string title;
      string author;
      unsigned short publicationYear;
};

class TextBook: public Book
{
   public:
      void promptSubject()
      {
         cout << "Subject: ";
         getline(cin, this->subject);
      }

      void displaySubject()
      {
         cout << "Subject: " << this->subject << endl;
      }

   protected:
      string subject;
};

class PictureBook: public Book
{
   public:
      void promptIllustrator()
      {
         cout << "Illustrator: ";
         getline(cin, this->illustrator);
      }

      void displayIllustrator()
      {
         cout << "Illustrated by " << this->illustrator << endl;
      }

      // Just because I feel like unnecessarily complicating things for myself
      void promptBookInfo()
      {
         this->Book::promptBookInfo();
         this->promptIllustrator();
      }

      // Ditto
      void displayBookInfo()
      {
         this->Book::displayBookInfo();
         this->displayIllustrator();
      }

   protected:
      string illustrator;
};

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   Book book;
   book.promptBookInfo();
   book.displayBookInfo();
   cout << endl;

   TextBook textbook;
   textbook.promptBookInfo();
   textbook.promptSubject();
   textbook.displayBookInfo();
   textbook.displaySubject();
   cout << endl;

   PictureBook picturebook;
   picturebook.promptBookInfo();
   picturebook.displayBookInfo();

   return 0;
}
