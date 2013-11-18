#include "Timer.h"

Timer::Timer()
{
    //Initialize the variables
    mStartTicks = 0;
    mStartTicks = SDL_GetTicks();
}

Uint32 Timer::getDeltaMilliseconds()
{
	Uint32 time = 0;
    time = SDL_GetTicks() - mStartTicks;
    mStartTicks = SDL_GetTicks();
    return time;
}
