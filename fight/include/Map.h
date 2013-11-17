#ifndef MAP_H
#define MAP_H
#include "Rect.h"
#include <vector>

class Map
{
    public:
        std::vector<Rect*> walls;

        Map();
        virtual ~Map();
    protected:
    private:
};

#endif // MAP_H
