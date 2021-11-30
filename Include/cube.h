#ifndef CUBE_h
#define CUBE_h

#include "row.h"
#include "floor.h"

class Cube{
   private: 
      void initCube();
      void setLedState(char ledNumber, bool state); // ���������� ���������� ���������� (false - ��������, true - �������)
      void setByte(char byte); // ��������� ����� �� ������ 
      void selectRow(char rowNumber); //������ l->U->l �� ���� CP
      void onFloor(char floorNumber); // �������� ����
      
      
   public: 
      Cube();
      void setFloor(char floorNumber, char *floor); //��������� ����� �� ���
      void setOEState(bool state);
};

#endif
