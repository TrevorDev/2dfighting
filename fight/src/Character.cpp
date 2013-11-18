#include "Character.h"

Character::Character(float x, float y)
{
    this->x=x;
    this->y=y;
    this->xSpd=0;
    this->ySpd=0;
}

Character::~Character()
{

}

void Character::update(){
    this->body->x=this->x;
    this->body->y=this->y;
}


void Character::draw(){
    this->body->draw();
}

bool Character::checkWallCollision(){
    //COLLISION
    for (std::vector<Rect*>::iterator it = Map::currentMap->walls.begin() ; it != Map::currentMap->walls.end(); ++it){
           if(Rect::checkCollision(*(this->body),*(*it))){
                return true;
           }
    }
    return false;
}
