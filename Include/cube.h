#ifndef CUBE_h
#define CUBE_h

#include "led.h"
#include "row.h"
#include "floor.h"

class Cube{
   private: 
      void initCube();
      Led leds[8] = {0, 1, 2, 3, 4, 5, 6, 7};
      Row rows[8] = {0, 1, 2, 3, 4, 5, 6, 7};
      Floor floors[8] = {0, 1, 2, 3, 4, 5, 6, 7};
      void setByte(char byte);
      
   public: 
      Cube();
   
      void setOEState(bool state);
};

#endif
