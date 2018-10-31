/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/diagram/Transition.h"

namespace tron 
{
Transition::Transition() 
{
    name = "";
    endStateID = 0;
    cost = 0.0;
}

Transition::Transition(TransitionPk& transitionPk, std::string name, int endState, float cost)
{
    setTransitionPk(transitionPk);
    this->name = name;
    endStateID = endState;
    this->cost = cost;
}

void Transition::clear()
{
    name = "";
    endStateID = 0;
    cost = 0.0;
}

std::string Transition::toString()
{
    return ("Transition: [" + transitionPk.toString() + "], end state = " + std::to_string(endStateID) + ", name = " + name + ", cost = " + std::to_string(cost));
}
}