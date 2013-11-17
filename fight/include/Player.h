#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"

class Player
{
    public:
        Character * character;
        Input * input;

        Player(Input * i);
        virtual ~Player();
    protected:
    private:
};

#endif // PLAYER_H
