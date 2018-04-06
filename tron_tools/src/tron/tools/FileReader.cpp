/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/tools/FileReader.h"

namespace tron 
{
FileReader::FileReader()
{
    filename = "";        
}

FileReader::~FileReader()
{
    close();
}

bool FileReader::open(std::string name)
{    
    // preventive close
    close();

    infile.open(name, std::fstream::in);

    if (infile.is_open())
    {
        filename = name;
        return true;
    }

    return false;
}

bool FileReader::isOpen()
{
    return (infile.is_open());
}

bool FileReader::close()
{
    // proceed if open 
    if (infile.is_open())
    {        
        infile.close();
        return true;
    }

    return false;
}

std::string FileReader::readLine()
{
    std::string line;    
    std::getline(infile, line);

    return line;
}

bool FileReader::readAllLines(std::vector<std::string>& listLines)
{          
    bool bread = false;
    std::string line;    
    while (std::getline(infile, line))
    {
        listLines.push_back(line);
        bread = true;
    }
    // refresh as eof is reached
    refresh();
    
    return (bread);
}

void FileReader::refresh()
{
    // if eof reached, clear flags
    if (infile.eof())
        infile.clear();    
}

void FileReader::cleanFile()
{
    // open and close file with truncate option
    std::ofstream outfile;
    outfile.open(filename, std::fstream::out | std::fstream::trunc);
    if (outfile.is_open())
        outfile.close();               
}

void FileReader::goTop()
{
    // point reader to file beginning
    infile.seekg(0, std::fstream::beg);
}

int FileReader::getPos()
{
    return infile.tellg();
}

bool FileReader::isEndReached() 
{
    return infile.eof();
}

bool FileReader::isFailed()
{
    return infile.fail();    
}
}