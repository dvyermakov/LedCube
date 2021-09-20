#include "stm32f10x.h"
#include "keyboard.h"
#include "timers.h"
#include "messages.h"
char key_state; // состояние автомата
char key_code, _key_code, short_key; // код клавиши
char debounce =  1 * msec;
char first_delay = 10 * msec;
char auto_repeat = 5 * msec;

void scan_keyboard(void){
	key_code = KEY_NONE;
	if ((GPIOA->IDR & GPIO_IDR_IDR4) == 0){
		key_code = KEY_INC;
	}
	if ((GPIOA->IDR & GPIO_IDR_IDR5) == 0){
		key_code = KEY_DEC;
	}
	if ((GPIOA->IDR & GPIO_IDR_IDR6) == 0){
		key_code = KEY_OK;
	}
	if ((GPIOA->IDR & GPIO_IDR_IDR7) == 0){
		key_code = KEY_MENU;
	}
}

void InitKeyboard(void){
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	//кнопка "+"
	GPIOA->CRL &= ~GPIO_CRL_MODE4;
	GPIOA->CRL &= ~GPIO_CRL_CNF4;
	GPIOA->CRL |= GPIO_CRL_CNF4_1;
	GPIOA->BSRR |= GPIO_BSRR_BS4;
	//кнопка "-"
	GPIOA->CRL &= ~GPIO_CRL_MODE5;
	GPIOA->CRL &= ~GPIO_CRL_CNF5;
	GPIOA->CRL |= GPIO_CRL_CNF5_1;
	GPIOA->BSRR |= GPIO_BSRR_BS5;
	//кнопка "Ok"
	GPIOA->CRL &= ~GPIO_CRL_MODE6;
	GPIOA->CRL &= ~GPIO_CRL_CNF6;
	GPIOA->CRL |= GPIO_CRL_CNF6_1;
	GPIOA->BSRR |= GPIO_BSRR_BS6;
	//кнопка "Menu"
	GPIOA->CRL &= ~GPIO_CRL_MODE7;
	GPIOA->CRL &= ~GPIO_CRL_CNF7;
	GPIOA->CRL |= GPIO_CRL_CNF7_1;
	GPIOA->BSRR |= GPIO_BSRR_BS7;
}

void ProcessKeyFSM(void){
	scan_keyboard();
	switch (key_state){
		case 0:{ //клавиша не нажата
			if (key_code > 0){
				_key_code = key_code;
				ResetTimer(T_Keyboard);
				key_state = 1;
			}
			break;
		}
		case 1:{ //задержка подавления дребезга
			if (GetTimer(T_Keyboard) >= debounce){
				key_state = 2;
			}
			break;
		}
		// при определении короткого / длинного нажатия
		case 2:{
			if (key_code == _key_code){
				ResetTimer(T_Keyboard);
				short_key = key_code;
				//SendMessage(MSG_KEY_PRESSED);
				key_state = 3;
			}
			else{
				key_state = 0;
			}
			break;
		}
		case 3:{
			if (key_code == _key_code){
				if (GetTimer(T_Keyboard) >= first_delay){
					SendMessage(MSG_KEY_PRESSED_LONG, key_code);
					key_state = 0;
				}
			}
			else{
				SendMessage(MSG_KEY_PRESSED, short_key);
				key_code = short_key;
				short_key = 0;
				key_state = 0;
			}
			break;
		}
		//при использовании автоповтора как на компьютерной клавиатуре
/*		case 2:{
			if (key_code == _key_code){
				ResetTimer(T_Keyboard);
				SendMessage(MSG_KEY_PRESSED);
				key_state = 3;
			}
			else{
				key_state = 0;
			}
			break;
		}
		case 3:{
			if (key_code == _key_code){
				if (GetTimer(T_Keyboard) >= first_delay){
					ResetTimer(T_Keyboard);
					SendMessage(MSG_KEY_PRESSED);
					key_state = 4;
				}
			}
			else{
				key_state = 0;
			}
			break;
		}
		case 4:{
			if (key_code == _key_code){
				if (GetTimer(T_Keyboard) >= auto_repeat){
					ResetTimer(T_Keyboard);
					SendMessage(MSG_KEY_PRESSED);
				}
			}
			else{
				key_state = 0;
			}
			break;
		}*/
	}
}

