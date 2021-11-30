#include <stdint.h>
#include <stdbool.h>
#include "timer.h"
#include "stm32f10x.h"

unsigned int Timers[MAX_TIMERS];

extern "C" void SysTick_Handler(void){
	char i;	
	for (i = 0; i < MAX_TIMERS; i++){
		Timers[i]++;
	}
}

void InitTimers(void){
	NVIC_EnableIRQ(SysTick_IRQn);
	char i;
	for (i = 0; i < MAX_TIMERS; i++){
		Timers[i] = 0;
	}
	SysTick_Config(SystemCoreClock/1000);
}

unsigned int GetTimer(char Timer){
	return Timers[Timer];
}

void ResetTimer(char Timer){
	Timers[Timer] = 0;
}
