#ifndef TIMERS_h
#define TIMERS_h

#define msec 1
#define sec 10
#define min 60*sec
#define hour 60*min
#define day 24*hour

#define MAX_TIMERS 8

#define T_BLINK_On 		0
#define T_BLINK_Off 	1
#define T_Keyboard 		2
#define T_Minute			3
#define T_Date				4
#define T_DHT					5
#define T_Dot_On			6
#define T_Dot_Off			7

void InitTimers(void);
unsigned int GetTimer(char Timer);
void ResetTimer(char Timer);

#endif
