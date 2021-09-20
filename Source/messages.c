#include "messages.h"

MSGData Messages[MAX_MESSAGES];

void InitMessages(void){
	char i;
	for (i = 0; i < MAX_MESSAGES; i++){
		Messages[i].Msg = 0;
		Messages[i].Param = 0;
	}
}

void SendMessage(char Msg, char Param){
	Messages[Msg].Msg = 1;
	Messages[Msg].Param = Param;
}

void ProcessMessages(void){
	char i;
	for (i = 0; i < MAX_MESSAGES; i++){
		if (Messages[i].Msg == 2){
			Messages[i].Msg = 0;
			Messages[i].Param = 0;
		}
		if (Messages[i].Msg == 1)
			Messages[i].Msg = 2;
	}
}

char GetMessage(char Msg, char* Param){
	if (Messages[Msg].Msg == 2){		
		Messages[Msg].Msg = 0;
		*Param = Messages[Msg].Param;
		Messages[Msg].Param = 0;
		return 1;
	}
	return 0;
}