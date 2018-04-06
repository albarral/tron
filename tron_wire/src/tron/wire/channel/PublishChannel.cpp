/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/wire/channel/PublishChannel.h"

namespace tron
{

PublishChannel::PublishChannel()
{    
    type = Channel::eCHANNEL_BROADCAST;
    mode = "publish";
}

PublishChannel::PublishChannel(int node, int channel) : OutputChannel(node, channel)
{    
    type = Channel::eCHANNEL_BROADCAST;
    setName();
    mode = "publish";
}
}