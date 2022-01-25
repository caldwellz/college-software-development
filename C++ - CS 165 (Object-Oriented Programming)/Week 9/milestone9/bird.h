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
      virtual void draw();
      virtual int hit();
};

#endif //BIRD_H
