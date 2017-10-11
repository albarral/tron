#ifndef __TULY_FILE_H
#define __TULY_FILE_H

/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <fstream>
#include <string>

namespace tuly 
{
// Base class used for file handling
class File
{
protected:
    std::string filename;
    std::fstream file;     

public:
    File();
    //~File();

    virtual bool open(std::string name) = 0;
    bool isOpen();
    std::string getName() {return filename;}
    bool close();
};

}		
#endif
