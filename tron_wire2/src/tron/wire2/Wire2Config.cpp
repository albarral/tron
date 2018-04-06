/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <cstdlib>  // for getenv

#include "tron/wire2/Wire2Config.h"

namespace tron
{    
const std::string Wire2Config::comsBaseFolder = "/coms";   
const std::string Wire2Config::comsFileExtension = ".txt";

// Constructor
Wire2Config::Wire2Config()
{    
    setComsBasePath();
}

void Wire2Config::setComsBasePath()
{
    // coms file located in home folder
    char* pVar = getenv("HOME");    
    if (pVar != NULL)
    {
        std::string home(pVar);
        comsBasePath = home + comsBaseFolder;
    }
    else
        comsBasePath = "";
}

}

