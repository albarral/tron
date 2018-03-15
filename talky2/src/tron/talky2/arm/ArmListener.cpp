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

bool ArmListener::senseChannels()
{    
    // hear messages from joints channel
    bool bok1 = senseChannel(oChannelSubscriber4Joints);
    // hear messages from axes channel
    bool bok2 = senseChannel(oChannelSubscriber4Axes);

    return (bok1 && bok2);
}

bool ArmListener::senseChannel(ChannelSubscriber& oChannelSubscriber)
{
    // hear messages in given subscribe channel
    if (oChannelSubscriber.senseChannel())
    {
        // process received messages
        oChannelSubscriber.processData();
        return true;
    }
    // if no messages could be read
    else
        return false;    
}

JointsData& ArmListener::getJointPositions()
{            
    return oChannelSubscriber4Joints.getJointPositions();
}

AxesData& ArmListener::getAxesPositions()
{
    return oChannelSubscriber4Axes.getAxesPositions();    
}

AxesData& ArmListener::getAxesSpeeds()
{
    return oChannelSubscriber4Axes.getAxesSpeeds();    
}
}