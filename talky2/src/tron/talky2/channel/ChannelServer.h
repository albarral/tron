#ifndef __TALKY2_CHANNELSERVER_H
#define __TALKY2_CHANNELSERVER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <vector>

#include "tron/talky2/channel/ChannelCommunicator.h"

namespace tron
{
// Base channel communicator with server functionality (info receptor on unicast channels).
class ChannelServer : public ChannelCommunicator
{    
protected:
    std::vector<std::string> listMessages;
        
public:
    ChannelServer(int node, int topic); 
    ~ChannelServer();

    // read messages from proper unicast channel
    bool senseChannel();
    
    // process commands from received messages
    virtual void processCommands() = 0;
    
    // clears info in our channel
    bool clearChannel();
    
protected:    
    virtual void setIdentity();
};

}
#endif
