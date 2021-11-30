#ifndef CUBE_h
#define CUBE_h

#include "row.h"
#include "floor.h"

class Cube{
   private: 
      void initCube();
      void setLedState(char ledNumber, bool state); // управление состоянием светодиода (false - выключен, true - включен)
      void setByte(char byte); // установка байта на строку 
      void selectRow(char rowNumber); //сигнал l->U->l на ногу CP
      void onFloor(char floorNumber); // зажигаем этаж
      
      
   public: 
      Cube();
      void setFloor(char floorNumber, char *floor); //установка этажа из вне
      void setOEState(bool state);
};

#endif
