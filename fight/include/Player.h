#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"
#include "Global.h"
#include "Map.h"

class Player
{
    public:
        Character * character;
        Input * input;

        void update();
        Player(Input * i);
        virtual ~Player();
    protected:
    private:
};

#endif // PLAYER_H
