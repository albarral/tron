/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/wire/channel/SubscribeChannel.h"

namespace tron
{

SubscribeChannel::SubscribeChannel()
{    
    type = Channel::eCHANNEL_BROADCAST;
    mode = "subscribe";
}

SubscribeChannel::SubscribeChannel(int node, int channel) : InputChannel(node, channel)
{    
    type = Channel::eCHANNEL_BROADCAST;
    setName();    
    mode = "subscribe";
}

// subscribers do not own the channel, so they can't clear its info
bool SubscribeChannel::clearInfo()
{
    return true;    
}    
}