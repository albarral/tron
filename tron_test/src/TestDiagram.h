#ifndef __TRON_TEST_DIAGRAM_H
#define __TRON_TEST_DIAGRAM_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>

// Class used to test tron_control lib.
class TestDiagram
{
private:
    static log4cxx::LoggerPtr logger;
    std::string modName;          // module name

public:
    TestDiagram();
    //~TestDiagram();

    void makeTest();      
    
private:
    void testDiagramCreation();
};
#endif
