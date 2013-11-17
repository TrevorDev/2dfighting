#include "Map.h"

Map * Map::currentMap;

Map::Map()
{
    //ctor
}

Map::~Map()
{
    //dtor
}

void Map::loadMap(Map * m){
    delete Map::currentMap;
    Map::currentMap=m;
}

void Map::draw(){
    for (std::vector<Rect *>::iterator it = Map::walls.begin() ; it != Map::walls.end(); ++it){
        (*it)->draw();
    }
}
