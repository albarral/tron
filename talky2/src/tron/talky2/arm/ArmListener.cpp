/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/talky2/arm/ArmListener.h"

using namespace log4cxx;

namespace tron
{
LoggerPtr ArmListener::logger(Logger::getLogger("tron.talky2"));

ArmListener::ArmListener()
{    
}

//ArmListener::~ArmListener()
//{    
//}

bool ArmListener::getJointPositions(JointsData& jointsData)
{    
    // hear messages in joints channel
    if (oJointChannelListener.senseChannel())
    {
        // process received messages
        oJointChannelListener.processData();
        jointsData = oJointChannelListener.getJointsData();
        return true;
    }
    // if no messages could be read
    else
        return false;
}

}