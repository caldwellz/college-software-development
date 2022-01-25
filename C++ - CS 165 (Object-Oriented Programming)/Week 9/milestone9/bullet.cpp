#include "bullet.h"
#include "uiDraw.h"

void Bullet::draw()
{
   drawDot(p);
}

void Bullet::fire(Point p, float angle)
{
   this->p = p;
   this->v.setDx(BULLET_SPEED * (-cos(M_PI / 180.0 * angle)));
   this->v.setDy(BULLET_SPEED * (sin(M_PI / 180.0 * angle)));
}
