/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/diagram/TransitionPk.h"

namespace tron 
{
TransitionPk::TransitionPk() 
{
    diagramID = 0;
    stateID = 0;
    transID = 0;
}

TransitionPk::TransitionPk(int diagram, int state, int trans)
{
    diagramID = diagram;
    stateID = state;
    transID = trans;    
}

TransitionPk::TransitionPk(StatePk& statePk, int trans)
{
    diagramID = statePk.getDiagramID();
    stateID = statePk.getStateID();
    transID = trans;
}

StatePk TransitionPk::getStatePk()
{
    StatePk oStatePk(diagramID, stateID);
    return oStatePk;    
}

bool operator== (const TransitionPk &pk1, const TransitionPk &pk2)
{
    return (pk1.diagramID == pk2.diagramID &&
            pk1.stateID == pk2.stateID &&
            pk1.transID == pk2.transID);
}
 
bool operator!= (const TransitionPk &pk1, const TransitionPk &pk2)
{
    return !(pk1 == pk2);
}

std::string TransitionPk::toString()
{
    return "TransitionPk: (diagram,state,transition) = (" + std::to_string(diagramID) + "," + std::to_string(stateID) + "," + std::to_string(transID) + ")";
}

}