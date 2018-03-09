#ifndef __TALKY2_ARMLISTENER_H
#define __TALKY2_ARMLISTENER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <vector>
#include <log4cxx/logger.h>

#include "tron/talky2/arm/ChannelSubscriber4Joints.h"
#include "tron/talky2/arm/ChannelSubscriber4Axes.h"
#include "tron/talky2/channel/ChannelSubscriber.h"
#include "tron/robot/listeners/TronArmListener.h"
#include "tron/robot/sensors/ArmSensors.h"

namespace tron
{
// Arm client class (implementing TronArmListener interface) to sense a robot arm.
class ArmListener : public TronArmListener
{    
private:
    static log4cxx::LoggerPtr logger;
    ChannelSubscriber4Joints oChannelSubscriber4Joints;
    ChannelSubscriber4Axes oChannelSubscriber4Axes;    
        
public:
    ArmListener();
    //~ArmListener();

    // senses subscribed channels
    bool senseChannels();
    
    // joint topic ...
    // sense joints positions 
    virtual JointsData& getJointPositions();
    // sense joint states
//    virtual JointsData& getJointStates();
//
    // axis topic ...
    // sense axes positions 
    virtual AxesData& getAxesPositions();
    // sense axes speeds 
    virtual AxesData& getAxesSpeeds();
    
private:
    // hear and process info in given channel 
    bool senseChannel(ChannelSubscriber& oChannelSubscriber);
};

}
#endif
