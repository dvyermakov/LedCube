#ifndef FRAME_H
#define FRAME_H
#include <stdint.h>

struct stFloor{
//   char Row0;
//   char Row1;
//   char Row2;
//   char Row3;
//   char Row4;
//   char Row5;
//   char Row6;
//   char Row7;
   char Rows[8]; // {0, 0, 0, 0, 0, 0, 0, 1}
};

// 

struct stCube{
//   struct stFloor Floor0;
//   struct stFloor Floor1;
//   struct stFloor Floor2;
//   struct stFloor Floor3;
//   struct stFloor Floor4;
//   struct stFloor Floor5;
//   struct stFloor Floor6;
//   struct stFloor Floor7;
   struct stFloor Floors[8];
};

struct stFrame{
   char Cube[8][8];
   uint32_t Time;
};


#endif
