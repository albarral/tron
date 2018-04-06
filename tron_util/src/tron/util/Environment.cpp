/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/util/Environment.h"

namespace tron 
{
std::string Environment::getHomePath()
{    
    // obtain value of HOME environment variable
    char* pVar = getenv("HOME");    
    if (pVar!=NULL)
    {
        // transform it in a string
        std::string home(pVar);
        return home;
    }
    else
        return "";
}
    
void Environment::cleanFolder(std::string path)
{
    std::string command = "exec rm " + path + "/*";
    system(command.c_str());
}      
}