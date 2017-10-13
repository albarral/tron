/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <cstdlib>  // for getenv

#include "comy/ComyConfig.h"

namespace comy
{    
const std::string ComyConfig::comsFolder = "/coms";   
const std::string ComyConfig::comsFilenameCS = "channel_CS.txt";
const std::string ComyConfig::comsFilenamePS = "channel_PS.txt";

// Constructor
ComyConfig::ComyConfig()
{    
    std::string comsPath = getComsPath();
    if (!comsPath.empty())
    {
        // path for client server communications        
        comsPathCS = comsPath + "/" + comsFilenameCS;
        // path for publish subscribe communications
        comsPathPS = comsPath + "/" + comsFilenamePS;
    }
    else
    {
        comsPathCS = "";
        comsPathPS = "";        
    }
}

std::string ComyConfig::getComsPath()
{
    // coms file located in home folder
    char* pVar = getenv("HOME");    
    if (pVar != NULL)
    {
        std::string home(pVar);
        return home + comsFolder;
    }
    else
        return "";
}

}

