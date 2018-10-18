#ifndef __TRON_DIAGRAM_TRANSITION_H
#define __TRON_DIAGRAM_TRANSITION_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "tron/diagram/TransitionPk.h"

namespace tron 
{
// Class used to represent a diagram transition between two states (with state1 origin & state2 destination).
// It includes a cost measure.
class Transition
{
protected:
    TransitionPk transitionPk;      // transition identifier 
    std::string name;
    int state2ID;                         // ID of destination state  
    float cost;                         // cost of the transition
  
public:
    Transition();
    Transition(TransitionPk& transitionPk, std::string name, int state2ID, float cost = 0.0);
        
    TransitionPk& getTransitionPk() {return transitionPk;};        
    int getState2ID() {return state2ID;};    
    float getCost() {return cost;};

    void setTransitionPk(TransitionPk& transitionPk) {this->transitionPk = transitionPk;};
    void setState2ID(int value) {state2ID = value;};
    void setCost(float value) {cost = value;};        

    void clear();
    std::string toString();
};
}

#endif
