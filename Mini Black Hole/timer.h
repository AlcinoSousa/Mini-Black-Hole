#ifndef TIMER_H
#define TIMER_H

#include <SDL.h>

/**
	Timer class represents the timers needed to control the game animation
*/


class Timer
{
	 private:
		//stores the ticks at which the timer was started 
		Uint32 mStartTicks;

		//stores the ticks that passed with timer paused
		Uint32 mPausedTicks;

		//possible states, started or paused
		bool mStarted;
		bool mPaused;

    public:
		//default constructor
		Timer();
		
		//starts the timer
		void start();

		//stops the timer
		void stop();

		//pauses the timer
		void pause();

		//unpauses the timer
		void unpause();

		/**
			the current time measured by the timer since start
			@return time measured
		*/
		Uint32 getTicks();
};

#endif