/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/tools/FileWriter.h"

namespace tron 
{
FileWriter::FileWriter()
{
    filename = "";        
}

FileWriter::~FileWriter()
{
    close();
}

bool FileWriter::open(std::string name, bool bappend)
{
    // preventive close
    close();

    if (bappend)
        outfile.open(name, std::fstream::out | std::fstream::app);
    else
        outfile.open(name, std::fstream::out);

    if (outfile.is_open())
    {
        filename = name;
        return true;
    }

    return false;
}

bool FileWriter::isOpen()
{
    return (outfile.is_open());
}

bool FileWriter::close()
{
    // proceed if open 
    if (outfile.is_open())
    {        
        outfile.close();
        return true;
    }

    return false;
}

void FileWriter::writeLine(std::string line)
{
    outfile << line;
}

void FileWriter::writeFlush(std::string line)
{
    outfile << line;
    outfile.flush();
}

void FileWriter::goTop()
{
    // point writer to file beginning    
    outfile.seekp(0, std::fstream::beg);
}

void FileWriter::cleanFile()
{
    // open and close file with truncate option
    std::ofstream outfile2;
    outfile2.open(filename, std::fstream::out | std::fstream::trunc);
    if (outfile2.is_open())
        outfile2.close();               
}

}