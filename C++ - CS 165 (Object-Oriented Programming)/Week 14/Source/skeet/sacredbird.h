/*************************************************************
 * File: sacredbird.h
 * Author: Zach Caldwell
 *************************************************************/

#ifndef SACREDBIRD_H
#define SACREDBIRD_H

#include "bird.h"

class SacredBird: public Bird
{
   public:
      SacredBird(Point p);
      void draw();
      int hit();
};

#endif //SACREDBIRD_H
