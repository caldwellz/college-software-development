/***********************************************************************
 * Implementation:
 *    STOCK
 * Summary:
 *    This will contain the implementation for stocksBuySell() as well
 *    as any other function or class implementation you need
 * Author
 *    John Batty
 *    Jordon Thompson
 *    Brian Thompson
 *    Zach Caldwell
 **********************************************************************/

#include <iostream>    // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>      // for STRING
#include <sstream>     // for STRINGSTREAM
#include <cassert>     // for ASSERT
#include <cstdlib>       // for atoi()
#include "stock.h"     // for STOCK_TRANSACTION
#include "queue.h"     // for QUEUE
using namespace std;

/************************************************
 * Portfolio :: Display Currently Held
 * Displays the contents of the Currently Held Queue
 * listing quantities held and buy prices.
 ***********************************************/
void Portfolio::displayCurrentlyHeld()
{
   custom::queue<Stock> temp = currentlyHeld;
   while(!temp.empty())
   {
      cout << "\tBought " << temp.front().numShares
           << " shares at " << temp.front().buyPrice << endl;
      temp.pop();
   }
}

/************************************************
 * Portfolio :: Display Sell History
 * Displays the contents of the Sell History Queue
 * listing quantities sold and net profits.
 ***********************************************/
void Portfolio::displaySellHistory()
{
   custom::queue<Stock> temp = sellHistory;
   Dollars profit;
   Dollars totalProfit;
    
   while(!temp.empty())
   {
      profit = (temp.front().sellPrice - temp.front().buyPrice)
         * temp.front().numShares;
      totalProfit += profit;
        
      cout << "\tSold " << temp.front().numShares
           << " shares at " << temp.front().sellPrice
           << " for a profit of " << profit << endl;
        
      temp.pop();
   }   
   cout << "Proceeds: " << totalProfit << endl;    
}

/************************************************
 * Portfolio :: Buy
 * Adds a Stock Batch to the Currently Held Queue.
 ***********************************************/
void Portfolio::buy(int numStocks, Dollars &price)
{   
   Stock s;
   s.buyPrice = price;
   s.numShares = numStocks;
   currentlyHeld.push(s);
    
   //Previous Method
   /*
     for (int i = 0; i < numStocks; ++i) {
     Stock s;
     s.buyPrice = price;
     currentlyHeld.push(s);
     }
   */
}

/************************************************
 * Portfolio :: Sell
 * Removes a Stock Batch from the Currently Held Queue
 * and adds it to the Sell History Queue.
 ***********************************************/
void Portfolio::sell(int numStocks, Dollars &price)
{    
   while (numStocks)
      if (numStocks >= currentlyHeld.front().numShares)
      {
         Stock s;
         s.buyPrice = currentlyHeld.front().buyPrice;
         s.sellPrice = price;
         s.numShares = currentlyHeld.front().numShares;
            
         currentlyHeld.pop();
         sellHistory.push(s);
            
         numStocks -= s.numShares;            
      }
      else if (numStocks < currentlyHeld.front().numShares)
      {
         Stock s;
         currentlyHeld.front().numShares -= numStocks;
         s.buyPrice = currentlyHeld.front().buyPrice;
         s.sellPrice = price;
         s.numShares = numStocks;
         sellHistory.push(s);
            
         numStocks = 0;
      }
    
   //Previous Method
   /*
     /for (int i = 0; (i < numStocks) && !(currentlyHeld.empty()); ++i) {
     Stock s = currentlyHeld.pop();
     s.sellPrice = price;
     sellHistory.push(s);
     }
   */
}

/************************************************
 * Portfolio :: Display
 * Calls display functions to show currently held assets,
 * sell history, and net profits.
 ***********************************************/
void Portfolio::display()
{
   if (!currentlyHeld.empty())
   {
      cout << "Currently held:" << endl;
      displayCurrentlyHeld();
   }
    
   if (!sellHistory.empty())
      cout << "Sell History:" << endl;
    
   displaySellHistory();
}

/************************************************
 * STOCKS BUY SELL
 * The interactive function allowing the user to
 * buy and sell stocks
 ***********************************************/
void stocksBuySell()
{
   // instructions
   cout << "This program will allow you to buy and sell stocks. "
        << "The actions are:\n";
   cout << "  buy 200 $1.57   - Buy 200 shares at $1.57\n";
   cout << "  sell 150 $2.15  - Sell 150 shares at $2.15\n";
   cout << "  display         - Display your current stock portfolio\n";
   cout << "  quit            - Display a final report and quit the program\n";
    
   Portfolio p;
   string input;
    
   while (true)
   {        
      cin.clear();
      cin.ignore();
      cout << "> ";
      cin >> input;
        
      if (input == "quit")
      {
         break;
      }
        
      else if (input == "display")
      {
         p.display();
         continue;
      }
        
      else if (input == "buy")
      {
         int numShares;
         cin >> numShares;
            
         Dollars value;
         cin >> value;
            
         p.buy(numShares, value);
         continue;
      }
        
      else if (input == "sell")
      {
         int numShares;
         cin >> numShares;
            
         Dollars value;
         cin >> value;
            
         p.sell(numShares, value);
         continue;
      }
        
      else
      {
         cout << "Invalid input" << endl;
         continue;
      }        
   }    
}
