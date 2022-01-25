/*************************************************************
 * File: movingobject.h
 * Author: Zach Caldwell
 *************************************************************/

#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

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
      void setSpeed(float s);
      void setAngle(float a);
      bool isAlive();
      bool kill();
      virtual void advance();
      virtual void draw() = 0;

   protected:
      Point p;
      Velocity v;
      float speed;
      float angle;
      bool alive;
};

#endif //MOVINGOBJECT_H
