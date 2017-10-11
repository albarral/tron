#ifndef __TULY_FILEWRITER_H
#define __TULY_FILEWRITER_H

/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tuly/utils/File.h"

namespace tuly 
{
// Utility class used for file writing
// Derives from base class File    
class FileWriter : public File
{
private:
    bool bappend;   // append flag (to write from the last line)
    
public:
    FileWriter();
    //~FileWriter();

    // set flag for appending mode (write at the end)
    void setAppendMode(bool value) {bappend = value;};
    // open file with write permissions
    virtual bool open(std::string name);
    // writes the given string into the file (delayed writing, done at file closing)
    void writeLine(std::string);
    // writes the given string into the file (immediate writing, done now)
    void writeFlush(std::string);
    // move writer pointer to file's beginning
    void writeFromTop();
};

}		
#endif
