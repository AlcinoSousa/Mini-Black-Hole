#include "timer.h"

//default constructor
Timer::Timer()
{
    mStartTicks = 0;
    mPausedTicks = 0;
    mPaused = false;
    mStarted = false;
}

//starts the timer
void Timer::start()
{
    mStarted = true;
    mPaused = false;
    //get the current ticks from SDL
    mStartTicks = SDL_GetTicks();
	//no paused ticks
	mPausedTicks = 0;
}

//stops the timer
void Timer::stop()
{
    mStarted = false;
    mPaused = false;
	//clear ticks
	mStartTicks = 0;
	mPausedTicks = 0;
}

//pauses the timer
void Timer::pause()
{
    if( mStarted && !mPaused )
    {
        mPaused = true;
		//calculate the ticks at which the timer was paused since start
        mPausedTicks = SDL_GetTicks() - mStartTicks;
		mStartTicks = 0;
    }
}

//unpauses the timer
void Timer::unpause()
{
    if( mStarted && mPaused )
    {
        mPaused = false;
        //reset the start ticks
        mStartTicks = SDL_GetTicks() - mPausedTicks;
        mPausedTicks = 0;
    }
}

//the current time
Uint32 Timer::getTicks()
{
	Uint32 time = 0;

    if(mStarted)
    {
        if(mPaused)
        {
            //return the number of ticks when the timer was paused
            time = mPausedTicks;
        }
        else
        {
            //return the current time minus the start time
            time = SDL_GetTicks() - mStartTicks;
        }
    }

    return time;
}