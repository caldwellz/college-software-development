/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementation of the game class
 *  methods.
 *
 *********************************************************************/

#include "game.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"

#include <vector>
// These are needed for the getClosestDistance function
#include <limits>
#include <algorithm>
// Needed for angle/speed to velocity conversions
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;


/***************************************
 * GAME CONSTRUCTOR
 ***************************************/
Game :: Game(Point tl, Point br)
 : topLeft(tl), bottomRight(br), score(0)
{ }

/****************************************
 * GAME DESTRUCTOR
 ****************************************/
Game :: ~Game()
{
   // Clean up remaining asteroids
   for (int i = 0; i < asteroids.size(); i++)
   {
      delete asteroids[i];
   }
}

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
   advanceBullets();
   advanceRocks();
   advanceShip();

   handleCollisions();
   cleanUpZombies();
}

/***************************************
 * GAME :: ADVANCE BULLETS
 * Go through each bullet and advance it.
 ***************************************/
void Game :: advanceBullets()
{
   // Move each bullet if it is alive
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         // this bullet is alive, so tell it to move forward
         bullets[i].advance();
         
         // Wrap it around to the other side if needed
         checkWrap(&bullets[i]);
      }
   }
}

/**************************************************************************
 * GAME :: ADVANCE ASTEROIDS
 *
 * 1. If there are no asteroids, create a new set, as at game start
 * 2. If there are asteroids, and they're alive, advance them
 * 3. Check if each asteroid has gone off the screen, and if so, wrap it around
 **************************************************************************/
void Game :: advanceRocks()
{
   if (asteroids.size() == 0)
   {
      createRocks();
   }
   else // Don't need to do the other checks if they've just been created
   {
      // Make sure each asteroid is alive
      for (int i = 0; i < asteroids.size(); i++)
      {
         if (asteroids[i]->isAlive())
         {
            // move it forward
            asteroids[i]->advance();
            
            // Wrap it around to the other side if needed
            checkWrap(asteroids[i]);
         }
      }
   }
}

/**************************************************************************
 * GAME :: ADVANCE SHIP
 * Advance the ship per game rules if it is alive
 **************************************************************************/
void Game::advanceShip()
{
   if (ship.isAlive())
   {
      ship.advance();
      checkWrap(&ship);
   }
}

/**************************************************************************
 * GAME :: CREATE ASTEROIDS
 * Create a new set of large asteroids.
 **************************************************************************/
void Game::createRocks()
{
   Rock* newRock = NULL;
   Velocity asterVel;
   Point asterPt;
   int angle;

   for (int i = 0; i < START_BIG_ASTEROIDS; ++i)
   {
      // Generate a random position and angle
      // TODO: Use an appropriate buffer around the ship to prevent insta-kill
      asterPt.setX(random(-190, 190));
      asterPt.setY(random(-190, 190));
      angle = random(0, 360);

      // Convert the angle and speed into a velocity
      asterVel.setDx(ROCK_SPEED * (-cos(M_PI / 180.0 * angle)));
      asterVel.setDy(ROCK_SPEED * (sin(M_PI / 180.0 * angle)));

      // Create a new large asteroid, set the variables, and add it in
      newRock = new BigRock;
      newRock->setPoint(asterPt);
      newRock->setVelocity(asterVel);
      newRock->setAngle(angle);
      asteroids.push_back(newRock);
   }
}

/**************************************************************************
 * GAME :: BREAK ASTEROID
 * Break a large / medium asteroid into smaller ones (or do nothing if small)
 * TODO: STUB function
 **************************************************************************/
void Game::breakRock(Rock* aster)
{
   
}

/**************************************************************************
 * GAME :: Check Wrap
 * Wrap a FlyingObject to the other side of the screen if needed
 **************************************************************************/
void Game::checkWrap(FlyingObject *obj)
{
   Point point = obj->getPoint();
   bool pointChanged = false;

   if (point.getX() < topLeft.getX() - OFF_SCREEN_BORDER_AMOUNT) {
      point.setX(bottomRight.getX() + OFF_SCREEN_BORDER_AMOUNT);
      pointChanged = true;
   }
   if (point.getX() > bottomRight.getX() + OFF_SCREEN_BORDER_AMOUNT) {
      point.setX(topLeft.getX() - OFF_SCREEN_BORDER_AMOUNT);
      pointChanged = true;
   }
   if (point.getY() < bottomRight.getY() - OFF_SCREEN_BORDER_AMOUNT) {
      point.setY(topLeft.getY() + OFF_SCREEN_BORDER_AMOUNT);
      pointChanged = true;
   }
   if (point.getY() > topLeft.getY() + OFF_SCREEN_BORDER_AMOUNT) {
      point.setY(bottomRight.getY() - OFF_SCREEN_BORDER_AMOUNT);
      pointChanged = true;
   }

   if(pointChanged)
      obj->setPoint(point);
}

/**************************************************************************
 * GAME :: HANDLE COLLISIONS
 * Check for a collision between an asteroid and a bullet or the ship.
 * TODO: STUB function
 **************************************************************************/
void Game :: handleCollisions()
{
/*
   // Somewhere in here, when killing big/medium asteroid, call
   // breakRock and add points

   // now check for a hit (if it is close enough to any live bullets)
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         // this bullet is alive, see if its too close

         // check if the bird is at this point (in case it was hit)
         if (bird != NULL && bird->isAlive())
         {
            // BTW, this logic could be more sophisiticated, but this will
            // get the job done for now...
            if (fabs(bullets[i].getPoint().getX() - bird->getPoint().getX()) < CLOSE_ENOUGH
                && fabs(bullets[i].getPoint().getY() - bird->getPoint().getY()) < CLOSE_ENOUGH)
            {
               //we have a hit!
               
               // hit the bird
               int points = bird->hit();
               score += points;
               
               // the bullet is dead as well
               bullets[i].kill();
            }
         }
      } // if bullet is alive
      
   } // for bullets
*/
}

/**************************************************************************
 * GAME :: CLEAN UP ZOMBIES
 * Remove any dead objects (take bullets/asteroids out of lists)
 **************************************************************************/
void Game :: cleanUpZombies()
{
   // Look for dead asteroids
   vector<Rock*>::iterator asterIt = asteroids.begin();
   while (asterIt != asteroids.end())
   {
      Rock *aster = *asterIt;
      
      if (!aster->isAlive())
      {
         delete aster;
         asterIt = asteroids.erase(asterIt);
      }
      else
      {
         asterIt++; // advance
      }
   }
   
   // Look for dead bullets
   vector<Bullet>::iterator bulletIt = bullets.begin();
   while (bulletIt != bullets.end())
   {
      Bullet bullet = *bulletIt;

      if (!bullet.isAlive())
      {        
         // remove from list and advance
         bulletIt = bullets.erase(bulletIt);
      }
      else
      {
         bulletIt++; // advance
      }
   }
   
}

/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
{
   // Change the direction of the ship
   if (ui.isLeft())
   {
      ship.turnLeft();
   }
   
   if (ui.isRight())
   {
      ship.turnRight();
   }

   if (ui.isUp())
   {
      ship.thrust();
   }

   // Check for "Spacebar"
   if (ui.isSpace())
   {
      Bullet newBullet;
      // Adjust angle so bullets fire from the FRONT rather than the side
      newBullet.fire(ship.getPoint(), ship.getVelocity(), ship.getAngle() + 90);
      bullets.push_back(newBullet);
   }
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
   
   // draw the bullets, if they are alive
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         bullets[i].draw();
      }
   }

   // draw the asteroids, if they are alive
   for (int i = 0; i < asteroids.size(); i++)
   {
      if (asteroids[i]->isAlive())
      {
         asteroids[i]->draw();
      }
   }

   // Draw ship
   if (ship.isAlive())
      ship.draw();

   // A&B: Put the score on the screen, draw game name
   Point scoreLocation;
   scoreLocation.setX(topLeft.getX() + 5);
   scoreLocation.setY(topLeft.getY() - 5);
   drawNumber(scoreLocation, score);
   drawText(Point(-30, 188), "Asteroids");
}

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/
float Game :: getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const
{
   // find the maximum distance traveled
   float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
   dMax = max(dMax, abs(obj2.getVelocity().getDx()));
   dMax = max(dMax, abs(obj2.getVelocity().getDy()));
   dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.
   
   float distMin = std::numeric_limits<float>::max();
   for (float i = 0.0; i <= dMax; i++)
   {
      Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
                     obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
      Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
                     obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));
      
      float xDiff = point1.getX() - point2.getX();
      float yDiff = point1.getY() - point2.getY();
      
      float distSquared = (xDiff * xDiff) +(yDiff * yDiff);
      
      distMin = min(distMin, distSquared);
   }
   
   return sqrt(distMin);
}
