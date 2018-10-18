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
    StatePk statePk;    // identifier of origin state
    int transID;            // transition identifier (inside state)
    
public:
    TransitionPk();
    TransitionPk(StatePk& statePk, int transID);
    
    StatePk& getStatePk() {return statePk;};
    void setStatePk(StatePk& statePk) {this->statePk = statePk;};

    int getTransitionID() {return transID;};
    void setTransitionID(int value) {transID = value;};
    
    std::string toString();
};
}

#endif
