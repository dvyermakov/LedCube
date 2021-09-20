#include "stm32f10x.h"

#include "delay.h"

#define	F_APB1 				72000000

void Delay_init(void){
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN; 
}

void delay_ms(uint32_t delay){	
	TIM4->PSC = F_APB1 / 1000 + 1;	
  TIM4->ARR = delay;	
  TIM4->EGR |= TIM_EGR_UG;	
  TIM4->CR1 |= TIM_CR1_CEN | TIM_CR1_OPM;	
  while ((TIM4->CR1 & TIM_CR1_CEN) != 0);
}

void delay_us(uint32_t delay){
	TIM4->PSC = F_APB1 / 1000000 + 1;	
  TIM4->ARR = delay;	
  TIM4->EGR |= TIM_EGR_UG;
  TIM4->CR1 |= TIM_CR1_CEN | TIM_CR1_OPM;
  while ((TIM4->CR1 & TIM_CR1_CEN) != 0);
}
