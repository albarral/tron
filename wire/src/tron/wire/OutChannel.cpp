/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/wire/OutChannel.h"

namespace tron
{

OutChannel::OutChannel()
{    
    type = Channel::eCHANNEL_P2P;
}

OutChannel::OutChannel(int node, int channel) : Channel(node, channel)
{
    type = Channel::eCHANNEL_P2P;    
}
}