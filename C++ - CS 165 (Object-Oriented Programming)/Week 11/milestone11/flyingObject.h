#ifndef flyingObject_h
#define flyingObject_h

#define _USE_MATH_DEFINES
#include <cmath>

#include "velocity.h"
#include "point.h"

class FlyingObject
{
   public:
      FlyingObject();
      FlyingObject(Point point);
      Point getPoint() const;
      void setPoint(Point p);
      Velocity getVelocity() const;
      void setVelocity(Velocity v);
      int getAngle() const;
      void setAngle(int angle);
      bool isAlive() const;
      void kill();
      virtual void advance();
      virtual void draw() = 0;

   protected:
      Point p;
      Velocity v;
      int angle;
      bool alive;
};

#endif /* flyingObject_h */
