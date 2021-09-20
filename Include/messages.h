#ifndef MESSAGES_h
#define MESSAGES_h

#define MAX_MESSAGES 2

typedef struct{
	char Msg;
	char Param;
} MSGData;


#define MSG_KEY_PRESSED				0 //нажата любая клавиша
#define MSG_KEY_PRESSED_LONG	1 //нажата любая клавиша



void InitMessages(void);
void SendMessage(char Msg, char Param);
char GetMessage(char Msg, char* Param);
void ProcessMessages(void);

#endif
