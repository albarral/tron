#ifndef __TALKY2_CHANNEL_SUBSCRIBER_H
#define __TALKY2_CHANNEL_SUBSCRIBER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <vector>

#include "tron/talky2/channel/ChannelCommunicator.h"

namespace tron
{
// Channel communicator with subscriber functionality (info receptor on broadcast channels).
class ChannelSubscriber : public ChannelCommunicator
{    
protected:
    std::vector<std::string> listMessages;
        
public:
    ChannelSubscriber(int node, int topic); 
    ~ChannelSubscriber();

    // read messages from proper broadcast channel
    bool senseChannel();
    
    // process data from received messages
    virtual void processData() = 0;
    
protected:    
    virtual void setIdentity();
};

}
#endif
