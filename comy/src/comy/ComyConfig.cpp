/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <cstdlib>  // for getenv

#include "comy/ComyConfig.h"

namespace comy
{    
// Constructor
ComyConfig::ComyConfig()
{    
    // coms file located in home folder
    char* pVar = getenv("HOME");    
    if (pVar!=NULL)
    {
        std::string home(pVar);
        // file for client server coms        
        comsFilename1 = home + "/coms/amy_in.txt";
        // file for publish subscribe coms
        comsFilename2 = home + "/coms/amy_pub.txt";
    }
}

std::string ComyConfig::getComsFolder()
{
    // coms file located in home folder
    char* pVar = getenv("HOME");    
    if (pVar!=NULL)
    {
        std::string home(pVar);
        return home + "/coms";
    }
}

}

