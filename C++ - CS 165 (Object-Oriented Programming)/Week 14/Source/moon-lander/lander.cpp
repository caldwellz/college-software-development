/***********************************************************************
 * Author:
 *    Zach Caldwell
 * Summary:
 *    Implement the logic for the lunar lander.
 ************************************************************************/

#include "lander.h"
#include "uiDraw.h"

#include <stdio.h>

/******************************************
 * Initialize lander variables
 *****************************************/
Lander::Lander()
{
   setAlive(true);
   setLanded(false);
   this->myPosition.setY(195);
}

/******************************************
 * Get the current lander position point
 *****************************************/
Point Lander::getPoint()
{
   return this->myPosition;
}

/******************************************
 * Get the lander's velocity
 *****************************************/
Velocity Lander::getVelocity()
{
   return this->myVelocity;
}

/******************************************
 * Get whether the lander is alive
 *****************************************/
bool Lander::isAlive()
{
   return this->amAlive;
}

/******************************************
 * Set the live status of the lander
 *****************************************/
void Lander::setAlive(bool alive)
{
   this->amAlive = alive;
}

/******************************************
 * Get whether we have landed
 *****************************************/
bool Lander::isLanded()
{
   return this->amLanded;
}

/******************************************
 * Set the landing status
 *****************************************/
void Lander::setLanded(bool landed)
{
   this->amLanded = landed;
}

/******************************************
 * Get the remaining units of fuel
 *****************************************/
int Lander::getFuel()
{
   return this->myFuel;
}

/******************************************
 * Set the remaining fuel
 *****************************************/
void Lander::setFuel(int fuel)
{
   this->myFuel = fuel;
}

/******************************************
 * Get whether it is still possible to thrust
 *****************************************/
bool Lander::canThrust()
{
   if (getFuel() > 0 && isAlive() && !isLanded())
      return true;

   return false;
}

/******************************************
 * Apply gravity to the lander
 *****************************************/
void Lander::applyGravity(float gravity)
{
   myVelocity.setDy(myVelocity.getDy() - gravity);
}

/******************************************
 * Thrust towards the right (if possible)
 *****************************************/
void Lander::applyThrustLeft()
{
   if (canThrust())
   {
      myVelocity.setDx(myVelocity.getDx() + 0.1);
      myFuel--;
   }
}

/******************************************
 * Thrust towards the left (if possible)
 *****************************************/
void Lander::applyThrustRight()
{
   if (canThrust())
   {
      myVelocity.setDx(myVelocity.getDx() - 0.1);
      myFuel--;
   }
}

/******************************************
 * Thrust upwards (if possible)
 *****************************************/
void Lander::applyThrustBottom()
{
   if (canThrust())
   {
      myVelocity.setDy(myVelocity.getDy() + 0.3);
      myFuel -= 3;
   }
}

/******************************************
 * Update the lander's velocity and position
 *****************************************/
void Lander::advance()
{
   myPosition.setY(myPosition.getY() + myVelocity.getDy());
   myPosition.setX(myPosition.getX() + myVelocity.getDx());
}

/******************************************
 * Draw the lander
 *****************************************/
void Lander::draw()
{
   drawLander(this->myPosition);
}
