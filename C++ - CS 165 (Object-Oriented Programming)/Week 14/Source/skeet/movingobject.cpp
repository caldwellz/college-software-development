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

bool MovingObject::isAlive()
{
   return alive;
}

void MovingObject::kill()
{
   alive = false;
}

void MovingObject::advance()
{
   p.addX(v.getDx());
   p.addY(v.getDy());
}
