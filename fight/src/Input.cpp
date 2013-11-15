#include "Input.h"

std::vector<Input*> Input::inputs;

Input::Input(std::string file, std::string settings)
{
    std::string line;
    std::ifstream infile;
	infile.open (file.c_str());
    int found=0;
        while(std::getline(infile, line))
        {
            if(found){
                if(line[0]=='*'){
                    break;
                }
                //HANDLE EACH LINE
                int pos = line.find("=");
                std::string action = line.substr(0,pos);
                std::string key=line.substr(pos+1);
                int keyVal=0;
                if(key.compare("UP")==0){
                    keyVal = SDLK_UP;
                }else if(key.compare("DOWN")==0){
                    keyVal = SDLK_DOWN;
                }else if(key.compare("LEFT")==0){
                    keyVal = SDLK_LEFT;
                }else if(key.compare("RIGHT")==0){
                    keyVal = SDLK_RIGHT;
                }else if(key.compare("ESC")==0){
                    keyVal = SDLK_ESCAPE;
                }else{
                    keyVal=(int)key[0];
                }
                int * val = new int(0);
                actionValueMap[action]=val;
                inputValueMap[keyVal]=val;
            }
            if(line.substr(1).compare(settings)==0){
                found = 1;
            }
        }
	infile.close();
	Input::inputs.push_back(this);
}

Input::~Input()
{
    for (std::map<int,int*>::iterator mit = inputValueMap.begin() ; mit != inputValueMap.end(); ++mit){
            delete (inputValueMap[mit->first]);
    }
}

void Input::update() {
    SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // check for messages
            switch (event.type)
            {
                // check for keypresses
                case SDL_KEYDOWN:
                {
                    for (std::vector<Input *>::iterator it = Input::inputs.begin() ; it != Input::inputs.end(); ++it){
                        Input * input = *it;
                        std::map<int,int*> iMap = input->inputValueMap;
                        for (std::map<int,int*>::iterator mit = iMap.begin() ; mit != iMap.end(); ++mit){
                            if (event.key.keysym.sym == mit->first){
                                (*(iMap[mit->first]))=1;
                            }

                        }
                    }
                    break;
                }
                case SDL_KEYUP:
                {
                    for (std::vector<Input *>::iterator it = Input::inputs.begin() ; it != Input::inputs.end(); ++it){
                        Input * input = *it;
                        std::map<int,int*> iMap = input->inputValueMap;
                        for (std::map<int,int*>::iterator mit = iMap.begin() ; mit != iMap.end(); ++mit){
                            if (event.key.keysym.sym == mit->first)
                                *(mit->second) = 0;
                        }
                    }
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                    std::cout << "test\n";
                    break;
                }
            } // end switch
        } // end of message processing

}

int Input::getButtonDown(std::string action){
    return *(actionValueMap[action]);
}
