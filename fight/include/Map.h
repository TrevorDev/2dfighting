#ifndef MAP_H
#define MAP_H
#include "Rect.h"
#include <vector>

class Map
{
    public:
        static Map * currentMap;
        std::vector<Rect*> walls;

        static void loadMap(Map * m);
        void draw();
        Map();
        virtual ~Map();
    protected:
    private:
};

#endif // MAP_H
