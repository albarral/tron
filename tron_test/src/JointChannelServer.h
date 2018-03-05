#ifndef __TRON_TEST_JOINT_CHANNELSERVER_H
#define __TRON_TEST_JOINT_CHANNELSERVER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/talky2/channel/ChannelServer.h"

namespace tron
{
// Channel listener implementation for arm joints topic.
class JointChannelServer : public ChannelServer
{            
public:
    JointChannelServer();
    //~JointChannelServer();
    
    // process commands from received messages
    virtual void processCommands();
};

}
#endif
