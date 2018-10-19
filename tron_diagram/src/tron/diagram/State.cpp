/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/diagram/State.h"

namespace tron 
{
State::State() 
{
    name = "";
}

State::State(StatePk& statePk, std::string name)
{
    setStatePk(statePk);
    this->name = name;    
}

State::~State()
{
    listTransitions.clear();    
}

Transition* State::getTransition(int transID)
{
    // safety check
    if (transID < listTransitions.size())
        return &(listTransitions.at(transID));
    else
        return nullptr;
}

void State::addTransition(int endState, std::string transName, float cost)
{    
    // create transition object
    // transition ID is automatically set
    int transID = listTransitions.size();     
    TransitionPk oTransitionPk(statePk, transID);
    Transition oTransition(oTransitionPk, transName, endState, cost);
    // and add it to list
    listTransitions.push_back(oTransition);    
}

void State::addFullTransition(Transition& oTransition)
{
    // transition ID is automatically set
    int transID = listTransitions.size();     
    oTransition.getTransitionPk().setTransitionID(transID);
    // and add it to list
    listTransitions.push_back(oTransition);    
}

void State::clear()
{
    name = "";
    listTransitions.clear();        
}

std::string State::toString()
{
    std::string text = "State: [" + statePk.toString() + "], name = " + name + "\n";
    for (Transition& oTransition : listTransitions)
    {
        text += oTransition.toString() + "\n";
    }        
        
    return text;
}

}