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
    state2ID = 0;
    cost = 0.0;
}

Transition::Transition(TransitionPk& transitionPk, std::string name, int state2ID, float cost)
{
    setTransitionPk(transitionPk);
    this->name = name;
    this->state2ID = state2ID;
    this->cost = cost;
}

void Transition::clear()
{
    name = "";
    state2ID = 0;
    cost = 0.0;
}

std::string Transition::toString()
{
    return ("Transition: [" + transitionPk.toString() + "], name = " + name + ", state2 = " + std::to_string(state2ID) + ", cost = " + std::to_string(cost));
}
}