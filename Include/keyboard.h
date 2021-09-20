#ifndef KEYBOARD_h
#define KEYBOARD_h

#define KEY_NONE	0
#define KEY_INC 	1
#define KEY_DEC 	2
#define KEY_OK 		3
#define KEY_MENU 	4

void scan_keyboard(void);

void InitKeyboard(void);
void ProcessKeyFSM(void);

#endif
