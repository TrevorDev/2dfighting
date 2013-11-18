#ifndef TIMER_H
#define TIMER_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <cstdlib>


class Timer
{
    private:

    Uint32 mStartTicks;
    public:

    Timer();
    Uint32 getDeltaMilliseconds();
};

#endif // TIMER_H
