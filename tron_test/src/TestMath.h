#ifndef __TRON_TEST_MATH_H
#define __TRON_TEST_MATH_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>

// Class used to test tron_math lib.
class TestMath
{
private:
    static log4cxx::LoggerPtr logger;
    std::string modName;          // module name

public:
    TestMath();
    //~TestMath();

    void makeTest();      
    
private:
    void testArmMath();
};
#endif
