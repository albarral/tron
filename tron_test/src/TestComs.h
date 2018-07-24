#ifndef __TRON_TEST_COMS_H
#define __TRON_TEST_COMS_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <functional>

#include <log4cxx/logger.h>

// Class used to test tron_coms lib.
class TestComs
{
private:
    static log4cxx::LoggerPtr logger;
    std::string modName;          // module name

public:
    TestComs();
    //~TestComs();

    void makeTest();      
    
private:
    void analyseMessage(std::string message, std::function<int(std::string)> cb);

    int checkSize(std::string message);       
};
#endif
