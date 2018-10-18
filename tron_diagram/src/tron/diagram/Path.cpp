/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/diagram/Path.h"

namespace tron
{
Path::Path() 
{
    state1 = state2 = 0;
    overallCost = 0.0;
}

Path::Path(int state1, int state2)
{
    this->state1 = state1;
    this->state2 = state2;
    overallCost = 0.0;
}

Path::~Path()
{
    listTransitions.clear();    
}

void Path::setState1(int value)
{
    state1 = value;
    // clear path when new origin set
    clear();
}

void Path::setState2(int value)
{
    state2 = value;    
    // clear path when new destination set
    clear();
}

void Path::addTransition(Transition& oTransition)
{
    // transition ID is assigned automatically
    oTransition.getTransitionPk().setTransitionID(listTransitions.size());
    listTransitions.push_back(oTransition);
    overallCost += oTransition.getCost();
}

void Path::clear()
{
    overallCost = 0.0;        
    listTransitions.clear();        
}

std::string Path::toString()
{
    std::string text = "Path: state1 = " + std::to_string(state1) + ", state2 = " + std::to_string(state2) + " , overallCost = " + std::to_string(overallCost) + "\n";
    for (Transition& oTransition : listTransitions)
    {
        text += oTransition.toString() + "\n";
    }        
        
    return text;
}

}