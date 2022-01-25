/*************************************************************
 * File: bird.h
 * Author: Zach Caldwell
 *************************************************************/

#ifndef BIRD_H
#define BIRD_H

#include "movingobject.h"

class Bird: public MovingObject
{
   public:
      Bird(Point p);
      void draw();
      int hit();
};

#endif //BIRD_H
