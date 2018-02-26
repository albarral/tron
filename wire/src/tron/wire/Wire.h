#ifndef __TRON_WIRE_WIRE_H
#define __TRON_WIRE_WIRE_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <vector>
#include <log4cxx/logger.h>

#include "tron/wire/channel/InputChannel.h"
#include "tron/wire/channel/OutputChannel.h"

namespace tron
{
// Base class used manage multichannel communications.
// Multichannel coms: each coms channel is associated to a specific node & category.
class Wire
{            
protected:
    static log4cxx::LoggerPtr logger;    
    std::vector<OutputChannel*> listUnicastOutChannels;
    std::vector<InputChannel*> listUnicastInChannels;
    std::vector<OutputChannel*> listPublishChannels;
    std::vector<InputChannel*> listSubscribeChannels;
        
public:
    Wire();
    ~Wire();

    // clears all channels lists
    void clearChannels();
    
    // unicast methods
    bool sendMsg(int node, int channel, std::string text);
//    bool sendMessages(int node, int channel, std::vector<std::string>& listMessages);
    bool receiveMessages(int node, int channel, std::vector<std::string>& listMessages);

    // broadcast methods
    bool publishMsg(int node, int channel, std::string text);
//    bool publishMessages(int node, int channel, std::vector<std::string>& listMessages);
    bool hearMessages(int node, int channel, std::vector<std::string>& listMessages);
    
private:    
    // search output channel in given list for given node/channel
    OutputChannel* searchOutputChannel(int node, int channel, std::vector<OutputChannel*>& listOutputChannels);
    // get existing input channel in given list for given node/channel
    InputChannel* searchInputChannel(int node, int channel, std::vector<InputChannel*>& listInputChannels);
    
    // clears given list of input channels (deleting objects in heap)
    void clearInputChannelsList(std::vector<InputChannel*>& listInputChannels);
    // clears given list of output channels (deleting objects in heap)
    void clearOutputChannelsList(std::vector<OutputChannel*>& listOutputChannels);
    
protected:    
    // create new unicast output channel for given node/channel 
    virtual OutputChannel* createUnicastOutputChannel(int node, int channel) = 0;
    // create new unicast input channel for given node/channel
    virtual InputChannel* createUnicastInputChannel(int node, int channel) = 0;
//    // create new publish channel for given node/channel
    virtual OutputChannel* createPublishChannel(int node, int channel) = 0;
//    // create new subscribe channel for given node/channel
    virtual InputChannel* createSubscribeChannel(int node, int channel) = 0;
};
}
#endif
