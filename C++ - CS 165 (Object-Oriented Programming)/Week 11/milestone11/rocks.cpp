#include "rocks.h"
#include "uiDraw.h"

Rock::Rock()
{
   angle = random(0, 360);

   // TODO A&B: Make rotation direction (+/-) random too
}

void Rock::advance()
{
   rotate();
   this->FlyingObject::advance();
}

void SmallRock::rotate()
{
   angle += SMALL_ROCK_SPIN;
}

void SmallRock::draw()
{
   drawSmallAsteroid(p, angle);
}

void MediumRock::rotate()
{
   angle += MEDIUM_ROCK_SPIN;
}

void MediumRock::draw()
{
   drawMediumAsteroid(p, angle);
}

void BigRock::rotate()
{
   angle += BIG_ROCK_SPIN;
}

void BigRock::draw()
{
   drawLargeAsteroid(p, angle);
}
