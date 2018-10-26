#ifndef __TRON_DIAGRAM_WALKER_H
#define __TRON_DIAGRAM_WALKER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/diagram/Diagram.h"
#include "tron/diagram/Path.h"
#include "tron/diagram/State.h"
#include "tron/diagram/Transition.h"

namespace tron
{
// Utility class used for walking diagrams (entering states and traversing transitions).
class Walker
{
protected:
    bool bgrounded;         // indicates that walker is in a valid diagram state
    Diagram* pDiagram;  // diagram to walk
    State* pState;           // present state
    Path oPath;               // walked path
        
public:
    Walker();
    //~Walker();

    // check if walker is grounded 
    bool isGrounded() {bgrounded;};
    // get present state
    State* getState() {return pState;};
    // get explored path
    Path& getPath() {return oPath;};

    // set exploration diagram
    void setDiagram(Diagram& oDiagram);
    // position walker in given state (returns false if invalid state)
    bool enter(int stateID);    
    // traverse given transition (returns false if invalid transition)
    bool walk(int transitionID);
    // walk back the last traversed transition reducing the path accordingly (returns false if could not do it)
    bool walkBack();
    // get the number of transitions the walker sees at present state
    int getNumTransitions2Walk();
    // get the ID of present state
    int getPresentPosition();
};
}
#endif
