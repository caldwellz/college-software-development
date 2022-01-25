#include "bullet.h"
#include "uiDraw.h"

Bullet::Bullet():
   framesAlive(0)
{ }

void Bullet::advance()
{
   this->FlyingObject::advance();

   // Check if we have exceeded max life
   framesAlive++;
   if (framesAlive > BULLET_LIFE)
      this->kill();
}

void Bullet::draw()
{
   drawDot(p);
}

// TODO: Fix something funny that's going on with the firing angle...
void Bullet::fire(Point p, const Velocity &shipVel, float angle)
{
   this->p = p;

   // Start with the ship's velocity
   this->v.setDx(shipVel.getDx());
   this->v.setDy(shipVel.getDy());

   // Add additional firing velocity
   this->v.addDx(BULLET_SPEED * (cos(M_PI / 180.0 * angle)));
   this->v.addDy(BULLET_SPEED * (sin(M_PI / 180.0 * angle)));
}
