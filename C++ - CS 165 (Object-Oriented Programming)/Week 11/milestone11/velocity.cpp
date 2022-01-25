#include "velocity.h"

/******************************************
 * Initialize the velocity to 0 both ways
 *****************************************/
Velocity::Velocity()
{
   this->setDx(0.0);
   this->setDy(0.0);
}

/******************************************
 * Initialize the velocity to the passed values
 *****************************************/
Velocity::Velocity(float x, float y)
{
   this->setDx(x);
   this->setDy(y);
}

/******************************************
 * Get the velocity x-value
 *****************************************/
float Velocity::getDx() const
{
   return this->dx;
}

/******************************************
 * Get the velocity y-value
 *****************************************/
float Velocity::getDy() const
{
   return this->dy;
}

/******************************************
 * Set the velocity x-value
 *****************************************/
void Velocity::setDx(float x)
{
   this->dx = x;
}

/******************************************
 * Set the velocity y-value
 *****************************************/
void Velocity::setDy(float y)
{
   this->dy = y;
}

/******************************************
 * Add a velocity x-value
 *****************************************/
void Velocity::addDx(float x)
{
   this->dx += x;
}

/******************************************
 * Add a velocity y-value
 *****************************************/
void Velocity::addDy(float y)
{
   this->dy += y;
}
