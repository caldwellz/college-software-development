/***********************************************************************
 * Author:
 *    Zach Caldwell
 * Summary:
 *    Manage the logic of the lunar lander.
 ************************************************************************/

#ifndef LANDER_H
#define LANDER_H

#include "point.h"
#include "velocity.h"

class Lander
{
   public:
      Lander();
      Point getPoint();
      Velocity getVelocity();
      bool isAlive();
      void setAlive(bool alive);
      bool isLanded();
      void setLanded(bool landed);
      int getFuel();
      void setFuel(int fuel);

      bool canThrust();
      void applyGravity(float gravity);
      void applyThrustLeft();
      void applyThrustRight();
      void applyThrustBottom();
      void advance();
      void draw();

   private:
      Point myPosition;
      Velocity myVelocity;
      bool amAlive;
      bool amLanded;
      int myFuel;
};

#endif //LANDER_H
