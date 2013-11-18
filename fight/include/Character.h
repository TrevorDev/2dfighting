#ifndef CHARACTER_H
#define CHARACTER_H
#include "Rect.h"
#include "Input.h"
#include "Map.h"
#include <vector>

class Character
{
    public:
        float x;
        float y;
        float xSpd;
        float ySpd;
        Rect * body;
        std::vector<Rect*> hitBoxes;
        std::vector<Rect*> hurtBoxes;

        void update();
        void draw();
        bool checkWallCollision();
        Character(float x, float y);
        virtual ~Character();
    protected:
    private:
};

#endif // CHARACTER_H
