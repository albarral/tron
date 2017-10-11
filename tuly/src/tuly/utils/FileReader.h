#ifndef __TULY_FILEREADER_H
#define __TULY_FILEREADER_H

/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tuly/utils/File.h"

namespace tuly 
{
// Utility class used for file reading
// Derives from base class File    
class FileReader : public File
{    
public:
    //FileReader();
    //~FileReader();

    // open file with read permissions
    virtual bool open(std::string name);
    // reads next line from file
    std::string readLine();
    // move reader pointer to file's beginning
    void readFromTop();
    // get reader position in file
    int getPos();
    // checks if end of file was reached
    bool isEndReached();
    // checks if stream is in ok state
    bool isStreamOk();
    
};

}		
#endif
