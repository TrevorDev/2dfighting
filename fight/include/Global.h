#ifndef GLOBAL_H
#define GLOBAL_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Config.h"
#include <string>


class Global
{
    public:
        //The window we'll be rendering to
        static SDL_Window* gameWindow;
        //The window renderer
        static SDL_Renderer* gameRenderer;

        //Screen dimension constants
        static int SCREEN_WIDTH;
        static int SCREEN_HEIGHT;
        static int SCREEN_RES_WIDTH;
        static int SCREEN_RES_HEIGHT;
        static std::string CONFIG_FILE;


        static int GRAVITY;
        static float deltaSeconds;

        static int init();
        static void exit();
        Global();
        virtual ~Global();
    protected:
    private:
};

#endif // GLOBAL_H
