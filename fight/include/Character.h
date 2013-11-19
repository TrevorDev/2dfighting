#ifndef CHARACTER_H
#define CHARACTER_H
#include "Rect.h"
#include "Input.h"
#include "Map.h"
#include <vector>
#include <cmath>

class Character
{
    public:
        float x;
        float y;
        float xSpd;
        float ySpd;
        bool grounded;
        Rect * body;
        std::vector<Rect*> hitBoxes;
        std::vector<Rect*> hurtBoxes;

        void update();
        void moveSpd();
        void moveXY(int x, int y);
        void draw();
        int checkWallCollision(int xMove, int yMove);
        Character(float x, float y);
        virtual ~Character();
    protected:
    private:
};

#endif // CHARACTER_H
