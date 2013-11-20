#include "Character.h"

Character::Character(float x, float y)
{
    this->x=x;
    this->y=y;
    this->xSpd=0;
    this->ySpd=0;

    jumpPwr = 300;
    jumpCount=0;
    maxJumps=2;

    grounded=false;
}

Character::~Character()
{

}

void Character::update(){
    this->body->x=this->x;
    this->body->y=this->y;
}

void Character::moveSpd(){
    int delta;
    if(abs(this->ySpd*Global::deltaSeconds)>0){
        grounded=false;
    }
    this->moveXY(0,this->ySpd*Global::deltaSeconds);
    if(delta = this->checkWallCollision(0,this->ySpd*Global::deltaSeconds)){
        if(delta<0){
            jumpCount=0;
            grounded=true;
        }
        this->moveXY(0,delta);
        this->ySpd=0;
    }
    this->moveXY(this->xSpd*Global::deltaSeconds,0);
    if(delta = this->checkWallCollision(this->xSpd*Global::deltaSeconds,0)){
        this->moveXY(delta,0);
        this->xSpd=0;
    }
}

void Character::moveXY(int x, int y){
    this->x+=x;
    this->y+=y;
    update();
}

void Character::setXY(int x, int y){
    this->x=x;
    this->y=y;
    update();
}

void Character::reset(){
        ySpd=0;
        xSpd=0;
        jumpCount=0;
}

void Character::jump(){
        ySpd=-jumpPwr;
}

void Character::waveDash(){
    ySpd=jumpPwr*2;
}

void Character::draw(){
    this->body->draw();
}

int Character::checkWallCollision(int xMove, int yMove){
    int ret;
    //COLLISION
    for (std::vector<Rect*>::iterator it = Map::currentMap->walls.begin() ; it != Map::currentMap->walls.end(); ++it){
           if(ret = Rect::checkCollision(*(this->body),*(*it),xMove,yMove)){
                return ret;
           }
    }
    return 0;
}
