#ifndef USART1_h
#define USART1_h

#include <stdint.h>

void USART1_init(void);

void USART1_send_byte(uint8_t byte);
void USART1_send_buf(char* buf);
#endif
