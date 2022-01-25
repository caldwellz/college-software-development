/*************************************************************
 * File: bullet.h
 * Author: Zach Caldwell
 *************************************************************/

#ifndef BULLET_H
#define BULLET_H

#include "movingobject.h"
#include "point.h"

class Bullet: public MovingObject
{
   public:
      Bullet();
      void draw();
      void fire(Point p, float angle);
};

#endif //BULLET_H
