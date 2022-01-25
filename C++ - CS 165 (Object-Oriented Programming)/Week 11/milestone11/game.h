/*********************************************************************
 * File: game.h
 * Description: Defines the main game class
 *********************************************************************/

#ifndef GAME_H
#define GAME_H

#include <vector>

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"
#include "bullet.h"
#include "ship.h"
#include "rocks.h"

#define CLOSE_ENOUGH 15
const unsigned int OFF_SCREEN_BORDER_AMOUNT = 5;
const unsigned int START_BIG_ASTEROIDS = 5;

/*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
class Game
{
public:
   /*********************************************
    * Constructor
    * Initializes the game
    *********************************************/
   Game(Point tl, Point br);
   ~Game();
   
   /*********************************************
    * Function: handleInput
    * Description: Takes actions according to whatever
    *  keys the user has pressed.
    *********************************************/
   void handleInput(const Interface & ui);
   
   /*********************************************
    * Function: advance
    * Description: Move everything forward one
    *  step in time.
    *********************************************/
   void advance();
   
   /*********************************************
    * Function: draw
    * Description: draws everything for the game.
    *********************************************/
   void draw(const Interface & ui);
   
private:
   // The coordinates of the screen
   Point topLeft;
   Point bottomRight;
   
   int score;
   
   Ship ship;
   std::vector<Bullet> bullets;
   std::vector<Rock*> asteroids;


   /*************************************************
    * Private methods to help with the game logic.
    *************************************************/
   void checkWrap(FlyingObject *obj);
   void advanceBullets();
   void advanceRocks();
   void advanceShip();
   void createRocks();
   void breakRock(Rock* aster);
   float getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const;
   
   void handleCollisions();
   void cleanUpZombies();
};

#endif /* GAME_H */
