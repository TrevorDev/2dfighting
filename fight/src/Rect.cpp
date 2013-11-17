#include "Rect.h"

Rect::Rect(int x, int y, int w, int h)
{
    this->x=x;
    this->y=y;
    this->w=w;
    this->h=h;
}

Rect::~Rect()
{
    //dtor
}

void Rect::draw(){
    //Render red filled quad
    SDL_SetRenderDrawColor( Global::gameRenderer, 0xFF, 0x00, 0x00, 0xFF );
    SDL_RenderFillRect( Global::gameRenderer, this );
}
