/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "TestDiagram.h"

#include "tron/diagram/Diagram.h"

using namespace log4cxx;

LoggerPtr TestDiagram::logger(Logger::getLogger("tron"));

// Constructor 
TestDiagram::TestDiagram()
{    
    modName = "TestDiagram";
 }

void TestDiagram::makeTest()
{
    LOG4CXX_INFO(logger, modName + ": test start \n");

    testDiagramCreation();
        
    LOG4CXX_INFO(logger, modName + ": test end \n");
};

void TestDiagram::testDiagramCreation()
{
    LOG4CXX_INFO(logger, modName + ": testDiagramCreation ...");
    
    tron::Diagram oDiagram(4, "Diagram4");
    
    oDiagram.addState(1, "s1");
    oDiagram.addState(2, "s2");
    oDiagram.addState(3, "s3");
    oDiagram.addState(4, "s4");
    
    oDiagram.addTransition(1, 2, 1, "s1_s2");
    oDiagram.addTransition(1, 3, 1, "s1_s3");
    oDiagram.addTransition(3, 2, 1, "s3_s2");
    oDiagram.addTransition(2, 4, 1, "s2_s4");
    oDiagram.addTransition(3, 4, 1, "s3_s4");
    
    LOG4CXX_INFO(logger, oDiagram.toString());
}
