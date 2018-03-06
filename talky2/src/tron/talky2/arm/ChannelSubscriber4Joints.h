#ifndef __TALKY2_ARM_JOINT_CHANNEL_SUBSCRIBER_H
#define __TALKY2_ARM_JOINT_CHANNEL_SUBSCRIBER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/talky2/channel/ChannelSubscriber.h"
#include "tron/robot/sensors/ArmSensors.h"

namespace tron
{
// Specific channel subscriber for arm joints topic.
class ChannelSubscriber4Joints : public ChannelSubscriber
{    
private:
    JointsData jointsData;
        
public:
    ChannelSubscriber4Joints();
    //~ChannelSubscriber4Joints();

    JointsData& getJointsData() {return jointsData;};
    
    // process data from received messages
    virtual void processData();
};

}
#endif
