#ifndef __TRON_DIAGRAM_STATEPK_H
#define __TRON_DIAGRAM_STATEPK_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

namespace tron 
{
class StatePk
{
private:
    int diagramID;
    int stateID;
    
public:
    StatePk();
    StatePk(int diagram, int state);
    
    int getDiagramID() {return diagramID;};
    void setDiagramID(int value) {diagramID = value;};

    int getStateID() {return stateID;};
    void setStateID(int value) {stateID = value;};
    
    std::string toString();
};
}

#endif
