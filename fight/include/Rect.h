#ifndef RECT_H
#define RECT_H
#include <SDL2/SDL.h>
#include "Global.h"


class Rect : public SDL_Rect
{
    public:
        void draw();

        Rect(int x, int y, int w, int h);
        virtual ~Rect();
    protected:
    private:
};

#endif // RECT_H
