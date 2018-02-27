/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/wire/channel/ClientChannel.h"

namespace tron
{

ClientChannel::ClientChannel()
{    
    type = Channel::eCHANNEL_UNICAST;
}

ClientChannel::ClientChannel(int node, int channel) : OutputChannel(node, channel)
{
    type = Channel::eCHANNEL_UNICAST;    
    setName();
}
}