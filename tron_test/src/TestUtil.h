#ifndef __TRON_TEST_UTIL_H
#define __TRON_TEST_UTIL_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <log4cxx/logger.h>


// Class used to test tron_util lib.
class TestUtil
{
private:
    static log4cxx::LoggerPtr logger;
    std::string modName;          // module name

public:
    TestUtil();
    //~TestUtil();

    void makeTest();      
    
private:
    void testMessageQueue();                    
};
#endif
