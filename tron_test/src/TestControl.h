#ifndef __TRON_TEST_CONTROL_H
#define __TRON_TEST_CONTROL_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>

// Class used to test tron_control lib.
class TestControl
{
private:
    static log4cxx::LoggerPtr logger;
    std::string modName;          // module name

public:
    TestControl();
    //~TestControl();

    void makeTest();      
    
private:
    void testControls();
    void testSensors();
    void testAdder();
    void testModule4();
};
#endif
