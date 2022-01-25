#ifndef bullet_h
#define bullet_h

#include "flyingObject.h"
#include "point.h"
#include "velocity.h"

const unsigned int BULLET_SPEED = 5;
const unsigned int BULLET_LIFE = 40;

class Bullet: public FlyingObject
{
   public:
      Bullet();
      void advance();
      void draw();
      void fire(Point p, const Velocity &shipVel, float angle);

   private:
      int framesAlive;
};

#endif /* bullet_h */
