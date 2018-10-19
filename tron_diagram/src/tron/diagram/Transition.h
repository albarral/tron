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
// Class used to represent a diagram transition between two states (origin and end).
// It features a cost measure of traversing the transition.
class Transition
{
protected:
    TransitionPk transitionPk;      // transition identifier 
    std::string name;               // transition name
    int endStateID;                   // end state ID
    float cost;                         // cost of the transition
  
public:
    Transition();
    Transition(TransitionPk& transitionPk, std::string name, int endState, float cost = 0.0);
        
    TransitionPk& getTransitionPk() {return transitionPk;};        
    int getEndStateID() {return endStateID;};    
    float getCost() {return cost;};

    void setTransitionPk(TransitionPk& transitionPk) {this->transitionPk = transitionPk;};
    void setState2ID(int value) {endStateID = value;};
    void setCost(float value) {cost = value;};        

    void clear();
    std::string toString();
};
}

#endif
