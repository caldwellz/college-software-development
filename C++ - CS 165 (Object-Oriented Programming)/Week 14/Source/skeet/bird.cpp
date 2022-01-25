#include "bird.h"
#include "uiDraw.h"

Bird::Bird(Point p):
   MovingObject(p)
{ }

void Bird::draw()
{
   drawCircle(p, 15);
}

int Bird::hit()
{
   this->kill();
   return 1;
}
