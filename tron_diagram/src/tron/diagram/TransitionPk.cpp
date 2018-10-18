/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/diagram/TransitionPk.h"

namespace tron 
{
TransitionPk::TransitionPk() 
{
    transID = 0;
}

TransitionPk::TransitionPk(StatePk& statePk, int transID)
{
    setStatePk(statePk);
    this->transID = transID;
}

std::string TransitionPk::toString()
{
//    return "TransitionPk: [" + statePk.toString() + "], transID = " + std::to_string(transID);    
    return "TransitionPk: (diagram,state,transition) = (" + std::to_string(statePk.getDiagramID()) + "," + std::to_string(statePk.getStateID()) + "," + std::to_string(transID) + ")";
}

}