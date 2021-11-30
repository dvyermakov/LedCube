#ifndef TIMER_h
#define TIMER_h

#define msec 1
#define sec 1000
#define min 60*sec
#define hour 60*min
#define day 24*hour

#define MAX_TIMERS   1

#define T_FLOOR      0
#define T_FRAME      1


void InitTimers(void);
unsigned int GetTimer(char Timer);
void ResetTimer(char Timer);

#endif
