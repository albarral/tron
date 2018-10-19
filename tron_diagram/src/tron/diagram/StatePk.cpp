/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/diagram/StatePk.h"

namespace tron 
{
StatePk::StatePk() 
{
    diagramID = 0;
    stateID = 0;
}

StatePk::StatePk(int diagram, int state)
{
    diagramID = diagram;
    stateID = state;
}

bool operator== (const StatePk &pk1, const StatePk &pk2)
{
    return (pk1.diagramID == pk2.diagramID &&
            pk1.stateID == pk2.stateID);
}
 
bool operator!= (const StatePk &pk1, const StatePk &pk2)
{
    return !(pk1 == pk2);
}

std::string StatePk::toString()
{
    return "StatePk: (diagram,state) = (" + std::to_string(diagramID) + "," + std::to_string(stateID) + ")";    
}

}