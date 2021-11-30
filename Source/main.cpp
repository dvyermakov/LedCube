#include "stm32f10x.h"
#include "stm32f10x_gpio.h"     // ???? ? ????????? ?????????? ??????? ???????????
#include "stm32f10x_rcc.h"      // ?????????? ?????????????
#include <stdint.h>             // ?????????? ???? ??????, ?????? ?????? int, char ? ???? ????????
#include <cube.h>
#include "frame.h"
#include <timer.h>

#define FPS       32
#define TIME_FLOOR   FPS / 8     // время переключения слоев

#define CUBE_START         0
#define CUBE_LIGHTING      1
#define CUBE_NEXT_FLOOR    2
#define CUBE_NEXT_FRAME    3

void init(void){

}

int main(void){	
	init();
	InitTimers();
	Cube myCube;
   const int FrameCount = 2;
   struct stFrame program[FrameCount];
   struct stFrame frame1 = {
      {
         {0, 0, 0, 0, 0, 0, 0, 1},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0}
      },
      10
   };
   struct stFrame frame2 = {
      {
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0}
      },
      10
   };
   program[0] = frame1;
   program[1] = frame2;
   char CubeState = CUBE_START;
   char FloorCounter = 0;
   int FrameCounter = 0;   
	while (1){
		switch (CubeState){
         case CUBE_START:{
            FrameCounter = 0;
            //ResetTimer(T_FLOOR);
            CubeState = CUBE_NEXT_FRAME;
            break;
         }
         case CUBE_LIGHTING:{
            //смена frame
            if (FloorCounter == 7){
               if (GetTimer(T_FRAME) >= program[FrameCounter].Time){
                  FrameCounter++;
                  CubeState = CUBE_NEXT_FRAME;               
               }
            }            
            //смена floor
            if (GetTimer(T_FLOOR) >= TIME_FLOOR){
               FloorCounter++;
               CubeState = CUBE_NEXT_FLOOR;               
            }            
            break;
         }
         case CUBE_NEXT_FLOOR:{
            //myCube.setFloor   
            if (FloorCounter == 7){
               FloorCounter = 0;
            }           
            myCube.setFloor(FloorCounter, program[FrameCounter].Cube[FloorCounter]);
            ResetTimer(T_FLOOR);
            CubeState = CUBE_LIGHTING;
            break;
         }
         case CUBE_NEXT_FRAME:{
            if (FrameCounter < FrameCount - 1){
               FloorCounter = 0;
               CubeState = CUBE_NEXT_FLOOR;
               ResetTimer(T_FRAME);
            }
            else{
              CubeState = CUBE_START;               
            }
            break;
         }
      }
	}	
	//return 0;
}
