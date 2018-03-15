#ifndef __TALKY2_CHANNELPUBLISHER_H
#define __TALKY2_CHANNELPUBLISHER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <vector>

#include "tron/talky2/channel/ChannelCommunicator.h"

namespace tron
{
// Base channel communicator with publisher functionality (info sender on broadcast channels).
class ChannelPublisher : public ChannelCommunicator
{    
protected:
    std::string message;                    // for single message publishing
    std::vector<std::string> listMessages;  // output queue for multi message publishing
        
public:
    ChannelPublisher(int node, int topic); 
    ~ChannelPublisher();

    // build message for given command & send it through proper channel
    bool publishMessage(int code, float value);

    // build message for given command & add it to output queue
    bool addMessage(int code, float value);
    // publish all messages of the output queue 
    bool publishAll();
    
    // clears info in our channel
    bool clearChannel();
    
protected:    
    virtual void setIdentity();
};

}
#endif
