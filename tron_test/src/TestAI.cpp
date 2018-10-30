/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <vector>

#include "TestAI.h"

#include "tron/ai/Exploration.h"
#include "tron/ai/Explorer.h"
#include "tron/ai/PathFinder.h"
#include "tron/diagram/Path.h"
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

    //testPathFinder();
    //testExplorer();
    testExploration();
        
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
    oDiagram.addState(5, "s5");
    
    oDiagram.addTransition(1, 2, "s1_s2");
    oDiagram.addTransition(1, 3, "s1_s3");
    oDiagram.addTransition(2, 4, "s2_s4");
    oDiagram.addTransition(2, 5, "s2_s5");
    oDiagram.addTransition(3, 2, "s3_s2");
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
    for (int i=0; i<10; i++)
    {
        oPath = tron::PathFinder::findAleatoryPath(oDiagram, 1, 3);

        if (!oPath.isEmpty())
        {
            LOG4CXX_INFO(logger, modName + ": path found!");  
            LOG4CXX_INFO(logger, oPath.toString());
        }
    }
}


void TestAI::testExplorer()
{
    LOG4CXX_INFO(logger, modName + ": testExplorer ...");

    // diagram creation
    createDiagram();
    
    tron::Explorer oExplorer;
    int start = 1;
    int target = 5;
    if (oExplorer.init(oDiagram, start, target) == false)
        return;
    
    while (oExplorer.isActive())
        oExplorer.advance();
    
    switch (oExplorer.getSatus())
    {
        case tron::Explorer::eSTATUS_BLOCKED:
            LOG4CXX_INFO(logger, modName + ": explorer blocked");  
            break;
        case tron::Explorer::eSTATUS_ARRIVED:
            LOG4CXX_INFO(logger, modName + ": explorer arrived");  
            break;
    }

    if (!oExplorer.getPath().isEmpty())
    {
        LOG4CXX_INFO(logger, oExplorer.getPath().toString());
    }

    LOG4CXX_INFO(logger, modName + ": ignored transitions ...");  
    for (tron::TransitionPk& oTransitionPk : oExplorer.getIgnoredTransitions())
    {
        LOG4CXX_INFO(logger, oTransitionPk.toString());
    }
}


void TestAI::testExploration()
{
    LOG4CXX_INFO(logger, modName + ": testExploration ...");

    // diagram creation
    createDiagram();
    
    int start = 1;
    int target = 5;
    std::vector<tron::Path> listPaths = tron::Exploration::explore(oDiagram, start, target);

    if (!listPaths.empty())
    {
        for (tron::Path& oPath : listPaths)
        {
            LOG4CXX_INFO(logger, oPath.toString());
        }
    }

}
