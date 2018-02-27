/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/wire/channel/Channel.h"

using namespace log4cxx;

namespace tron
{
LoggerPtr Channel::logger(Logger::getLogger("tron.wire"));

Channel::Channel()
{    
    node = -1;
    channel = -1;
    bopen = false;
}

Channel::Channel(int node, int channel)
{
    this->node = node;
    this->channel = channel;
    bopen = false;        
}

// build channel name
void Channel::setName()
{
    // inform node
    name = "c" + std::to_string(node);
    switch (type)
    {
        case eCHANNEL_UNICAST: 
            // inform unicast mode
            name += "uni";
            break;
        case eCHANNEL_BROADCAST:
            // inform broadcast mode
            name += "broad";
            break;
    }
    // inform channel
    name += std::to_string(channel);
}
}