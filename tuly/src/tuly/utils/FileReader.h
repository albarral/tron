#ifndef __TULY_FILEREADER_H
#define __TULY_FILEREADER_H

/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <fstream>
#include <string>
#include <vector>

namespace tuly 
{
// Utility class used for file reading
class FileReader
{    
private:
    std::string filename;
    std::ifstream infile;     
    
public:
    FileReader();
    ~FileReader();

    // open file with read permissions
    bool open(std::string name);
    bool isOpen();
    std::string getName() {return filename;}
    bool close();
    
    // reads next line from file
    std::string readLine();
    // reads all lines in file, keeping position if end of file reached
    bool readAllLines(std::vector<std::string>& listLines);
    // clear flags if eof reached
    void refresh();
    
    // clean file contents
    void cleanFile();
    
    // move reader pointer to file's beginning
    void goTop();
    // get reader position in file
    int getPos();
    // checks if end of file was reached
    bool isEndReached();
    // checks if stream is in ok state
    bool isFailed();
    
};

}		
#endif
