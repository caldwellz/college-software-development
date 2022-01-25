/***********************************************************************
* Program:
*    Assignment 05, Go Fish
 *    Brother JonesL, CS 235
* Author:
*    John Batty
*    Jordon Thompson
*    Brian Thompson
*    Emmanuel Gatica
*    Zach Caldwell
* Summary: 
*    This is all the functions necessary to play Go Fish!
************************************************************************/

#include <iostream>
#include <fstream>
#include "set.h"
#include "card.h"
#include "goFish.h"
using namespace std;

typedef custom::set<Card>::iterator cardIterator;


/**********************************************************************
 * Read Hand
 * Reads a hand of cards from a text file.
 ***********************************************************************/
custom::set<Card> readHand(char * file)
{
  //Open File
  ifstream fin(file);

  //Check for Errors
  if(fin.fail())
    throw "Could not open file.";
    
  custom::set<Card> output;
  char word[128];
    
  //Read the file until NULL character is reached.
  while(fin >> word)
  {
    output.insert(word);
  }

  //Close the File
  fin.close();
    
  return output;
}

/**********************************************************************
 * GO FISH
 * The function which starts it all
 ***********************************************************************/
void goFish()
{
   try
   {
    //Read Hand From File
    custom::set<Card> hand = readHand("/home/cs235/week05/hand.txt");
    

    cout << "We will play 5 rounds of Go Fish.  Guess the card in the hand" << endl;
    
    char input[128];
    int matchCount = 0;

    //Play 5 Rounds of Go Fish
    for(int round = 1;round <= 5;round++)
    {
      cout << "round " << round << ": ";
      cin >> input;                         //Get User Guess
      cardIterator loc = hand.find(input);  //Search Hand for User Input
    
      if(loc!=hand.end())   //If there was a match!
      {
        cout << "\tYou got a match!" << endl;
        matchCount++;
        hand.erase(loc);
      }
      else //If there was not a match.
      {
        cout << "\tGo Fish!" << endl;
      }
    }
      
    //Display Score
    cout << "You have " << matchCount << " matches!" << endl;
    
    //Display Hand
    cout << "The remaining cards: ";
    for (cardIterator it = hand.begin(); it < hand.end();it++)
    {
      if(it != hand.begin()) //Place a comma and a space before all except the first card in hand.
        cout << ", ";
      cout << *it;
    }
    cout << endl;

   }
   catch(const char * message)
   {
    cout << message << endl;
   }
}
