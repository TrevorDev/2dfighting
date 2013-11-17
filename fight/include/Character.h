#ifndef CHARACTER_H
#define CHARACTER_H
#include "Rect.h"
#include "Input.h"
#include <vector>

class Character
{
    public:
        Rect * body;
        std::vector<Rect*> hitBoxes;
        std::vector<Rect*> hurtBoxes;

        void draw();
        Character();
        virtual ~Character();
    protected:
    private:
};

#endif // CHARACTER_H
