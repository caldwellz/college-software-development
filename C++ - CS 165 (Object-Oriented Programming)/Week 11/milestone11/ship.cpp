#include "ship.h"
#include "uiDraw.h"

void Ship::turnLeft()
{
   angle = (angle + ROTATE_AMOUNT) % 360;
}

void Ship::turnRight()
{
   angle -= ROTATE_AMOUNT;
   if (angle < 0)
      angle += 360;
}

void Ship::thrust()
{
   v.addDx(THRUST_AMOUNT * (cos(M_PI / 180.0 * (angle + 90))));
   v.addDy(THRUST_AMOUNT * (sin(M_PI / 180.0 * (angle + 90))));
   thrusting = true;
}

void Ship::draw()
{
   drawShip(p, angle, thrusting);
   thrusting = false;
}
