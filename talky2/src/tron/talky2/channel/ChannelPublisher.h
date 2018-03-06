#ifndef __TALKY2_CHANNELPUBLISHER_H
#define __TALKY2_CHANNELPUBLISHER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/talky2/channel/ChannelCommunicator.h"

namespace tron
{
// Base channel communicator with client functionality (sender on unicast channels).
class ChannelPublisher : public ChannelCommunicator
{    
protected:
    std::string message;
        
public:
    ChannelPublisher(int node, int topic); 
    //~ChannelPublisher();

    // build message for given command & send it through proper channel
    bool publishMessage(int code, float value);

    // clears info in our channel
    bool clearChannel();
    
protected:    
    virtual void setIdentity();
};

}
#endif
