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
   this->amAlive = true;
   this->amLanded = false;
   this->myFuel = 500;
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
   if (this->myFuel > 0)
      return true;

   return false;
}

/******************************************
 * STUB: Apply gravity to the lander
 *****************************************/
void Lander::applyGravity(float gravity)
{
   
}

/******************************************
 * STUB: Thrust towards the right (if possible)
 *****************************************/
void Lander::applyThrustLeft()
{
   
}

/******************************************
 * STUB: Thrust towards the left (if possible)
 *****************************************/
void Lander::applyThrustRight()
{
   
}

/******************************************
 * STUB: Thrust upwards (if possible)
 *****************************************/
void Lander::applyThrustBottom()
{
   
}

/******************************************
 * STUB: Update the lander's velocity and position
 *****************************************/
void Lander::advance()
{
   
}

/******************************************
 * 
 *****************************************/
void Lander::draw()
{
   drawLander(this->myPosition);
}
