/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/wire/InChannel.h"

namespace tron
{

InChannel::InChannel()
{    
    type = Channel::eCHANNEL_P2P;
}

InChannel::InChannel(int node, int channel) : Channel(node, channel)
{
    type = Channel::eCHANNEL_P2P;
}

}