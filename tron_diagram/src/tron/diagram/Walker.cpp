/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/diagram/Walker.h"
#include "tron/diagram/Transition.h"

namespace tron
{    
Walker::Walker() 
{
    pDiagram = nullptr;
    pState = nullptr;
}

//Walker::~Walker()
//{
//}

void Walker::setDiagram(Diagram& oDiagram)
{
    pDiagram = &(oDiagram);
    // reset state & path
    pState = nullptr;
    oPath.clear();
}

bool Walker::setPosition(int state)
{
    if (pDiagram != nullptr)
    {
        pState = pDiagram->getState(state);
        // if state exists, ok
        if (pState != nullptr)
        {
            // reset path
            oPath.clear();
            return true;        
        }
        else
            return false;
    }
    else
        return false;
}

bool Walker::walk(int transition)
{
    // check if grounded
    if (pState != nullptr)
    {
        // get specified transition 
        Transition* pTransition = pState->getTransition(transition);
        // if valid, traverse it 
        if (pTransition != nullptr)
        {
            // walk to transition pointed state
            pState = pDiagram->getState(pTransition->getEndStateID());                    
            // if valid state
            if (pState != nullptr)
            {
                // add it to path
                oPath.addTransition(*pTransition);           
                return true;
            }
            // otherwise, incoherent transition (skip walk)
            else
                return false;
        // otherwise, not existent transition (skip walk)    
        }
        else
            return false;              
    }
    // not grounded (skip walk)
    else
        return false;   
}
}