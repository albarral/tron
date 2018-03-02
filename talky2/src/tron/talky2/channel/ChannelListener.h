#ifndef __TALKY2_CHANNELLISTENER_H
#define __TALKY2_CHANNELLISTENER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <vector>

#include "tron/talky2/channel/ChannelCommunicator.h"

namespace tron
{
// Base channel communicator with listener functionality (subscriber on broadcast channels).
class ChannelListener : public ChannelCommunicator
{    
private:
    std::vector<std::string> listMessages;
        
public:
    ChannelListener(int node, int topic); 
    ~ChannelListener();

    // read messages from proper broadcast channel
    bool senseChannel();
    
    // process data from received messages
    virtual void processSensedData() = 0;
    
protected:    
    virtual void setIdentity();
};

}
#endif
