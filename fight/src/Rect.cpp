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

int Rect::checkCollision(Rect a, Rect b, int xMove, int yMove){
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return 0;
    }

    if( topA >= bottomB )
    {
        return 0;
    }

    if( rightA <= leftB )
    {
        return 0;
    }

    if( leftA >= rightB )
    {
        return 0;
    }

    if(xMove>0){
        return leftB-rightA;
    }else if(xMove<0){
        return rightB-leftA;
    }else if(yMove>0){
        return topB-bottomA;
    }else if(yMove<0){
        return bottomB-topA;
    }

    return 1;
}

void Rect::draw(){
    //Render red filled quad
    SDL_SetRenderDrawColor( Global::gameRenderer, 0xFF, 0x00, 0x00, 0xFF );
    SDL_RenderFillRect( Global::gameRenderer, this );
}
