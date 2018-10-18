/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <stdexcept>

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
    mapTransitions.clear();    
}

Transition* State::getTransition(int transID)
{
    try 
    {
        return &(mapTransitions.at(transID));
    }
    // if transition not found
    catch (const std::out_of_range& oor) 
    {                
        return nullptr;
    }                    
}

void State::addTransition(int state2ID, int transID, std::string transName, float cost)
{
    // create transition object
    TransitionPk oTransitionPk(statePk, transID);
    Transition oTransition(oTransitionPk, transName, state2ID, cost);
    // and add it to map
    addFullTransition(oTransition);    
}

void State::addFullTransition(Transition& oTransition)
{
    mapTransitions.emplace(oTransition.getTransitionPk().getTransitionID(), oTransition);
}

void State::clear()
{
    name = "";
    mapTransitions.clear();        
}

std::string State::toString()
{
    std::string text = "State: [" + statePk.toString() + "], name = " + name + "\n";
    for (auto& x : mapTransitions)
    {
        text += x.second.toString() + "\n";
    }        
        
    return text;
}

}