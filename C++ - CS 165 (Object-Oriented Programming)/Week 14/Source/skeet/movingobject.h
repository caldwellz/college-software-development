/*************************************************************
 * File: movingobject.h
 * Author: Zach Caldwell
 *************************************************************/

#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

#define _USE_MATH_DEFINES
#include <cmath>

#include "velocity.h"
#include "point.h"

class MovingObject
{
   public:
      MovingObject();
      MovingObject(Point point);
      Point getPoint();
      void setPoint(Point p);
      Velocity getVelocity();
      void setVelocity(Velocity v);
      bool isAlive();
      void kill();
      virtual void advance();
      virtual void draw() = 0;

   protected:
      Point p;
      Velocity v;
      bool alive;
};

#endif //MOVINGOBJECT_H
