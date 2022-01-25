#include "toughbird.h"
#include "uiDraw.h"

ToughBird::ToughBird(Point p):
   Bird(p)
{
   hitsLeft = 3;
}

void ToughBird::draw()
{
   drawToughBird(p, 13, hitsLeft);
}

int ToughBird::hit()
{
   if (hitsLeft > 1)
   {
      hitsLeft--;
      return 1;
   }

   // Must be the third hit
   this->kill();
   return 3;
}
