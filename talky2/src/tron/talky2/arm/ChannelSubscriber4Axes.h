#ifndef __TALKY2_ARM_CHANNELSUBSCRIBER_4AXES_H
#define __TALKY2_ARM_CHANNELSUBSCRIBER_4AXES_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/talky2/channel/ChannelSubscriber.h"
#include "tron/robot/sensors/ArmSensors.h"

namespace tron
{
// Specific channel subscriber for arm axes topic.
class ChannelSubscriber4Axes : public ChannelSubscriber
{    
private:
    AxesData axesPositions;
    AxesData axesSpeeds;
        
public:
    ChannelSubscriber4Axes();
    //~ChannelSubscriber4Axes();

    AxesData& getAxesPositions() {return axesPositions;};
    AxesData& getAxesSpeeds() {return axesSpeeds;};
    
    // process data from received messages
    virtual void processData();
};

}
#endif
