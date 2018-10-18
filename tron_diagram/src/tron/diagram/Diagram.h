#ifndef __TRON_DIAGRAM_DIAGRAM_H
#define __TRON_DIAGRAM_DIAGRAM_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <map>
#include <string>

#include "tron/diagram/State.h"

namespace tron 
{
// Class used to represent state diagrams with transitions between states.
class Diagram
{
protected:
    int ID;
    std::string name;
    std::map<int, State> mapStates;      /*! states map (mapped by stateID) */    
    
public:
    Diagram();
    Diagram(int id, std::string name);    
    ~Diagram();
    
    int getID() {return ID;};
    std::string getName() {return name;};
    std::map<int, State>& getStatesMap() {return mapStates;};             

    void setID(int value) {ID = value;};    
    void setName(std::string value) {name = value;};
            
    // get specified state
    State* getState(int stateID); 
    // add state to diagram
    void addState(int stateID, std::string stateName);
    // add transition (from state1 to state2) to diagram
    bool addTransition(int state1ID, int state2ID, int transID, std::string transName, float cost=0.0);

    // add full state (with transitions included) to diagram
    void addFullState(State& oState);    
    
    // clear diagram
    void clear();
    
    std::string toString();

};
}

#endif
