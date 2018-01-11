#ifndef __TRON_TESTTIVY_H
#define __TRON_TESTTIVY_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>

// class used to conduct tests
class TestTivy
{
 private:
     static log4cxx::LoggerPtr logger;
    std::string modName;          // module name

public:
    TestTivy();
//    ~TestTivy();

        void makeTest();      

private:    
    void testPlot();
    void testHistoryPlot();
    void testDiscPlot();
    void testDualWindow();
    
};

#endif
