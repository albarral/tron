/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/ai/PathFinder.h"
#include "tron/diagram/State.h"
#include "tron/diagram/Transition.h"

using namespace log4cxx;

namespace tron
{
LoggerPtr PathFinder::logger(Logger::getLogger("tron.ai"));
    
Path PathFinder::findAleatoryPath(Diagram& oDiagram, int state1, int length)
{
    // create empty path
    Path oPath;
            
    // get origin state
    State* pState = oDiagram.getState(state1);
    if (pState != nullptr)
    {
        int steps = 0;
        // walk through diagram states following random transitions (for a number of steps)
        // do it for a number of steps (specified) or till a "dead end" state reached
        while (steps < length && pState->hasTransitions())
        {
            // select random transition 
            int random = rand() % pState->getNumTransitions();                
            Transition& oTransition = *(pState->getTransition(random));
            // add it to path
            oPath.addTransition(oTransition);           
            // and walk to next state (the one pointed by the selected transition)
            pState = oDiagram.getState(oTransition.getEndStateID());            
            steps++;
        }        
        LOG4CXX_DEBUG(logger, "PathFinder: findAleatoryPath(): path found from state " << state1);
    }
    else                
        LOG4CXX_WARN(logger, "PathFinder: findAleatoryPath() failed, origin state not in diagram! " << state1);
    
    
    return oPath;
}

//Path PathFinder::findShortestPath(Diagram& oDiagram, int state1, int state2)
//{
//    // create empty path
//    Path oPath;
//    // TO DO
//    return oPath;
//}

}