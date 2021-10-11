#include <stdint.h>
#include <stdbool.h>
#include "row.h"
#include "stm32f10x.h"

Row::Row(char number){
   rowNumber = number;
   
}

void Row::writeRow(char row){
   rowNumber = row;
   switch (rowNumber){
		case 0:{
			GPIOB->BSRR = GPIO_BSRR_BS6;
			break;
		}
		case 1:{
			GPIOB->BSRR = GPIO_BSRR_BS7;
			break;
		}
		case 2:{
			GPIOB->BSRR = GPIO_BSRR_BS8;
			break;
		}
		case 3:{
			GPIOB->BSRR = GPIO_BSRR_BS9;
			break;
		}
		case 4:{
			GPIOC->BSRR = GPIO_BSRR_BS13;
			break;
		}
		case 5:{
			GPIOC->BSRR = GPIO_BSRR_BS14;
			break;
		}
		case 6:{
			GPIOC->BSRR = GPIO_BSRR_BS15;
			break;
		}
		case 7:{
			GPIOC->BSRR = GPIO_BSRR_BS0;
			break;
		}
	}
	GPIOB->BSRR = GPIO_BSRR_BR6;
	GPIOB->BSRR = GPIO_BSRR_BR7;
	GPIOB->BSRR = GPIO_BSRR_BR8;
	GPIOB->BSRR = GPIO_BSRR_BR9;
	GPIOC->BSRR = GPIO_BSRR_BR13;
	GPIOC->BSRR = GPIO_BSRR_BR14;
	GPIOC->BSRR = GPIO_BSRR_BR15;
	GPIOC->BSRR = GPIO_BSRR_BR0;
}
