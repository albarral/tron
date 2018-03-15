#ifndef __TALKY2_ARM_CHANNELSUBSCRIBER_4JOINTS_H
#define __TALKY2_ARM_CHANNELSUBSCRIBER_4JOINTS_H

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
    JointsData jointPositions;
        
public:
    ChannelSubscriber4Joints();
    //~ChannelSubscriber4Joints();

    JointsData& getJointPositions() {return jointPositions;};
    
    // process data from received messages
    virtual void processData();
};

}
#endif
