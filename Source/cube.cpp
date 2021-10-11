#include <stdint.h>
#include <stdbool.h>
#include "cube.h"
#include "stm32f10x.h"

Cube::Cube(){
   initCube();
}

void Cube::initCube(){
   //Enable GPIO ports
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; //PORTA
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN; //PORTB
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN; //PORTC
	RCC->APB2ENR |= RCC_APB2ENR_IOPDEN; //PORTD
	
	//JTAG disable for PA15, PB3 work as pins
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
	AFIO->MAPR |= AFIO_MAPR_SWJ_CFG_JTAGDISABLE;	
	
	//OE pin configuration
	GPIOA->CRH &= ~GPIO_CRH_CNF8; //CNF = 00 - General purpose output push-pull
	GPIOA->CRH |= GPIO_CRH_MODE8; //MODE = 11 - Output mode, max speed 10 MHz
	
	//Led pins configuration
	//Led0 POTRB pin 12
	GPIOB->CRH &= ~GPIO_CRH_CNF12; //CNF = 00 - General purpose output push-pull
	GPIOB->CRH |= GPIO_CRH_MODE12; //MODE = 11 - Output mode, max speed 10 MHz
	//Led1 POTRB pin 13
	GPIOB->CRH &= ~GPIO_CRH_CNF13; //CNF = 00 - General purpose output push-pull
	GPIOB->CRH |= GPIO_CRH_MODE13; //MODE = 11 - Output mode, max speed 10 MHz
	//Led2 POTRB pin 14
	GPIOB->CRH &= ~GPIO_CRH_CNF14; //CNF = 00 - General purpose output push-pull
	GPIOB->CRH |= GPIO_CRH_MODE14; //MODE = 11 - Output mode, max speed 10 MHz
	//Led3 POTRB pin 15
	GPIOB->CRH &= ~GPIO_CRH_CNF15; //CNF = 00 - General purpose output push-pull
	GPIOB->CRH |= GPIO_CRH_MODE15; //MODE = 11 - Output mode, max speed 10 MHz
	//Led4 POTRC pin 6
	GPIOC->CRL &= ~GPIO_CRL_CNF6; //CNF = 00 - General purpose output push-pull
	GPIOC->CRL |= GPIO_CRL_MODE6; //MODE = 11 - Output mode, max speed 10 MHz
	//Led5 POTRC pin 7
	GPIOC->CRL &= ~GPIO_CRL_CNF7; //CNF = 00 - General purpose output push-pull
	GPIOC->CRL |= GPIO_CRL_MODE7; //MODE = 11 - Output mode, max speed 10 MHz
	//Led6 POTRC pin 8
	GPIOC->CRH &= ~GPIO_CRH_CNF8; //CNF = 00 - General purpose output push-pull
	GPIOC->CRH |= GPIO_CRH_MODE8; //MODE = 11 - Output mode, max speed 10 MHz
	//Led7 POTRC pin 9
	GPIOC->CRH &= ~GPIO_CRH_CNF9; //CNF = 00 - General purpose output push-pull
	GPIOC->CRH |= GPIO_CRH_MODE9; //MODE = 11 - Output mode, max speed 10 MHz	
	
	//Row pins configuration
	//Row0 POTRB pin 6
	GPIOB->CRL &= ~GPIO_CRL_CNF6; //CNF = 00 - General purpose output push-pull
	GPIOB->CRL |= GPIO_CRL_MODE6; //MODE = 11 - Output mode, max speed 10 MHz
	//Row1 POTRB pin 7
	GPIOB->CRL &= ~GPIO_CRL_CNF7; //CNF = 00 - General purpose output push-pull
	GPIOB->CRL |= GPIO_CRL_MODE7; //MODE = 11 - Output mode, max speed 10 MHz
	//Row2 POTRB pin 8
	GPIOB->CRH &= ~GPIO_CRH_CNF8; //CNF = 00 - General purpose output push-pull
	GPIOB->CRH |= GPIO_CRH_MODE8; //MODE = 11 - Output mode, max speed 10 MHz
	//Row3 POTRB pin 9
	GPIOB->CRH &= ~GPIO_CRH_CNF9; //CNF = 00 - General purpose output push-pull
	GPIOB->CRH |= GPIO_CRH_MODE9; //MODE = 11 - Output mode, max speed 10 MHz
	//Row4 POTRC pin 13
	GPIOC->CRH &= ~GPIO_CRH_CNF13; //CNF = 00 - General purpose output push-pull
	GPIOC->CRH |= GPIO_CRH_MODE13; //MODE = 11 - Output mode, max speed 10 MHz
	//Row5 POTRC pin 14
	GPIOC->CRH &= ~GPIO_CRH_CNF14; //CNF = 00 - General purpose output push-pull
	GPIOC->CRH |= GPIO_CRH_MODE14; //MODE = 11 - Output mode, max speed 10 MHz
	//Row6 POTRC pin 15
	GPIOC->CRH &= ~GPIO_CRH_CNF15; //CNF = 00 - General purpose output push-pull
	GPIOC->CRH |= GPIO_CRH_MODE15; //MODE = 11 - Output mode, max speed 10 MHz
	//Row7 POTRC pin 0
	GPIOC->CRL &= ~GPIO_CRL_CNF0; //CNF = 00 - General purpose output push-pull
	GPIOC->CRL |= GPIO_CRL_MODE0; //MODE = 11 - Output mode, max speed 10 MHz
	
	//Floor pins configuration
	//Floor0 PORTA pin 0
	GPIOA->CRH &= ~GPIO_CRH_CNF15; //CNF = 00 - General purpose output push-pull
	GPIOA->CRH |= GPIO_CRH_MODE15; //MODE = 11 - Output mode, max speed 50 MHz
	//Floor1 PORTC pin 10
	GPIOC->CRH &= ~GPIO_CRH_CNF10; //CNF = 00 - General purpose output push-pull
	GPIOC->CRH |= GPIO_CRH_MODE10; //MODE = 11 - Output mode, max speed 50 MHz
	//Floor2 PORTC pin 11
	GPIOC->CRH &= ~GPIO_CRH_CNF11; //CNF = 00 - General purpose output push-pull
	GPIOC->CRH |= GPIO_CRH_MODE11; //MODE = 11 - Output mode, max speed 50 MHz
	//Floor3 PORTC pin 12
	GPIOC->CRH &= ~GPIO_CRH_CNF12; //CNF = 00 - General purpose output push-pull
	GPIOC->CRH |= GPIO_CRH_MODE12; //MODE = 11 - Output mode, max speed 50 MHz
	//Floor4 PORTD pin 2
	GPIOD->CRL &= ~GPIO_CRL_CNF2; //CNF = 00 - General purpose output push-pull
	GPIOD->CRL |= GPIO_CRL_MODE2; //MODE = 11 - Output mode, max speed 50 MHz
	//Floor5 PORTB pin 3
	GPIOB->CRL &= ~GPIO_CRL_CNF3; //CNF = 00 - General purpose output push-pull
	GPIOB->CRL |= GPIO_CRL_MODE3; //MODE = 11 - Output mode, max speed 50 MHz
	//Floor6 PORTB pin 4
	GPIOB->CRL &= ~GPIO_CRL_CNF4; //CNF = 00 - General purpose output push-pull
	GPIOB->CRL |= GPIO_CRL_MODE4; //MODE = 11 - Output mode, max speed 50 MHz
	//Floor7 PORTB pin 5
	GPIOB->CRL &= ~GPIO_CRL_CNF5; //CNF = 00 - General purpose output push-pull
	GPIOB->CRL |= GPIO_CRL_MODE5; //MODE = 11 - Output mode, max speed 50 MHz
}

void Cube::setOEState(bool state){
   if (state){
		GPIOA->BSRR = GPIO_BSRR_BR8;
	}
	else{
		GPIOA->BSRR = GPIO_BSRR_BS8;
	}
}

void Cube::setByte(char byte){
   if (byte & (1 << 0)){
      leds[0].setLedState(true);
   }
   else{
      leds[0].setLedState(false);
   }
   if (byte & (1 << 1)){
      leds[0].setLedState(true);
   }
   else{
      leds[1].setLedState(false);
   }
   if (byte & (1 << 2)){
      leds[2].setLedState(true);
   }
   else{
      leds[2].setLedState(false);
   }
   if (byte & (1 << 3)){
      leds[3].setLedState(true);
   }
   else{
      leds[3].setLedState(false);
   }
   if (byte & (1 << 4)){
      leds[4].setLedState(true);
   }
   else{
      leds[4].setLedState(false);
   }
   if (byte & (1 << 5)){
      leds[5].setLedState(true);
   }
   else{
      leds[5].setLedState(false);
   }
   if (byte & (1 << 6)){
      leds[6].setLedState(true);
   }
   else{
      leds[6].setLedState(false);
   }
   if (byte & (1 << 7)){
      leds[7].setLedState(true);
   }
   else{
      leds[7].setLedState(false);
   }
}
