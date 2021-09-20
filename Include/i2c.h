#ifndef I2C_h
#define I2C_h

#include <stdint.h>

#define I2C_MODE_WRITE	0
#define I2C_MODE_READ		1
//#define CLK_ADDR				0xD0

void I2C_init(void);
uint8_t I2C_ADDRESS(uint8_t addr, uint8_t mode);
void I2C_Write(uint8_t addr, uint8_t reg_addr, uint8_t data);
uint8_t I2C_Read(uint8_t addr, uint8_t reg_addr);

#endif
