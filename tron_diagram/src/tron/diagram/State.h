#ifndef __TRON_DIAGRAM_STATE_H
#define __TRON_DIAGRAM_STATE_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <map>
#include <string>

#include "tron/diagram/StatePk.h"
#include "tron/diagram/Transition.h"

namespace tron 
{
// Class used to represent a diagram state, including its transitions to other states.
class State
{
protected:
    StatePk statePk;
    std::string name;
    std::map<int, Transition> mapTransitions;      /*! transitions map (mapped by transitionID) */    
    
public:
    State();
    State(StatePk& statePk, std::string name);
    ~State();

    StatePk& getStatePk() {return statePk;};
    std::string getName() {return name;};
    std::map<int, Transition>& getTransitionsMap() {return mapTransitions;};

    void setStatePk(StatePk& statePk) {this->statePk = statePk;};
    void setName(std::string value) {name = value;};
        
    // get specified transition
    Transition* getTransition(int transID);     
    // add transition (to state2) to state
    void addTransition(int state2ID, int transID, std::string transName, float cost=0.0);
    // add full transition (with state pointers included) to diagram    
    void addFullTransition(Transition& oTransition);      

    void clear();
    std::string toString();   
};
}

#endif
