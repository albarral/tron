/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <cstdlib>  // for getenv

#include "comy/ComyConfig.h"

namespace comy
{    
const std::string ComyConfig::comsBaseFolder = "/coms";   
const std::string ComyConfig::comsFileExtension = ".txt";

// Constructor
ComyConfig::ComyConfig()
{    
    setComsBasePath();
}

void ComyConfig::setComsBasePath()
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

