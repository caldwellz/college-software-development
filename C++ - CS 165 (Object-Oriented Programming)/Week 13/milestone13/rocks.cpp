#include "rocks.h"
#include "uiDraw.h"

Rock::Rock()
{
   angle = random(0, 360);
}

void Rock::advance()
{
   rotate();
   this->FlyingObject::advance();
}

void Rock::rotate()
{
   angle += spin;
}

SmallRock::SmallRock()
{
   // Set random spin direction
   if ((random(0, 10) % 2) == 0)
      spin = SMALL_ROCK_SPIN;
   else
      spin = -SMALL_ROCK_SPIN;
}

void SmallRock::draw()
{
   drawSmallAsteroid(p, angle);
}

int SmallRock::getRadius()
{
   return 4;
}

int SmallRock::breakRock(std::vector<Rock*> &asteroids) {
   kill();
   return 3;
}

MediumRock::MediumRock()
{
   // Set random spin direction
   if ((random(0, 10) % 2) == 0)
      spin = MEDIUM_ROCK_SPIN;
   else
      spin = -MEDIUM_ROCK_SPIN;
}

void MediumRock::draw()
{
   drawMediumAsteroid(p, angle);
}

int MediumRock::getRadius()
{
   return 8;
}

int MediumRock::breakRock(std::vector<Rock*> &asteroids) {
   kill();

   Rock* newrock = new SmallRock;
   Velocity newvel = this->v;
   newvel.addDx(3);
   newrock->setVelocity(newvel);
   newrock->setPoint(this->p);
   asteroids.push_back(newrock);

   newrock = new SmallRock;
   newvel = this->v;
   newvel.addDy(3);
   newrock->setVelocity(newvel);
   newrock->setPoint(this->p);
   asteroids.push_back(newrock);

   return 2;
}

BigRock::BigRock()
{
   // Set random spin direction
   if ((random(0, 10) % 2) == 0)
      spin = BIG_ROCK_SPIN;
   else
      spin = -BIG_ROCK_SPIN;
}

void BigRock::draw()
{
   drawLargeAsteroid(p, angle);
}

int BigRock::getRadius()
{
   return 16;
}

int BigRock::breakRock(std::vector<Rock*> &asteroids) {
   kill();

   Rock* newrock = new MediumRock;
   Velocity newvel = this->v;
   newvel.addDy(1);
   newrock->setVelocity(newvel);
   newrock->setPoint(this->p);
   asteroids.push_back(newrock);

   newrock = new MediumRock;
   newvel = this->v;
   newvel.addDy(-1);
   newrock->setVelocity(newvel);
   newrock->setPoint(this->p);
   asteroids.push_back(newrock);

   newrock = new SmallRock;
   newvel = this->v;
   newvel.addDx(2);
   newrock->setVelocity(newvel);
   newrock->setPoint(this->p);
   asteroids.push_back(newrock);

   return 1;
}
