#ifndef __TALKY2_ARM_JOINT_CHANNELLISTENER_H
#define __TALKY2_ARM_JOINT_CHANNELLISTENER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/talky2/channel/ChannelListener.h"
#include "tron/robot/sensors/ArmSensors.h"

namespace tron
{
// Channel listener implementation for arm joints topic.
class JointChannelListener : public ChannelListener
{    
private:
    JointsData jointsData;
        
public:
    JointChannelListener();
    //~JointChannelListener();

    JointsData& getJointsData() {return jointsData;};
    
    // process data from received messages
    virtual void processData();
};

}
#endif
