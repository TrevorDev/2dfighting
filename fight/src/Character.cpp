#include "Character.h"

Character::Character()
{
    //ctor
}

Character::~Character()
{
    //dtor
}

void Character::draw(){
    this->body->draw();
}
