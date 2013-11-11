#ifndef INPUT_H
#define INPUT_H
#include <SDL/SDL.h>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

class Input
{
    public:
        static std::vector<Input*> inputs;

        std::map<std::string,int*> actionValueMap;
        std::map<int,int*> inputValueMap;


        static void update();
        Input(std::string file, std::string settings);
        virtual ~Input();
    protected:
    private:
};

#endif // INPUT_H
