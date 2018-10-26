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
    // safety check
    if (pDiagram != nullptr)
    {
        // if state valid
        if (pDiagram->getState(stateID) != nullptr)
        {
            // ground walker at this state
            pState = pDiagram->getState(stateID);
            bgrounded = true;
            // and reset path
            oPath.clear();
            
            return true;        
        }
        // invalid state
        else
            return false;
    }
    else
        return false;
}

bool Walker::walk(int transitionID)
{
    // check if grounded
    if (bgrounded)
    {
        // get transition
        Transition* pTransition = pState->getTransition(transitionID);
        // if exists
        if (pTransition != nullptr)
        {
            // check state pointed by transition
            State* pNextState = pDiagram->getState(pTransition->getEndStateID());                    
            // if state exists
            if (pNextState != nullptr)
            {
                // walk to it and add transition to path
                pState = pNextState;
                oPath.addTransition(*pTransition);           
                return true;
            }
            // state not exists, invalid transition (points to nowhere)
            else
                return false;
        }
        // transition not exists
        else
            return false;              
    }
    // walker not grounded
    else
        return false;   
}

bool Walker::walkBack()
{
    // check if grounded
    if (bgrounded)
    {
        // reduce path popping last transition
        if (oPath.popTransition())
        {
            // get back to previous state (the pointed by new path end)
            pState = pDiagram->getState(oPath.getEnd());                    
            // if state exists (should exist, as we walked it in the past)
            if (pState != nullptr)
                return true;
            // otherwise, invalid walk back (jumped to nowhere)
            else
            {
                bgrounded = false;
                return false;            
            }
        }
        // couldn't reduce path
        else
            return false;            
    }
    // walker not grounded
    else
        return false;   
}

int Walker::getNumTransitions2Walk()
{
    // check if grounded
    if (bgrounded)
        return pState->getNumTransitions();        
    // not grounded
    else
        return 0;
}

int Walker::getPresentPosition()
{
    // check if grounded
    if (bgrounded)
        return oPath.getEnd();        
    // not grounded
    else
        return -1;
}
}