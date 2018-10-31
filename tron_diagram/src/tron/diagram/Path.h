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
// A path is a sequence of connected transitions that go from an origin state to an end state.
class Path
{
protected:
    std::vector<Transition> listTransitions;    // transitions sequence
    int originState;     // origin state (automatically set)
    int endState;       // end state (automatically set)
    float overallCost;    // cost of traversing the whole path (automatically computed)
    
public:
    Path();
    ~Path();

    std::vector<Transition>& getTransitions() {return listTransitions;};
    int getOrigin() {return originState;};
    int getEnd() {return endState;};
    float getOverallCost() {return overallCost;};

    int getLength() {return listTransitions.size();};
    bool isEmpty() {return listTransitions.empty();};

    // add transition to path (only allowed if transition connected to path end)
    bool addTransition(Transition& oTransition);      
    // pop last transition from path (affects endState and cost)
    bool popLast();
    
    // check if given path is connected to this (it starts where this one ends)
    bool isConnected(Path& oPath2); 
    // add given path to this one (only if it's connected)
    bool add(Path& oPath2);
    
    // clear path (remove all transitions)
    void clear();

    // compare operator (return true if paths equal)
    friend bool operator== (Path& p1, Path& p2);
    // differ operator (return true if paths different)
    friend bool operator!= (Path& p1, Path& p2);        
    
    std::string toString();   
    // get short description of the path
    std::string shortDesc();

private:    
    void setOrigin(int value) {originState = value;};
    void setEnd(int value) {endState = value;};    

    
   
};
}

#endif
