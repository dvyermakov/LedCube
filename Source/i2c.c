#include "i2c.h"
#include "stm32f10x.h"

void I2C_init(void){
	I2C2->CR1 &= ~I2C_CR1_PE; //выключить I2C2
	//настройка PB10, PB11 I2C
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;	
	RCC->APB1ENR |= RCC_APB1ENR_I2C2EN;
	//SCL
	GPIOB->CRH &= ~GPIO_CRH_CNF10;
	GPIOB->CRH &= ~GPIO_CRH_MODE10;
	GPIOB->CRH |= GPIO_CRH_CNF10; //Altrernate function open drain
	GPIOB->CRH |= GPIO_CRH_MODE10;	//Output mode, max speed 2 MHz.
	//SDA
	GPIOB->CRH &= ~GPIO_CRH_CNF11;	
	GPIOB->CRH &= ~GPIO_CRH_MODE11;
	GPIOB->CRH |= GPIO_CRH_CNF11; //Altrernate function open drain
	GPIOB->CRH |= GPIO_CRH_MODE11;	//Output mode, max speed 2 MHz.
	//настраиваем модуль в режим I2C
	I2C2->CR1 &= ~I2C_CR1_SMBUS;
	
        //указываем частоту тактирования модуля
	I2C2->CR2 &= ~I2C_CR2_FREQ;
	I2C2->CR2 |= 42; // Fclk1=168/4=42MHz 
	
        //конфигурируем I2C, standart mode, 100 KHz duty cycle 1/2	
	I2C2->CCR &= ~(I2C_CCR_FS | I2C_CCR_DUTY);
        //задаем частоту работы модуля SCL по формуле 10 000nS/(2* TPCLK1) 
	I2C2->CCR |= 208; //10 000ns/48ns = 208
	
	//Standart_Mode = 1000nS, Fast_Mode = 300nS, 1/42MHz = 24nS
	I2C2->TRISE = 42; //(1000nS/24nS)+1
	
	I2C2->CR1 |= I2C_CR1_PE; //включить I2C2
}

uint8_t I2C_ADDRESS(uint8_t addr, uint8_t mode){
	uint8_t dr;
	dr = addr;
	dr |= mode << 0;
	return dr;
}

void I2C_Write(uint8_t addr, uint8_t reg_addr, uint8_t data){
        //стартуем
	I2C2->CR1 |= I2C_CR1_PE; //включить I2C2
  I2C2->CR1 |= I2C_CR1_START;		
	while(!(I2C2->SR1 & I2C_SR1_SB)){};
	(void) I2C2->SR1;
		
        //передаем адрес устройства
	I2C2->DR = I2C_ADDRESS(addr, I2C_MODE_WRITE);
	while(!(I2C2->SR1 & I2C_SR1_ADDR)){};
	(void) I2C2->SR1;
	(void) I2C2->SR2;
		
        //передаем адрес регистра
	I2C2->DR = reg_addr;	
	while(!(I2C2->SR1 & I2C_SR1_TXE)){};	
			
        //пишем данные	
	I2C2->DR = data;	
	while(!(I2C2->SR1 & I2C_SR1_BTF)){};	
	I2C2->CR1 |= I2C_CR1_STOP;	
	I2C2->CR1 &= ~I2C_CR1_PE; //включить I2C2		
}

uint8_t I2C_Read(uint8_t addr, uint8_t reg_addr){
	uint8_t data;
	//стартуем
	I2C2->CR1 |= I2C_CR1_PE; //включить I2C2
	I2C2->CR1 |= I2C_CR1_ACK;
	I2C2->CR1 |= I2C_CR1_START;		
	while(!(I2C2->SR1 & I2C_SR1_SB)){};
	(void) I2C2->SR1;

	//передаем адрес устройства	
	I2C2->DR = I2C_ADDRESS(addr, I2C_MODE_WRITE);
	while(!(I2C2->SR1 & I2C_SR1_ADDR)){};
	(void) I2C2->SR1;
	(void) I2C2->SR2;

	//передаем адрес регистра
	I2C2->DR = reg_addr;	
	while(!(I2C2->SR1 & I2C_SR1_TXE)){};	
	I2C2->CR1 |= I2C_CR1_STOP;	
			
	//рестарт!!!
	I2C2->CR1 |= I2C_CR1_START;		
	while(!(I2C2->SR1 & I2C_SR1_SB)){};
	(void) I2C2->SR1;
		
	//передаем адрес устройства, но теперь для чтения
	I2C2->DR = I2C_ADDRESS(addr, I2C_MODE_READ);
	while(!(I2C2->SR1 & I2C_SR1_ADDR)){};
	(void) I2C2->SR1;
	(void) I2C2->SR2;
			
	//читаем	
	I2C2->CR1 &= ~I2C_CR1_ACK;
	while(!(I2C2->SR1 & I2C_SR1_RXNE)){};
	data = I2C2->DR;	
	I2C2->CR1 |= I2C_CR1_STOP;	
	I2C2->CR1 &= ~I2C_CR1_PE; //выключить I2C2
	return data;	
}

