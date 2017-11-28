#ifndef __TRON_TESTMATY_H
#define __TRON_TESTMATY_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>

// Class used to test maty lib.
class TestMaty
{
private:
    static log4cxx::LoggerPtr logger;
    std::string modName;          // module name

public:
    TestMaty();
    //~TestMaty();

    void makeTest();      
    
private:
    void testArmMath();
};
#endif
