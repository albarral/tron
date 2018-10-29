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

    // set walker to given state, clearing the path (return false if failed)
    bool enter(int stateID);    
    // traverse given transition (return false if failed)
    bool walk(int transitionID);
    // get the number of transitions seen from present state
    int getNumTransitionsAhead();
    
    // set a new walked path also updating the present state (return false if failed)
    bool setNewPath(Path& oPath2);
    
private:
    // set present state to given state id (return false if state is not in diagram)
    bool setState(int stateID);
};
}
#endif
