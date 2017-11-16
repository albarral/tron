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
            nowPos = 0;
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

std::string FileReader::readLineSafe()
{  
    if (safeAhead())
    {
        std::string line;    
        std::getline(file, line);
        nowPos = file.tellg();        
        return line;
    }
    else
        return "";
}

bool FileReader::safeAhead()
{
    file.seekg(nowPos, std::fstream::beg);        
    if (file.fail())
        return false;
    else
    {
        if (file.peek() == EOF)
            return false;
        else
            return true;
    }
}

void FileReader::goTop()
{
    // point reader to file beginning
    file.seekg(0, std::fstream::beg);
}

void FileReader::clearStream()
{
    // reset stream 
    file.clear();
}

int FileReader::getPos()
{
    return file.tellg();
}

bool FileReader::isEndReached() 
{
    return file.eof();
}

bool FileReader::isFailed()
{
    return file.fail();    
}
}