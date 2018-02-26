/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/wire/channel/UnicastOutChannel.h"

namespace tron
{

UnicastOutChannel::UnicastOutChannel()
{    
    type = Channel::eCHANNEL_P2P;
}

UnicastOutChannel::UnicastOutChannel(int node, int channel) : OutputChannel(node, channel)
{
    type = Channel::eCHANNEL_P2P;    
}
}