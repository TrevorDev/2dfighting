#include "ConfigReader.h"

ConfigReader::ConfigReader()
{
    //ctor
}

ConfigReader::~ConfigReader()
{
    //dtor
}

std::map< std::string,std::map<std::string,std::string>* > ConfigReader::readConfig(std::string file) {
    std::map< std::string,std::map<std::string,std::string>* > ret;
    std::string line;
    std::ifstream infile;
    std::string key = "";

	infile.open (file.c_str());
    while(std::getline(infile, line))
    {
        if(line[0]=='*'){
            key = line.substr(1);
            (ret)[key] = new std::map<std::string,std::string>();
        }else{
            int pos = line.find("=");
            std::string k = line.substr(0,pos);
            std::string v = line.substr(pos+1);
            (*(ret)[key])[k] = v;
        }
    }
    return ret;
}
