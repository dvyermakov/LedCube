#include "usart1.h"
#include "stm32f10x.h"
#include <string.h>

void USART1_init(void){
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN; //включаем тактирование usart1
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; //включаем тактирование порта A
	//настройка PA9 - TX1
	// CNF = 10 - Alternate function output Push-pull, MODE = 11 - Output mode, max speed 50MHz
	GPIOA->CRH |= GPIO_CRH_MODE9 | GPIO_CRH_CNF9_1;
	GPIOA->CRH &= ~GPIO_CRH_CNF9_0;
	// настройка PA10 - RX1
	// CNF = 10 - Input with pull-up/pull-down, MODE = 00 - Input mode (reset state), ODR = 1 - pull-up
	GPIOA->CRH &= ~GPIO_CRH_CNF10_0;
	GPIOA->CRH |= GPIO_CRH_CNF10_1;
	GPIOA->CRH &= ~GPIO_CRH_MODE10;
	GPIOA->BSRR |= GPIO_ODR_ODR10;
	USART1->CR1 = USART_CR1_UE; // разрешаем USART1, сбрасываем остальные биты
	//USARTDIV = Fck / (16 * BAUD) = 72000000 / (16 * 9600) = 468,75
	//Значение регистра USART_BRR = 468,75 * 16 = 7500.
	USART1->BRR = 7500; // скорость 9600 бод
	USART1->CR1 |= USART_CR1_TE | USART_CR1_RE ; // разрешаем приемник и передатчик
	USART1->CR2 = 0;
	USART1->CR3 = 0;
}

void USART1_send_byte(uint8_t byte){
	while (! (USART1->SR & USART_SR_TC));
	USART1->DR = byte;
}

void USART1_send_buf(char* buf){
	for (uint8_t i = 0; i < strlen(buf); i++){
		USART1_send_byte(buf[i]);
	}
}

