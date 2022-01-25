/*************************************************************
 * File: toughbird.h
 * Author: Zach Caldwell
 *************************************************************/

#ifndef TOUGHBIRD_H
#define TOUGHBIRD_H

#include "bird.h"

class ToughBird: public Bird
{
   public:
      ToughBird(Point p);
      void draw();
      int hit();

   private:
      int hitsLeft;
};

#endif //TOUGHBIRD_H
