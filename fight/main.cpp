#include <cstdlib>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include "Global.h"
#include "Rect.h"
#include "Map.h"
#include "Input.h"
#include "Player.h"
#include "Timer.h"

int main ( int argc, char** argv )
{

    if(Global::init()!=0){
        return 1;
    }

    Player * p1 = new Player(new Input("game.conf","PLAYER1"));
    p1->character=new Character(300,0);
    p1->character->body=new Rect(0,0,30,30);

    Player * p2 = new Player(new Input("game.conf","PLAYER2"));
    p2->character=new Character(350,0);
    p2->character->body=new Rect(0,0,30,30);

    Map::loadMap(new Map());
    Map::currentMap->walls.push_back(new Rect(Global::SCREEN_WIDTH/2-(500/2),Global::SCREEN_HEIGHT*(0.7),500,50));
    Map::currentMap->inMap=new Rect(0,0,Global::SCREEN_WIDTH,Global::SCREEN_HEIGHT);
    Timer delta;
    // program main loop
    bool done = false;
    while (!done)
    {
        Global::deltaSeconds = delta.getDeltaMilliseconds()/1000.f;
        Input::update();
        p1->update();
        //p2->update();
        if(p1->input->getButtonDown("EXIT")){
            done=1;
        }

        // DRAWING STARTS HERE
        SDL_SetRenderDrawColor( Global::gameRenderer, 0x00, 0x00, 0x00, 0x00 );
        SDL_RenderClear( Global::gameRenderer );
        Map::currentMap->draw();
        p1->character->draw();
        //p2->character->draw();
        //Update screen
        SDL_RenderPresent( Global::gameRenderer );
    }




    Global::exit();
    return 0;
}
