/***********************************************************************
 * Header:
 *    STOCK
 * Summary:
 *    This will contain just the prototype for stocksBuySell(). You may
 *    want to put other class definitions here as well.
 * Author
 *    John Batty
 *    Jordon Thompson
 *    Brian Thompson
 *    Zach Caldwell
 ************************************************************************/

#ifndef STOCK_H
#define STOCK_H

#include "dollars.h"   // for Dollars defined in StockTransaction
#include "queue.h"     // for QUEUE
#include <iostream>    // for ISTREAM and OSTREAM

struct Stock
{
   Dollars buyPrice;
   Dollars sellPrice;
   int numShares;
   Stock():
   buyPrice(0),
   sellPrice(0),
   numShares(0)
   { }
};

// the interactive stock buy/sell function
void stocksBuySell();

class Portfolio
{    
  private:
   custom::queue<Stock> currentlyHeld;
   custom::queue<Stock> sellHistory;
   void displayCurrentlyHeld();
   void displaySellHistory();
    
  public:
   void buy(int numStocks, Dollars &price);
   void sell(int numStocks, Dollars &price);
   void display();    
};

#endif // STOCK_H


