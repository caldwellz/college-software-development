#define _USE_MATH_DEFINES
#include <cmath> // used for sin, cos, and M_PI

#include "movingobject.h"

MovingObject::MovingObject():
   p(0, 0),
   v(0, 0),
   alive(true)
{ }

MovingObject::MovingObject(Point point):
   p(point),
   v(0, 0),
   alive(true)
{ }

Point MovingObject::getPoint()
{
   return p;
}

void MovingObject::setPoint(Point p)
{
   this->p = p;
}

Velocity MovingObject::getVelocity()
{
   return v;
}

void MovingObject::setVelocity(Velocity v)
{
   this->v = v;
}

void MovingObject::setSpeed(float s)
{
   this->speed = s;
}

void MovingObject::setAngle(float a)
{
   this->angle = a;
}

bool MovingObject::isAlive()
{
   return alive;
}

bool MovingObject::kill()
{
   alive = false;
}

void MovingObject::advance()
{
   float xVel = speed * (-cos(M_PI / 180.0 * angle));
   float yVel = speed * (sin(M_PI / 180.0 * angle));;

   v.setDx(xVel);
   v.setDy(yVel);
   p.addX(xVel);
   p.addY(yVel);
}
