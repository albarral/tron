#ifndef __TRON_TEST_DIAGRAM_H
#define __TRON_TEST_DIAGRAM_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>

#include "tron/diagram/Diagram.h"

// Class used to test tron_diagram lib.
class TestDiagram
{
private:
    static log4cxx::LoggerPtr logger;
    std::string modName;          // module name
    tron::Diagram oDiagram; 

public:
    TestDiagram();
    //~TestDiagram();

    void makeTest();      
    
private:
    void createDiagram();
    void testComparisons();
    void testPathCreation();
    void testWalker();

};
#endif
