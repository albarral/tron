/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "TestAI.h"

#include "tron/ai/PathFinder.h"
#include "tron/diagram/State.h"
#include "tron/diagram/Path.h"
#include "tron/diagram/Transition.h"
#include "tron/diagram/TransitionPk.h"

using namespace log4cxx;

LoggerPtr TestAI::logger(Logger::getLogger("tron"));

// Constructor 
TestAI::TestAI()
{    
    modName = "TestAI";
 }

void TestAI::makeTest()
{
    LOG4CXX_INFO(logger, modName + ": test start \n");

    testPathFinder();
        
    LOG4CXX_INFO(logger, modName + ": test end \n");
};

void TestAI::createDiagram()
{
    LOG4CXX_INFO(logger, modName + ": createDiagram ...");
    
    oDiagram.setID(4);
    oDiagram.setName("Diagram4");
    
    oDiagram.addState(1, "s1");
    oDiagram.addState(2, "s2");
    oDiagram.addState(3, "s3");
    oDiagram.addState(4, "s4");
    
    oDiagram.addTransition(1, 2, "s1_s2");
    oDiagram.addTransition(1, 3, "s1_s3");
    oDiagram.addTransition(3, 2, "s3_s2");
    oDiagram.addTransition(2, 4, "s2_s4");
    oDiagram.addTransition(3, 4, "s3_s4");
    
    LOG4CXX_INFO(logger, oDiagram.toString());
}


void TestAI::testPathFinder()
{
    LOG4CXX_INFO(logger, modName + ": testPathFinder ...");

    // diagram creation
    createDiagram();
    tron::Path oPath;
    // find paths from state 1
    for (int i=0; i<5; i++)
    {
        oPath = tron::PathFinder::findAleatoryPath(oDiagram, 1, 3);

        if (!oPath.isEmpty())
        {
            LOG4CXX_INFO(logger, modName + ": path found!");  
            LOG4CXX_INFO(logger, oPath.toString());
        }
    }
}
