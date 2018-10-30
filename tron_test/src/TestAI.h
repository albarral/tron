#ifndef __TRON_TEST_AI_H
#define __TRON_TEST_AI_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>

#include "tron/diagram/Diagram.h"

// Class used to test tron_ai lib.
class TestAI
{
private:
    static log4cxx::LoggerPtr logger;
    std::string modName;          // module name
    tron::Diagram oDiagram; 

public:
    TestAI();
    //~TestAI();

    void makeTest();      
    
private:
    void createDiagram();
    void testPathFinder();
    void testExplorer();
    void testExploration();
};
#endif
