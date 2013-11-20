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

    this->character->ySpd+=Global::GRAVITY*Global::deltaSeconds;
    if(this->input->getButtonDown("LEFT")){
        this->character->xSpd-=moveAcc*Global::deltaSeconds;
    }
    if(this->input->getButtonDown("RIGHT")){
        this->character->xSpd+=moveAcc*Global::deltaSeconds;
    }

    //jumping
    if(this->input->getButtonDown("UP")){
        if(character->jumpCount%2==0){
            if(character->maxJumps*2>character->jumpCount){
                character->jump();
                character->jumpCount++;
            }
        }
    }else{
        if(character->jumpCount%2==1){
            character->jumpCount++;
        }
    }

    if(this->input->getButtonDown("DOWN")){
        this->character->waveDash();
    }


    this->character->moveSpd();

    //check character died
    if(!Rect::checkCollision(*character->body, *Map::currentMap->inMap)){
        this->character->setXY(5,5);
        this->character->reset();
    }

}
