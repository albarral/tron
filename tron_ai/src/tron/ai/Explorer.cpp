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
    // walk the selected transition
    bool bwalked = walk(transitionID);
    updateStatus(bwalked);        

    return bwalked;
}

bool Explorer::advance()
{
    // try advancing if not yet arrived (retry if blocked for if new transitions appeared)
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
            bwalked = walk(0);
            updateStatus(bwalked);
            break;

        default:
            // if multiple transitions, select one to walk and store the ignored ones 
            int selected = 0;   // select first available transition            
            for (Transition& oTransition : pState->getTransitionsList())
            {
                // store all except the selected one
                if (oTransition.getTransitionPk().getTransitionID() != selected)
                    listIgnoredTransitions.push_back(oTransition.getTransitionPk());
            }

            // walk the selected transition
            bwalked = walk(selected);
            updateStatus(bwalked);
            break;
    }

    return bwalked;
}


void Explorer::updateStatus(bool bwalked)
{
    // if walked
    if (bwalked)
        // if target reached -> arrived
        // otherwise -> active
        status = (oPath.getEnd() == target ? eSTATUS_ARRIVED : eSTATUS_ACTIVE);
    // otherwise -> blocked
    else
        status = eSTATUS_BLOCKED;
}


void Explorer::clearIgnoredTransitions()
{
    listIgnoredTransitions.clear();
}

}