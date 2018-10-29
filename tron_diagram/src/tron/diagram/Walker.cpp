/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/diagram/Walker.h"

namespace tron
{    
Walker::Walker() 
{
    bgrounded = false;
    pDiagram = nullptr;
    pState = nullptr;
}

//Walker::~Walker()
//{
//}

void Walker::setDiagram(Diagram& oDiagram)
{
    pDiagram = &(oDiagram);
    // when setting diagram, walker is ungrounded
    bgrounded = false;
    pState = nullptr;
    oPath.clear();
}

bool Walker::enter(int stateID)
{
    bool bok = false;
    // if state set correctly, reset path
    if (pDiagram != nullptr && setState(stateID))
    {
        oPath.clear();            
        bok = true;
    }
    
    return bok;
}

bool Walker::walk(int transitionID)
{
    bool bok = false;
    // check if grounded
    if (bgrounded)
    {
        // get specified transition
        Transition* pTransition = pState->getTransition(transitionID);
        // if valid 
        if (pTransition != nullptr)
        {
            // set state pointed by transition
            if (setState(pTransition->getEndStateID()))
            {
                // add transition to path
                oPath.addTransition(*pTransition);           
                bok = true;
            }
        }
    }

    return bok;
}

bool Walker::setNewPath(Path& oPath2)
{
    bool bok = false;
    // we assume that new path is valid if its origin & end states are valid

    // if new path origin is valid
    if (enter(oPath2.getOrigin()))
    {
        // set state indicated by new path end
        if (setState(oPath2.getEnd()))
        {
            // copy path 
            oPath = oPath2;
            bok = true;
        }
    }
    
    return bok;
}

int Walker::getNumTransitionsAhead()
{
    // check if grounded
    if (bgrounded)
        return pState->getNumTransitions();        
    // not grounded
    else
        return 0;
}

bool Walker::setState(int stateID)
{
    // check new state existence
    State* pNewState = pDiagram->getState(stateID);                    
    // if exists, set it
    if (pNewState != nullptr)
    {        
        pState = pNewState;
        bgrounded = true;
        return true;
    }
    // otherwise, not
    else
        return false;
}

}