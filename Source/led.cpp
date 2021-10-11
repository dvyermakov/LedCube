#include <stdint.h>
#include <stdbool.h>
#include "led.h"
#include "stm32f10x.h"

Led::Led(char number){
   ledNumber = number;
}

void Led::setLedState(bool state){
   ledState = state;
   switch (ledNumber){
      case 0:{
         if (ledState){
				GPIOB->BSRR = GPIO_BSRR_BS12;
			}
			else{
				GPIOB->BSRR = GPIO_BSRR_BR12;
			}
         break;
      }
      case 1:{
         if (ledState){
				GPIOB->BSRR = GPIO_BSRR_BS13;
			}
			else{
				GPIOB->BSRR = GPIO_BSRR_BR13;
			}
         break;
      }
      case 2:{
         if (ledState){
				GPIOB->BSRR = GPIO_BSRR_BS14;
			}
			else{
				GPIOB->BSRR = GPIO_BSRR_BR14;
			}
         break;
      }
      case 3:{
         if (ledState){
				GPIOB->BSRR = GPIO_BSRR_BS15;
			}
			else{
				GPIOB->BSRR = GPIO_BSRR_BR15;
			}
         break;
      }
      case 4:{
         if (ledState){
				GPIOC->BSRR = GPIO_BSRR_BS6;
			}
			else{
				GPIOC->BSRR = GPIO_BSRR_BR6;
			}
         break;
      }
      case 5:{
         if (ledState){
				GPIOC->BSRR = GPIO_BSRR_BS7;
			}
			else{
				GPIOC->BSRR = GPIO_BSRR_BR7;
			}
         break;
      }
      case 6:{
         if (ledState){
				GPIOC->BSRR = GPIO_BSRR_BS8;
			}
			else{
				GPIOC->BSRR = GPIO_BSRR_BR8;
			}
         break;
      }
      case 7:{
         if (ledState){
				GPIOC->BSRR = GPIO_BSRR_BS9;
			}
			else{
				GPIOC->BSRR = GPIO_BSRR_BR9;
			}
         break;
      }
   }
}


