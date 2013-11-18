#include "Player.h"

Player::Player(Input * i)
{
    input = i;
}

Player::~Player()
{
    //dtor
}

void Player::update(){
    int moveAcc = 820;
    int jumpPwr = 300;

    this->character->ySpd+=Global::GRAVITY*Global::deltaSeconds;
    if(this->input->getButtonDown("LEFT")){
        this->character->xSpd-=moveAcc*Global::deltaSeconds;
    }
    if(this->input->getButtonDown("RIGHT")){
        this->character->xSpd+=moveAcc*Global::deltaSeconds;
    }
    if(this->input->getButtonDown("UP")){
        this->character->ySpd=-jumpPwr;
    }




    this->character->y+=this->character->ySpd*Global::deltaSeconds;
    this->character->update();
    if(this->character->checkWallCollision()){
        this->character->y-=this->character->ySpd*Global::deltaSeconds;
        this->character->ySpd=0;
    }
    this->character->update();
    this->character->x+=this->character->xSpd*Global::deltaSeconds;
    this->character->update();
    if(this->character->checkWallCollision()){
        this->character->x-=this->character->xSpd*Global::deltaSeconds;
        this->character->xSpd=0;
    }
    this->character->update();
}
