/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/ai/Explorer.h"
#include "tron/diagram/Transition.h"

using namespace log4cxx;

namespace tron
{
LoggerPtr Explorer::logger(Logger::getLogger("tron.ai"));
    
Explorer::Explorer() 
{
    status = -1;
    start = target = -1;
}

Explorer::~Explorer()
{
    listPendingTransitions.clear();
}

bool Explorer::init(Diagram& oDiagram, int startState, int targetState)
{
    // set diagram
    Walker::setDiagram(oDiagram);
    // set start position       
    if (Walker::setPosition(startState))
        start = startState;
    else
    {
        LOG4CXX_WARN(logger, "Explorer: init failed! Start state not found in diagram: " << startState);        
        return false;
    }
        
     if (oDiagram.getState(targetState) != nullptr)
        target = targetState;
    else
    {
        LOG4CXX_WARN(logger, "Explorer: init failed! Target state not found in diagram: " << targetState);        
        return false;
    }

    // if all was valid, explorer is active
    status = eSTATUS_ACTIVE;
    return true;
}

bool Explorer::go()
{
    // safety check
    if (Walker::isGrounded())
    {
        int numTransitions = pState->getNumTransitions();
        switch (numTransitions)
        {
            case 0:
                // if no transitions, blocked
                status = eSTATUS_BLOCKED;
                break;
    
            case 1:
                // if single transition, walk it
                walkAndCheck(0);
                break;
                
            default:
                // if multiple transitions, walk first 
                walkAndCheck(0);                                
                // and add rest of them to pending list
                bool bskip = true;
                for (Transition& oTransition : pState->getTransitionsList())
                {
                    // skip first transition (the walked one)
                    if (!bskip)
                        listPendingTransitions.push_back(oTransition.getTransitionPk());
                    else
                        bskip = false;
                }
                break;
        }
        
        // return true if any transition was traversed
        return (status != eSTATUS_BLOCKED);
    }
    else
    {
        LOG4CXX_WARN(logger, "Explorer: go failed, explorer not grounded! ");
        return false;
    }            
}

void Explorer::walkAndCheck(int transition)
{
    // walk given transition
    if (Walker::walk(transition))
    {
        // if target reached, arrived
        if (pState->getStatePk().getStateID() == target)
            status = eSTATUS_ARRIVED;
        // otherwise, stay active
        else
            status = eSTATUS_ACTIVE;
    }
    // if walk failed -> blocked
    else
        status = eSTATUS_BLOCKED;
}

void Explorer::clearPendingTransitions()
{
    listPendingTransitions.clear();
}

}