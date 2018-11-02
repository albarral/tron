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
    ID = 0;
    status = -1;
    target = -1;
    boriented = false;
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
        {
            status = eSTATUS_ACTIVE;
            boriented = false;            
        }

        return bok;
    }
    else
    {
        LOG4CXX_WARN(logger, "Explorer: init failed! Start state not found in diagram: " << startState);        
        return false;
    }
}

void Explorer::orient(int transitionID)
{
    // set oriented mode and next transition to walk
    boriented = true;
    this->transitionID = transitionID;
}

bool Explorer::advance()
{
    int numTransitions = pState->getNumTransitions();

    // if no transitions -> blocked
    if (numTransitions == 0)
    {
        status = eSTATUS_BLOCKED;
        return false;
    }
    // otherwise, try advancing 
    else
    {
        bool bwalked = false;                
        // if oriented mode, walk the specified transition
        if (boriented)
        {
            bwalked = walk(transitionID);
            updateStatus(bwalked);
            // and set free mode again
            boriented = false;
        }
        // if free mode 
        else
        {
            // if single transition, walk it
            if (numTransitions == 1)
            {
                bwalked = walk(0);
                updateStatus(bwalked);
            }
            // if multiple transitions, select one to walk and store the ignored ones
            else
            {    
                // select first transition (by now)
                int selected = 0;  
                State* pPrevState = pState;
                // walk it
                bwalked = walk(selected);
                updateStatus(bwalked);                        
                // store ignored transitions
                for (Transition& oTransition : pPrevState->getTransitionsList())
                {
                    // skip the selected one
                    if (oTransition.getTransitionPk().getTransitionID() != selected)
                        listIgnoredTransitions.push_back(oTransition.getTransitionPk());
                }
            }
        }
        return bwalked;        
    }
}

void Explorer::updateStatus(bool bwalked)
{
    // if walked and ...
    // target reached -> arrived
    // otherwise -> active
    if (bwalked)
        status = (oPath.getEnd() == target ? eSTATUS_ARRIVED : eSTATUS_ACTIVE);
}


void Explorer::clearIgnoredTransitions()
{
    listIgnoredTransitions.clear();
}

std::string Explorer::shortDesc()
{
    std::string text = "explorer " + std::to_string(ID);
    if (bgrounded)    
    {
        // show state name
        text += " [" + pState->getName() + "]";
        // show orientation (if oriented)
        if (boriented)
            text += std::to_string(transitionID);
    }        
    return text;
}

std::string Explorer::statusDesc(int status)
{
    switch (status)
    {
        case eSTATUS_ACTIVE: 
            return "active";
        case eSTATUS_ARRIVED:
            return "arrived";
        case eSTATUS_BLOCKED:
            return "blocked"; 
        default: 
            return "undefined status";
    }
}
}