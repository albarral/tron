#ifndef __TRON_TESTCOMY_H
#define __TRON_TESTCOMY_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/


#include <fstream>  // TEST FILE READING
#include <string>
#include <log4cxx/logger.h>

#include "comy/file/ComyFileServer.h"


// Class used to test comy lib.
class TestComy
{
private:
    static log4cxx::LoggerPtr logger;
    std::string modName;          // module name

public:
    TestComy();
    //~TestComy();

    void makeTest();      
    
private:
    void testComsClientServer();                
    void testComsPublishSubscribe();
    void readByServer(comy::ComyFileServer& oComyServer);
    
    void testFileReading();
    void testFileReading2();
    bool safeRead(std::fstream& file, int readPos);
    void refreshWhenEOF(std::ifstream& file);
    
};
#endif
