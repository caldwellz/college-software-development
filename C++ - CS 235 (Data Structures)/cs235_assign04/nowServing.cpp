/***********************************************************************
 * Implementation:
 *    NOW SERVING
 * Summary:
 *    This will contain the implementation for nowServing() as well as any
 *    other function or class implementations you may need
 * Author
 *    John Batty
 *    Jordon Thompson
 *    Brian Thompson
 *    Emmanuel Gatica
 *    Zach Caldwell
 **********************************************************************/

#include <iostream>     // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>       // for STRING
#include <cassert>      // for ASSERT
#include "nowServing.h" // for nowServing() prototype
#include "deque.h"      // for DEQUE
//#include <deque>
using custom::deque;
using std::cin;
using std::cout;

/************************************************
 * NOW SERVING
 * The interactive function allowing the user to
 * handle help requests in the Linux lab
 ***********************************************/
void nowServing()
{
   // instructions
   cout << "Every prompt is one minute.  The following input is accepted:\n";
   cout << "\t<class> <name> <#minutes>    : a normal help request\n";
   cout << "\t!! <class> <name> <#minutes> : an emergency help request\n";
   cout << "\tnone                         : no new request this minute\n";
   cout << "\tfinished                     : end simulation\n";

   deque<UserRequest> deck;
   UserRequest currentUser;
   currentUser.numMinutes = 0;
   string input;
   unsigned int minuteCounter = 0;

   while (true)
   {
      // Clear input buffer & display minute counter
      cin.clear();
      cin.ignore();
      cout << '<' << minuteCounter++ << "> ";
      cin >> input;

      // Process input
      if (input == "finished")
      { // All done
         cout << "End of simulation\n";
         return;
      }
      else if (input == "none")
      {
         // Do nothing, but we still want to process existing requests below,
         // so don't "continue" the loop either.
      }
      else
      { // Process any other input as a help request
         UserRequest r;
         if (input == "!!")
         {
            cin >> r.userClass;
            r.emergency = true;
         } else {
            r.userClass = input;
            r.emergency = false;
         }
         cin >> r.userName;
         cin >> r.numMinutes;

         if (input == "!!")
            deck.push_front(r);
         else
            deck.push_back(r);
      }

      // Update current user
      if (currentUser.numMinutes < 1)
      {
         if (!deck.empty())
         {
            currentUser = deck.front();
            deck.pop_front();
         }
      }

      // Process current help request
      if (currentUser.numMinutes > 0)
      {
         if (currentUser.emergency)
         {
            cout << "\tEmergency for " << currentUser.userName << " for class "
               << currentUser.userClass << ". Time left: "
               << currentUser.numMinutes << endl;
         } else {
            cout << "\tCurrently serving " << currentUser.userName << " for class "
               << currentUser.userClass << ". Time left: "
               << currentUser.numMinutes << endl;
         }
         currentUser.numMinutes--;
      }
   }
}
