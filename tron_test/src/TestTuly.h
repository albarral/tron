#ifndef __TRON_TESTTULY_H
#define __TRON_TESTTULY_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <fstream>  // TEST FILE READING
#include <string>
#include <log4cxx/logger.h>

#include "tuly/utils/FileReader.h"
#include "tuly/utils/FileWriter.h"

// Class used to test tuly lib.
class TestTuly
{
private:
    static log4cxx::LoggerPtr logger;
    std::string modName;          // module name

public:
    TestTuly();
    //~TestTuly();

    void makeTest();      
    
private:
    void testMessageQueue();                
    
    // functions to test file handling directly with file streams
    void testFileReading();
    void writeBunch(std::ofstream& file, int i);
    void readEverything(std::ifstream& file);
    void refreshWhenEOF(std::ifstream& file);

    // test file handling with tuly reader and writer
    void testFileReading2();
    void writeLines(tuly::FileWriter& oFileWriter, int i);
    void readLines(tuly::FileReader& oFileReader);    
};
#endif
