/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/control/Behaviour.h"

namespace tron
{
// Constructor
Behaviour::Behaviour()
{    
    prevState = state = -1;
    binhibited = false;
}

Behaviour::Behaviour(std::string name) : Behaviour()
{    
    this->name = name;
}

Behaviour::~Behaviour()
{
    listStateNames.clear();
}

std::string Behaviour::getStateName()
{
    // get name of given state
    if (state < listStateNames.size())
        return listStateNames.at(state);
    // return empty if invalid state
    else
        return "";
}

void Behaviour::addStateName(std::string name)
{        
    listStateNames.push_back(name);
}

void Behaviour::postLoop()
{
    // store previous state
    prevState = state;
}

}


