#include <stdint.h>
#include <stdbool.h>
#include "timer.h"
#include "stm32f10x.h"

unsigned int Timers[MAX_TIMERS];

void SysTick_Handler(){
	char i;	
	for (i = 0; i < MAX_TIMERS; i++){
		Timers[i]++;
	}
}

void InitTimers(void){
	char i;
	for (i = 0; i < MAX_TIMERS; i++){
		Timers[i] = 0;
	}
	SysTick_Config(SystemCoreClock/10);
}

unsigned int GetTimer(char Timer){
	return Timers[Timer];
}

void ResetTimer(char Timer){
	Timers[Timer] = 0;
}
