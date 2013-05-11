#include "Timer.h"


Timer::Timer(){
	start = time(NULL);
}
void Timer::setTime(){
	time_t now = time(NULL);
	during_time = now - start;
	
	sec = during_time % 60;
	min = during_time / 60;
	hr = during_time / 3600;

	displayTime();
	
}


void Timer::displayTime(){
	mvprintw(20, 0," %d hr %d min %d sec", hr, min, sec);
}


void Timer::stopTime(){
	stop = time(NULL);
	during_time = stop - start;
	sec = during_time % 60;
	min = during_time / 60;
	hr = during_time / 3600;

	mvprintw(20, 0," %d hr %d min %d sec", hr, min, sec);
}
