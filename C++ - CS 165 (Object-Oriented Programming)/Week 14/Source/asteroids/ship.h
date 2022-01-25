#ifndef ship_h
#define ship_h

#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5

#include "flyingObject.h"

class Ship: public FlyingObject
{
   public:
      void turnLeft();
      void turnRight();
      void thrust();
      void draw();
      int getRadius();

   private:
      bool thrusting;
};

#endif /* ship_h */
