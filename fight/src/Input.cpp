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
                if(key.compare("UP")){
                    keyVal = SDLK_UP;
                }
                int * val = new int(0);
                actionValueMap[action]=val;
                inputValueMap[keyVal]=val;
                std::cout<<action+"-"+key+"\n";

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
    //dtor
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
                    // exit if ESCAPE is pressed
                    for (std::vector<Input *>::iterator it = Input::inputs.begin() ; it != Input::inputs.end(); ++it){
                        Input * input = *it;
                        std::map<int,int*> iMap = input->inputValueMap;
                    }
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                    std::cout << "test\n";
                    break;
                }
            } // end switch
        } // end of message processing

}
