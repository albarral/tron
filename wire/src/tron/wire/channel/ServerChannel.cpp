/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/wire/channel/ServerChannel.h"

namespace tron
{

ServerChannel::ServerChannel()
{    
    type = Channel::eCHANNEL_UNICAST;
    mode = "server";
}

ServerChannel::ServerChannel(int node, int channel) : InputChannel(node, channel)
{
    type = Channel::eCHANNEL_UNICAST;
    setName();    
    mode = "server";
}

}