#include <stdint.h>
#include <stdbool.h>
#include "floor.h"
#include "stm32f10x.h"

Floor::Floor(char number){
   floorNumber = number;   
}

void Floor::onFloor(char floor){
   GPIOA->BSRR = GPIO_BSRR_BR15;
	GPIOC->BSRR = GPIO_BSRR_BR10;
	GPIOC->BSRR = GPIO_BSRR_BR11;
	GPIOC->BSRR = GPIO_BSRR_BR12;
	GPIOD->BSRR = GPIO_BSRR_BR2;
	GPIOB->BSRR = GPIO_BSRR_BR3;
	GPIOB->BSRR = GPIO_BSRR_BR4;
	GPIOB->BSRR = GPIO_BSRR_BR5;
	switch (floor){
		case 0:{
			GPIOA->BSRR = GPIO_BSRR_BS15;
			break;
		}
		case 1:{
			GPIOC->BSRR = GPIO_BSRR_BS10;
			break;
		}
		case 2:{
			GPIOC->BSRR = GPIO_BSRR_BS11;
			break;
		}
		case 3:{
			GPIOC->BSRR = GPIO_BSRR_BS12;
			break;
		}
		case 4:{
			GPIOD->BSRR = GPIO_BSRR_BS2;
			break;
		}
		case 5:{
			GPIOB->BSRR = GPIO_BSRR_BS3;
			break;
		}
		case 6:{
			GPIOB->BSRR = GPIO_BSRR_BS4;
			break;
		}
		case 7:{
			GPIOB->BSRR = GPIO_BSRR_BS5;
			break;
		}
	}
}
