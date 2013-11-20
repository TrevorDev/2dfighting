#ifndef CONFIGREADER_H
#define CONFIGREADER_H
#include <map>
#include <string>
#include <iostream>
#include <fstream>

class ConfigReader
{
    public:
        ConfigReader();
        virtual ~ConfigReader();
        static std::map< std::string,std::map<std::string,std::string>* > readConfig(std::string file);
    protected:
    private:
};

#endif // CONFIGREADER_H
