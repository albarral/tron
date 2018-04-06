/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <sys/stat.h>

#include "tron/wire2/FileCommunicator.h"
#include "tron/wire2/Wire2Config.h"
#include "tron/tools/FileWriter.h"

namespace tron
{
FileCommunicator::FileCommunicator()
{    
    // get base path for communications
    Wire2Config oComyConfig;    
    basePath = oComyConfig.getComsBasePath();
  
    // create base path (if it doesn't exist)
    if (!basePath.empty())
        mkdir(basePath.c_str(), 0777);
}

void FileCommunicator::setFullPath(std::string fileName)
{        
    fullPath = basePath + "/" + fileName + Wire2Config::comsFileExtension;
}

bool FileCommunicator::createComsFile()
{
    // create physical file by opening it with a writer
    FileWriter oFileWriter;
    oFileWriter.open(fullPath, false);  
    
    if (oFileWriter.isOpen())                   
    {        
       oFileWriter.close();        
       return true;
    }
    else
        return false;
}

}