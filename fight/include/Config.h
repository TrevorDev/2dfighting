#ifndef CONFIG_H
#define CONFIG_H

#include <map>
#include <string>
#include <iostream>
#include <fstream>

class Config
{
    public:
        std::string getSetting(std::string catagory,std::string name);
        Config(std::string file);
        virtual ~Config();

    protected:
    private:
        std::map< std::string,std::map<std::string,std::string>* > config;
};

#endif // CONFIG_H
