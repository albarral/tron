#ifndef __TRON_TEST_TOOLS_H
#define __TRON_TEST_TOOLS_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <fstream>  // TEST FILE READING
#include <string>
#include <log4cxx/logger.h>

#include "tron/tools/FileReader.h"
#include "tron/tools/FileWriter.h"

// Class used to test tron_tools lib.
class TestTools
{
private:
    static log4cxx::LoggerPtr logger;
    std::string modName;          // module name

public:
    TestTools();
    //~TestTools();

    void makeTest();      
    
private:
    // functions to test file handling directly with file streams
    void testFileReading();
    void writeBunch(std::ofstream& file, int i);
    void readEverything(std::ifstream& file);
    void refreshWhenEOF(std::ifstream& file);

    // test file handling with tuly reader and writer
    void testFileReading2();
    void writeLines(tron::FileWriter& oFileWriter, int i);
    void readLines(tron::FileReader& oFileReader);    
};
#endif
