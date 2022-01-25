#include "bullet.h"
#include "uiDraw.h"

Bullet::Bullet()
{
   setSpeed(10);
}

void Bullet::draw()
{
   drawDot(p);
}

void Bullet::fire(Point p, float angle)
{
   this->p = p;
   this->angle = angle;
}
