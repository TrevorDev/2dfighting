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


int main ( int argc, char** argv )
{

    if(Global::init()!=0){
        return 1;
    }

    Player * p1 = new Player(new Input("game.conf","PLAYER1"));
    p1->character=new Character();
    p1->character->body=new Rect(0,0,20,20);

    Map::loadMap(new Map());
    Map::currentMap->walls.push_back(new Rect(Global::SCREEN_WIDTH/2-(500/2),Global::SCREEN_HEIGHT*(0.7),500,50));


    // program main loop
    bool done = false;
    while (!done)
    {
        Input::update();
        if(p1->input->getButtonDown("EXIT")){
            done=1;
        }

        // DRAWING STARTS HERE
        SDL_SetRenderDrawColor( Global::gameRenderer, 0x00, 0x00, 0x00, 0x00 );
        SDL_RenderClear( Global::gameRenderer );
        Map::currentMap->draw();
        p1->character->draw();
        //Update screen
        SDL_RenderPresent( Global::gameRenderer );
    }




    Global::exit();
    return 0;
}
