/*************************************************************
 * File: bullet.h
 * Author: Zach Caldwell
 *************************************************************/

#ifndef BULLET_H
#define BULLET_H

#include "movingobject.h"
#include "point.h"

const unsigned int BULLET_SPEED = 10;

class Bullet: public MovingObject
{
   public:
      void draw();
      void fire(Point p, float angle);
};

#endif //BULLET_H
