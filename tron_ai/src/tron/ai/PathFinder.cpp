/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/ai/PathFinder.h"
#include "tron/diagram/State.h"
#include "tron/diagram/Transition.h"
#include "tron/diagram/Walker.h"

using namespace log4cxx;

namespace tron
{
LoggerPtr PathFinder::logger(Logger::getLogger("tron.ai"));
    
Path PathFinder::findAleatoryPath(Diagram& oDiagram, int state1, int length)
{
    // create diagram walker
    Walker oWalker;
    oWalker.setDiagram(oDiagram);
    // set start position       
    if (oWalker.setPosition(state1))
    {
        int steps = 0;
        bool bwalking;        
        // walk through diagram states following random transitions
        // do it for a number of steps (specified) or till a "dead end" state reached
        do
        {
            // select random transition 
            float random = (float)std::rand() / RAND_MAX;             
            int transition = oWalker.getState()->getNumTransitions() * random;
            LOG4CXX_DEBUG(logger, "PathFinder: findAleatoryPath(): state " << oWalker.getState()->getStatePk().getStateID() << ", trans " << transition);        
            // and walk through it 
            bwalking = oWalker.walk(transition);
            steps++;                         
        }
        while (steps < length && bwalking);
    }
    else
        LOG4CXX_WARN(logger, "PathFinder: findAleatoryPath() failed, origin state not in diagram! " << state1);    
    
    return oWalker.getPath();
}

//Path PathFinder::findShortestPath(Diagram& oDiagram, int state1, int state2)
//{
//    // create empty path
//    Path oPath;
//    // TO DO
//    return oPath;
//}

}