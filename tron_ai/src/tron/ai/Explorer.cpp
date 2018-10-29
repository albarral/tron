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
    target = -1;
}

Explorer::~Explorer()
{
    listIgnoredTransitions.clear();
}

bool Explorer::init(Diagram& oDiagram, int startState, int targetState)
{
    // check target validity 
    if (oDiagram.getState(targetState) != nullptr)        
        target = targetState;
    else
    {
        LOG4CXX_WARN(logger, "Explorer: init failed! Target state not found in diagram: " << targetState);        
        return false;
    }
    
    // check origin validity 
    if (oDiagram.getState(startState) != nullptr)        
    {
        // set diagram
        Walker::setDiagram(oDiagram);
        // and enter start position       
        bool bok = Walker::enter(startState);        

        // if all was valid, explorer is active
        if (bok)
            status = eSTATUS_ACTIVE;

        return bok;
    }
    else
    {
        LOG4CXX_WARN(logger, "Explorer: init failed! Start state not found in diagram: " << startState);        
        return false;
    }
}

bool Explorer::advance(int transitionID)
{
    // try advancing if not yet arrived (retry if blocked for if new transitions appeared)
    if (Walker::isGrounded() && status != eSTATUS_ARRIVED)
    {
        bool bwalked = false;
        int numTransitions = pState->getNumTransitions();
        switch (numTransitions)
        {
            case 0:
                // if no transitions, blocked
                status = eSTATUS_BLOCKED;
                break;
    
            case 1:
                // if single transition, walk it
                bwalked = walkAndCheck(transitionID);
                break;
                
            default:
                // if multiple transitions, store the ignored ones 
                for (Transition& oTransition : pState->getTransitionsList())
                {
                    // store all except the selected one
                    if (oTransition.getTransitionPk().getTransitionID() != transitionID)
                        listIgnoredTransitions.push_back(oTransition.getTransitionPk());
                }
                
                // walk the selected transition
                bwalked = walkAndCheck(transitionID);                                
                break;
        }
        
        // return true if walked
        return bwalked;
    }
    else
    {
        LOG4CXX_WARN(logger, "Explorer: go failed, not grounded! ");
        return false;
    }            
}

bool Explorer::walkAndCheck(int transitionID)
{
    // walk given transition
    if (Walker::walk(transitionID))
    {
        // if target reached, arrived
        if (oPath.getEnd() == target)
            status = eSTATUS_ARRIVED;
        // otherwise, stay active
        else
            status = eSTATUS_ACTIVE;
        
        return true;
    }
    // if walk failed -> blocked
    else
    {
        status = eSTATUS_BLOCKED;
        return false;
    }
}

void Explorer::clearIgnoredTransitions()
{
    listIgnoredTransitions.clear();
}

}