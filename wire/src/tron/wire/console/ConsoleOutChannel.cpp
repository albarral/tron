/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <iostream>

#include "tron/wire/console/ConsoleOutChannel.h"

namespace tron
{

ConsoleOutChannel::ConsoleOutChannel()
{
    name = "channel?-?";
}

ConsoleOutChannel::ConsoleOutChannel(int node, int channel) : OutChannel(node, channel)
{
    name = "channel" + std::to_string(node) + "-" + std::to_string(channel);
}

bool ConsoleOutChannel::open()
{
    bopen = true;
    return true;    
}

bool ConsoleOutChannel::close()
{
    bopen = false;
    return true;        
}

bool ConsoleOutChannel::sendMsg(std::string text)
{
    std::cout << name + ":" + text << std::endl;        
}
}