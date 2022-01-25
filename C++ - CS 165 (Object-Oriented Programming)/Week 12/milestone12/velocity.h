#ifndef VELOCITY_H
#define VELOCITY_H

class Velocity
{
   public:
      Velocity();
      Velocity(float x, float y);
      float getDx() const;
      float getDy() const;
      void setDx(float x);
      void setDy(float y);
      void addDx(float x);
      void addDy(float y);

   private:
      float dx;
      float dy;
};

#endif /* velocity_h */
