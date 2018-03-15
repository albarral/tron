#ifndef __TRON_WIRE_OUTPUTCHANNEL_H
#define __TRON_WIRE_OUTPUTCHANNEL_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <vector>

#include "tron/wire/channel/Channel.h"

namespace tron
{
// Base class used to transmit messages to a destination node.
class OutputChannel : public Channel
{           
public:
    OutputChannel() {};    
    OutputChannel(int node, int channel) : Channel(node, channel) {};

    // send message to destination, returns false if nothing sent
    virtual bool sendMsg(std::string message) = 0;
    // send messages to destination, returns false if nothing sent
    virtual bool sendMessages(std::vector<std::string>& listMessages) = 0;
};
}
#endif
