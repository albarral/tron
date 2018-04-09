#ifndef __TRON_TEST_DISPLAY_H
#define __TRON_TEST_DISPLAY_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>

// class used to conduct tests
class TestDisplay
{
 private:
     static log4cxx::LoggerPtr logger;
    std::string modName;          // module name

public:
    TestDisplay();
//    ~TestDisplay();

        void makeTest();      

private:    
    void testDrawnDisplay();
    void testChart();
    
};

#endif
