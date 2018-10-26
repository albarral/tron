/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <stdexcept>

#include "tron/diagram/Diagram.h"
#include "tron/diagram/StatePk.h"

namespace tron 
{
Diagram::Diagram() 
{
    ID = 0;
    name = "";
}

Diagram::Diagram(int id, std::string name)
{
    this->ID = id;
    this->name = name;    
}

Diagram::~Diagram()
{
    mapStates.clear();    
}

State* Diagram::getState(int stateID)
{
    try 
    {
        return &(mapStates.at(stateID));
    }
    // if state not found
    catch (const std::out_of_range& oor) 
    {                
        return nullptr;
    }                    
}

void Diagram::addState(int stateID, std::string stateName)
{    
    // create state object
    StatePk oStatePk(ID, stateID);
    State oState(oStatePk, stateName);
    // and add it to map
    addFullState(oState);    
}

bool Diagram::addTransition(int originState, int endState, std::string transName, float cost)
{    
    // check that states exist
    State* pOrigin = getState(originState);
    State* pEnd = getState(endState);
    // if yes, add transition to origin state
    if (pOrigin != nullptr && pEnd != nullptr)
        pOrigin->addTransition(endState, transName, cost);        
    // some state doesn't exist, skip
    else
        return false; 
}

void Diagram::addFullState(State& oState)
{
    mapStates.emplace(oState.getStatePk().getStateID(), oState);
}

void Diagram::clear()
{
    mapStates.clear();    
}

std::string Diagram::toString()
{
    std::string text = "Diagram: ID = " + std::to_string(ID) + ", name = " + name + "\n";
    for (auto& x : mapStates)
    {
        text += x.second.toString();
    }                
    return text;
}

}