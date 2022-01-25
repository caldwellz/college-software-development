#include "sacredbird.h"
#include "uiDraw.h"

SacredBird::SacredBird(Point p):
   Bird(p)
{ }

void SacredBird::draw()
{
   drawSacredBird(p, 15);
}

int SacredBird::hit()
{
   this->kill();
   return -10;
}
