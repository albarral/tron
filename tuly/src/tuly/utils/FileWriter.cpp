/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tuly/utils/FileWriter.h"

namespace tuly 
{
FileWriter::FileWriter()
{
    bappend = false;    // not append by default
}

bool FileWriter::open(std::string name)
{
    bool bok = false;
    // proceed if not open yet
    if (!file.is_open())
    {        
        if (bappend)
            file.open(name, std::fstream::out | std::fstream::app);
        else
            file.open(name, std::fstream::out);
        
        if (file.is_open())
        {
            filename = name;
            bok = true;
        }
    }
    else 
        bok = true;

    return bok;
}

void FileWriter::writeLine(std::string line)
{
    file << line;
}

void FileWriter::writeFlush(std::string line)
{
    file << line;
    file.flush();
}

void FileWriter::writeFromTop()
{
    file.seekp(0, std::fstream::beg);
}
}