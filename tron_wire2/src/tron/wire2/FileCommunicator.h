#ifndef __TRON_WIRE2_FILECOMMUNICATOR_H
#define __TRON_WIRE2_FILECOMMUNICATOR_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

namespace tron
{
// Base class used for file based communications.
class FileCommunicator
{    
protected:
    const char delimiter = '\n'; // newline used as delimiter for strings (default used by std::getline())
    std::string basePath;    // base path of coms file (common for all channels)       
    std::string fullPath;       // full path of coms file 
    
public:
    FileCommunicator();

    std::string getFullPath() {return fullPath;};

protected:    
    void setFullPath(std::string fileName);    
    // force creation of coms file
    bool createComsFile();
    
};
}
#endif
