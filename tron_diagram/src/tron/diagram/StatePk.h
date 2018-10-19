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
    int diagramID;  // diagram identifier
    int stateID;      // state identifier  (inside diagram)
    
public:
    StatePk();
    StatePk(int diagram, int state);
    
    int getDiagramID() {return diagramID;};
    void setDiagramID(int value) {diagramID = value;};

    int getStateID() {return stateID;};
    void setStateID(int value) {stateID = value;};
    
    friend bool operator== (const StatePk& pk1, const StatePk& pk2);
    friend bool operator!= (const StatePk& pk1, const StatePk& pk2);    
    
    std::string toString();
};
}

#endif
