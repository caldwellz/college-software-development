#ifndef rocks_h
#define rocks_h

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10
const unsigned int ROCK_SPEED = 1;

#include <vector>
#include "flyingObject.h"
#include "point.h"

class Rock: public FlyingObject
{
   public:
      Rock();
      void advance();
      virtual void rotate() = 0;
      virtual int breakRock(std::vector<Rock*> &asteroids) = 0;
};

class SmallRock: public Rock
{
   public:
      void rotate();
      void draw();
      int getRadius();
      int breakRock(std::vector<Rock*> &asteroids);
};

class MediumRock: public Rock
{
   public:
      void rotate();
      void draw();
      int getRadius();
      int breakRock(std::vector<Rock*> &asteroids);
};

class BigRock: public Rock
{
   public:
      void rotate();
      void draw();
      int getRadius();
      int breakRock(std::vector<Rock*> &asteroids);
};

#endif /* rocks_h */
