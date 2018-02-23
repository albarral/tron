/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/wire/SubscribeChannel.h"

namespace tron
{

SubscribeChannel::SubscribeChannel()
{    
    type = Channel::eCHANNEL_BROADCAST;
}

SubscribeChannel::SubscribeChannel(int node, int channel) : Channel(node, channel)
{    
    type = Channel::eCHANNEL_BROADCAST;
}
}