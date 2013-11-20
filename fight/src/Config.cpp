#include "Config.h"

Config::Config(std::string file)
{
    std::string line;
    std::ifstream infile;
    std::string key = "";

	infile.open (file.c_str());
    while(std::getline(infile, line))
    {
        if(line[0]=='*'){
            key = line.substr(1);
            (config)[key] = new std::map<std::string,std::string>();
        }else{
            int pos = line.find("=");
            std::string k = line.substr(0,pos);
            std::string v = line.substr(pos+1);
            (*(config)[key])[k] = v;
        }
    }
}

Config::~Config()
{
    //dtor
}

std::string Config::getSetting(std::string catagory,std::string name){
    return (*(config)[catagory])[name];
}
