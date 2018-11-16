#ifndef __TRON_TOOLS_FILEWRITER_H
#define __TRON_TOOLS_FILEWRITER_H

/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <fstream>
#include <string>

namespace tron 
{
// Utility class used for file writing
class FileWriter
{
private:
    std::string filename;
    std::ofstream outfile;     
    
public:
    FileWriter();
    ~FileWriter();

    // open file with write permissions (append mode by default)
    bool open(std::string name, bool bappend = true);
    bool isOpen();
    std::string getName() {return filename;}
    bool close();

    // writes the given string into the file (delayed writing, done at file closing)
    void writeLine(std::string);
    // writes the given string into the file (immediate writing, done now)
    void writeFlush(std::string);
    // move writer pointer to file's beginning
    void goTop();
    
    // clean file contents
    void cleanFile();    
};

}		
#endif
