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
private:
    int nowPos;    // next read position
public:
    //FileReader();
    //~FileReader();

    // open file with read permissions
    virtual bool open(std::string name);
    // reads next line from file
    std::string readLine();
    // reads next line from file, keeping position if end of file reached
    std::string readLineSafe();
    // move reader pointer to file's beginning
    void goTop();
    // clear file stream
    void clearStream();
    // get reader position in file
    int getPos();
    // checks if end of file was reached
    bool isEndReached();
    // checks if stream is in ok state
    bool isFailed();
    // checks if next read position is safe
    bool safeAhead();
    
};

}		
#endif
