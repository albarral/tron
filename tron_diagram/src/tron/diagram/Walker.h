#ifndef __TRON_DIAGRAM_WALKER_H
#define __TRON_DIAGRAM_WALKER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/diagram/Diagram.h"
#include "tron/diagram/Path.h"
#include "tron/diagram/State.h"

namespace tron
{
// Utility class used for walking (traversing) diagrams.
class Walker
{
protected:
    Diagram* pDiagram;  // diagram to walk
    State* pState;           // present state (informed when walker is positioned in a valid diagram state)
    Path oPath;               // walked path
        
public:
    Walker();
    //~Walker();

    // get present state
    State* getState() {return pState;};
    // get explored path
    Path& getPath() {return oPath;};
    // check if walker is in a valid position
    bool isGrounded() {return pState != nullptr;};

    // set exploration diagram
    void setDiagram(Diagram& oDiagram);
    // set position in diagram (returns false if state is not in diagram)
    bool setPosition(int state);    
    // traverse the given transition (returns false if transition not exists in present state)
    bool walk(int transition);
};
}
#endif
