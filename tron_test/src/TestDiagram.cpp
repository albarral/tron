/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "TestDiagram.h"

#include "tron/diagram/State.h"
#include "tron/diagram/Path.h"
#include "tron/diagram/Transition.h"
#include "tron/diagram/TransitionPk.h"
#include "tron/diagram/Walker.h"

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

    //testComparisons();
    //testPathCreation();
    testWalker();
        
    LOG4CXX_INFO(logger, modName + ": test end \n");
};

void TestDiagram::createDiagram()
{
    LOG4CXX_INFO(logger, modName + ": createDiagram ...");
    
    oDiagram.setID(4);
    oDiagram.setName("Diagram4");
    
    oDiagram.addState(1, "s1");
    oDiagram.addState(2, "s2");
    oDiagram.addState(3, "s3");
    oDiagram.addState(4, "s4");
    
    oDiagram.addTransition(1, 2, "s1_s2", 1.0);
    oDiagram.addTransition(1, 3, "s1_s3", 1.0);
    oDiagram.addTransition(3, 2, "s3_s2", 1.0);
    oDiagram.addTransition(2, 4, "s2_s4", 1.0);
    oDiagram.addTransition(3, 4, "s3_s4", 1.0);
    
    LOG4CXX_INFO(logger, oDiagram.toString());
}

void TestDiagram::testComparisons()
{
    LOG4CXX_INFO(logger, modName + ": testComparisons ...");
    
    tron::TransitionPk oTransitionPk(4, 3, 2);
    tron::TransitionPk oTransitionPk2(4, 3, 3);
    
    if (oTransitionPk == oTransitionPk2)
    {
        LOG4CXX_INFO(logger, modName + ": equal transition pks ...");        
    }
    else
    {
        LOG4CXX_INFO(logger, modName + ": different transition pks ...");        
    }
}

void TestDiagram::testPathCreation()
{
    LOG4CXX_INFO(logger, modName + ": testPathCreation ...");
    
    // diagram creation
    createDiagram();

    tron::Path oPath; 
        
    // get initial state
    tron::State* pState = oDiagram.getState(1);
    // safety check
    if (pState == nullptr)
        return;
    
    // walk diagram 
    while (oPath.getLength() < 3 && pState->getNumTransitions() > 0)
    {
        // get first available transition
        tron::Transition& oTransition = *(pState->getTransition(0));            
        // walk to next state 
        pState = oDiagram.getState(oTransition.getEndStateID());
        // if valid update the path
        if (pState != nullptr)
            oPath.addTransition(oTransition);                   
        // otherwise, skip
        else
        {
            LOG4CXX_WARN(logger, modName + " wrong state reached! " << oTransition.toString());                
            break;
        }
    }
    
    // show path
    LOG4CXX_INFO(logger, oPath.toString());
    
    LOG4CXX_INFO(logger, modName + " path reduced ...");                
    // reduce path
    oPath.popLast();
    // show path
    LOG4CXX_INFO(logger, oPath.toString());
}

void TestDiagram::testWalker()
{
    LOG4CXX_INFO(logger, modName + ": testWalker ...");

    // diagram creation
    createDiagram();
    
    tron::Walker oWalker;
    oWalker.setDiagram(oDiagram);
    
    // enter walker in a diagram state
    int startState = 1;
    if (!oWalker.enter(startState))
    {
        LOG4CXX_WARN(logger, modName + " could not ground Walker to diagram, enter state = " << startState);                
        return;
    }
    
    // make walker walk until blocked
    bool bwalking = true;
    while (bwalking && oWalker.getNumTransitionsAhead() > 0)
    {
        // take always first transition
        bwalking = oWalker.walk(0);        
    }
    
    // show walked path
    LOG4CXX_INFO(logger, oWalker.getPath().toString());
    
    // now walk back
    LOG4CXX_INFO(logger, modName + " walk back one step ...");              
    // get copy of walked path and remove last transition
    tron::Path oPath = oWalker.getPath(); 
    oPath.popLast();
    // then set reduced path
    oWalker.setNewPath(oPath);
    // show walked path
    LOG4CXX_INFO(logger, oWalker.getPath().toString());    
}
