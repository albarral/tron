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
    if (oChannelSubscriber4Joints.senseChannel())
    {
        // process received messages
        oChannelSubscriber4Joints.processData();
        jointsData = oChannelSubscriber4Joints.getJointsData();
        return true;
    }
    // if no messages could be read
    else
        return false;
}

}