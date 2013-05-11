#include <ctime>
#include <ncurses.h>


class Timer{
	public:
		Timer();
		void setTime();
		void stopTime();
		void displayTime();

	private:
		time_t start;
		time_t stop;
		time_t during_time;
		int sec, min, hr;


};
