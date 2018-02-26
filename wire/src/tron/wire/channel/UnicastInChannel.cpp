/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/wire/channel/UnicastInChannel.h"

namespace tron
{

UnicastInChannel::UnicastInChannel()
{    
    type = Channel::eCHANNEL_P2P;
}

UnicastInChannel::UnicastInChannel(int node, int channel) : InputChannel(node, channel)
{
    type = Channel::eCHANNEL_P2P;
}

}