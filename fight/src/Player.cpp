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

    if(this->input->getButtonDown("DOWN")){
        this->character->ySpd=jumpPwr*2;
    }


    this->character->moveSpd();


}
