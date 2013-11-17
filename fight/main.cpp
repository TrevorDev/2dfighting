#include <cstdlib>
#include <SDL2/SDL.h>
#include "Input.h"
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include "LTexture.h"

//Screen dimension constants
const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 540;

//Loads media
bool loadMedia(SDL_Renderer* gRenderer);

bool loadMedia(SDL_Renderer* gRenderer)
{
    //Walking animation
    const int WALKING_ANIMATION_FRAMES = 4;
    SDL_Rect gSpriteClips[ WALKING_ANIMATION_FRAMES ];
    LTexture gSpriteSheetTexture;

	//Loading success flag
	bool success = true;

	//Load sprite sheet texture
	if( !gSpriteSheetTexture.loadFromFile( "foo.png",gRenderer))
	{
		printf( "Failed to load walking animation texture!\n" );
		success = false;
	}
	else
	{
		//Set sprite clips
		gSpriteClips[ 0 ].x =   0;
		gSpriteClips[ 0 ].y =   0;
		gSpriteClips[ 0 ].w =  64;
		gSpriteClips[ 0 ].h = 205;

		gSpriteClips[ 1 ].x =  64;
		gSpriteClips[ 1 ].y =   0;
		gSpriteClips[ 1 ].w =  64;
		gSpriteClips[ 1 ].h = 205;

		gSpriteClips[ 2 ].x = 128;
		gSpriteClips[ 2 ].y =   0;
		gSpriteClips[ 2 ].w =  64;
		gSpriteClips[ 2 ].h = 205;

		gSpriteClips[ 3 ].x = 196;
		gSpriteClips[ 3 ].y =   0;
		gSpriteClips[ 3 ].w =  64;
		gSpriteClips[ 3 ].h = 205;
	}

	return success;
}



int main ( int argc, char** argv )
{
    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //The window renderer
    SDL_Renderer* gRenderer = NULL;

    //Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		return 1;
	}

    //Enable VSync
    if( !SDL_SetHint( SDL_HINT_RENDER_VSYNC, "1" ) )
    {
        printf( "Warning: VSync not enabled!" );
    }

    //Set texture filtering to linear
    if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
    {
        printf( "Warning: Linear texture filtering not enabled!" );
    }

    //Create window
    gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( gWindow == NULL )
    {
        printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
        return 1;
    }

    //Create renderer for window
    gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
    if( gRenderer == NULL )
    {
        printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
        return 1;
    }

    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
        return 1;
    }

    Input * inputP1 = new Input("game.conf","PLAYER1");

    // program main loop
    bool done = false;
    while (!done)
    {
        Input::update();
        if(inputP1->getButtonDown("EXIT")){
            done=1;
        }
        // DRAWING STARTS HERE
        //Clear screen
        SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0x00 );
        SDL_RenderClear( gRenderer );

        //Render current frame
        //gSpriteSheetTexture.render( ( SCREEN_WIDTH - gSpriteClips[ frame / 4 ].w ) / 2, ( SCREEN_HEIGHT - gSpriteClips[ frame / 4 ].h ) / 2, &gSpriteClips[ frame / 4 ] );

        //Update screen
        SDL_RenderPresent( gRenderer );
    } // end main loop


    delete inputP1;
    //Free loaded images
	//gSpriteSheetTexture.free();

	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
    // all is well ;)
    printf("Exited cleanly\n");
    return 0;
}
