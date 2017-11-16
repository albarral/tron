#ifndef __TRON_TESTTULY_H
#define __TRON_TESTTULY_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>

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
};
#endif
