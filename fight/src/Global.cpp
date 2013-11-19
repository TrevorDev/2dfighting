#include "Global.h"

SDL_Window* Global::gameWindow;
SDL_Renderer* Global::gameRenderer;
int Global::SCREEN_WIDTH;
int Global::SCREEN_HEIGHT;
int Global::SCREEN_RES_WIDTH;
int Global::SCREEN_RES_HEIGHT;
int Global::GRAVITY;
float Global::deltaSeconds;

Global::Global()
{
    //ctor
}

Global::~Global()
{
    //dtor
}

int Global::init(){
    Global::SCREEN_WIDTH=960;
    Global::SCREEN_HEIGHT=540;
    Global::SCREEN_RES_WIDTH=960;
    Global::SCREEN_RES_HEIGHT=540;

    Global::GRAVITY=840;

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
    Global::gameWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Global::SCREEN_RES_WIDTH, Global::SCREEN_RES_HEIGHT, SDL_WINDOW_SHOWN);
    if( Global::gameWindow == NULL )
    {
        printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
        return 1;
    }

    //Create renderer for window
    Global::gameRenderer = SDL_CreateRenderer( Global::gameWindow, -1, SDL_RENDERER_ACCELERATED );
    if( Global::gameRenderer == NULL )
    {
        printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
        return 1;
    }
    SDL_RenderSetScale(gameRenderer,(float)Global::SCREEN_RES_WIDTH/(float)Global::SCREEN_WIDTH,(float)Global::SCREEN_RES_HEIGHT/(float)Global::SCREEN_HEIGHT);

    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
        return 1;
    }

    return 0;
}

void Global::exit(){
    //Destroy window
	SDL_DestroyRenderer( Global::gameRenderer );
	SDL_DestroyWindow( Global::gameWindow );

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}
