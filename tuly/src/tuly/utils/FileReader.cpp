/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tuly/utils/FileReader.h"

namespace tuly 
{
bool FileReader::open(std::string name)
{
    bool bok = false;
    // proceed if not open yet
    if (!file.is_open())
    {        
        file.open(name, std::fstream::in);
        
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
        
std::string FileReader::readLine()
{
    std::string line;    
    std::getline(file, line);

    return line;
}

void FileReader::readFromTop()
{
    // reset stream if something failed
    if (!isStreamOk())
        file.clear();
    
    // then point to file beginning
    file.seekg(0, std::fstream::beg);
}

int FileReader::getPos()
{
    int pos = file.tellg();
    return pos;
}

bool FileReader::isEndReached() 
{
    return file.eof();
}

bool FileReader::isStreamOk()
{
    return (file.fail() == false);
    
}
}