#include "flyingObject.h"

FlyingObject::FlyingObject():
   p(0, 0),
   v(0, 0),
   angle(0),
   alive(true)
{ }

FlyingObject::FlyingObject(Point point):
   p(point),
   v(0, 0),
   angle(0),
   alive(true)
{ }

Point FlyingObject::getPoint() const
{
   return p;
}

void FlyingObject::setPoint(Point p)
{
   this->p = p;
}

Velocity FlyingObject::getVelocity() const
{
   return v;
}

void FlyingObject::setVelocity(Velocity v)
{
   this->v = v;
}

int FlyingObject::getAngle() const
{
   return angle;
}

void FlyingObject::setAngle(int angle)
{
   this->angle = angle;
}

bool FlyingObject::isAlive() const
{
   return alive;
}

void FlyingObject::kill()
{
   alive = false;
}

void FlyingObject::advance()
{
   p.addX(v.getDx());
   p.addY(v.getDy());
}
