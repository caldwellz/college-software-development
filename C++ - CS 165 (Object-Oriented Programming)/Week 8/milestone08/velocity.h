/***********************************************************************
 * Author:
 *    Zach Caldwell
 * Summary:
 *    Stores velocity.
 ************************************************************************/

#ifndef VELOCITY_H
#define VELOCITY_H

class Velocity
{
   public:
      Velocity();
      Velocity(float x, float y);
      float getDx();
      float getDy();
      void setDx(float x);
      void setDy(float y);

   private:
      float dx;
      float dy;
};

#endif //VELOCITY_H
