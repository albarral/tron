#ifndef __TRON_WIRE_INPUTCHANNEL_H
#define __TRON_WIRE_INPUTCHANNEL_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <vector>

#include "tron/wire/channel/Channel.h"

namespace tron
{
// Base class used to receive messages from an origin node.
class InputChannel : public Channel
{           
public:
    InputChannel() {};    
    InputChannel(int node, int channel) : Channel(node, channel) {};

    // receive messages from origin, returns false if nothing received
    virtual bool receiveMessages(std::vector<std::string>& listMessages) = 0;
};
}
#endif
