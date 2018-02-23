/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/wire/Channel.h"

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
}