#ifndef __TRON_WIRE_WIRE_H
#define __TRON_WIRE_WIRE_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <vector>
#include <log4cxx/logger.h>

#include "tron/wire/InChannel.h"
#include "tron/wire/OutChannel.h"
#include "tron/wire/PublishChannel.h"
#include "tron/wire/SubscribeChannel.h"

namespace tron
{
// Base class used manage multichannel communications.
// Multichannel coms: each coms channel is associated to a specific node & category.
class Wire
{            
protected:
    static log4cxx::LoggerPtr logger;    
    std::vector<OutChannel> listOutputChannels;
    std::vector<InChannel> listInputChannels;
    std::vector<PublishChannel> listPublishChannels;
    std::vector<SubscribeChannel> listSubscribeChannels;
        
public:
    Wire();
    ~Wire();

    // clears all channels lists
    void clearChannels();
    
    // p2p methods
    bool sendMsg(int node, int channel, std::string text);
    bool sendMessages(int node, int channel, std::vector<std::string>& listMessages);
    bool fetchMessages(int node, int channel, std::vector<std::string>& listMessages);

    // broadcast methods
    bool publishMsg(int node, int channel, std::string text);
    bool publishMessages(int node, int channel, std::vector<std::string>& listMessages);
    bool readMessages(int node, int channel, std::vector<std::string>& listMessages);
    
protected:    
    // get existing output channel for given node/channel
    OutChannel& getOutChannel(int node, int channel);
    // get existing input channel for given node/channel
    InChannel& getInChannel(int node, int channel);
    // get existing publish channel for given node/channel
    PublishChannel& getPublishChannel(int node, int channel);
    // get existing subscribe channel for given node/channel
    SubscribeChannel& getSubscribeChannel(int node, int channel);
    
    // create new output channel for given node/channel 
    virtual OutChannel* createOutChannel(int node, int channel) = 0;
    // create new input channel for given node/channel
    virtual InChannel* createInChannel(int node, int channel) = 0;
    // create new publish channel for given node/channel
    virtual PublishChannel* createPublishChannel(int node, int channel) = 0;
    // create new subscribe channel for given node/channel
    virtual SubscribeChannel* createSubscribeChannel(int node, int channel) = 0;
};
}
#endif
