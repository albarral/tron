#ifndef __TRON_DIAGRAM_TRANSITIONPK_H
#define __TRON_DIAGRAM_TRANSITIONPK_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "tron/diagram/StatePk.h"

namespace tron 
{
class TransitionPk
{
private:
    int diagramID;  // diagram identifier
    int stateID;      // state identifier  (inside diagram)
    int transID;      // transition identifier (inside state)
    
public:
    TransitionPk();
    TransitionPk(int diagram, int state, int trans);
    TransitionPk(StatePk& statePk, int trans);
    
    int getDiagramID() {return diagramID;};
    void setDiagramID(int value) {diagramID = value;};

    int getStateID() {return stateID;};
    void setStateID(int value) {stateID = value;};
    
    int getTransitionID() {return transID;};
    void setTransitionID(int value) {transID = value;};
    
    // build a state pk from this transition pk
    StatePk getStatePk();
    
    friend bool operator== (const TransitionPk& pk1, const TransitionPk& pk2);
    friend bool operator!= (const TransitionPk& pk1, const TransitionPk& pk2);    
    
    std::string toString();
};
}

#endif
