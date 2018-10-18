#ifndef __TRON_DIAGRAM_PATH_H
#define __TRON_DIAGRAM_PATH_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <vector>

#include "tron/diagram/Transition.h"

namespace tron 
{
// Class used to represent a path in a states diagram. 
// A path is the sequence of transitions needed to go from an origin state to a destination state.
class Path
{
protected:
    int state1;     // origin state
    int state2;     // destination state
    std::vector<Transition> listTransitions;    // transitions sequence
    float overallCost;       // total cost of traversing all the path transitions
    
public:
    Path();
    Path(int state1, int state2);
    ~Path();

    int getState1() {return state1;};
    int getState2() {return state1;};
    std::vector<Transition>& getListTransitions() {return listTransitions;};
    float getOverallCost() {return overallCost;};

    void setState1(int value);
    void setState2(int value);    
    void setOverallCost(float value) {overallCost = value;};
    void addTransition(Transition& oTransition);      
    
    void clear();

    std::string toString();   
};
}

#endif
