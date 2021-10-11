#ifndef FLOOR_h
#define FLOOR_h

class Floor{
   private: 
      char floorNumber; // номер этажа 0 - 7

   public: 
      Floor(char number);
      void onFloor(char floor);
};

#endif
