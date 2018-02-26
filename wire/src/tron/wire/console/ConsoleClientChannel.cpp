/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <iostream>

#include "tron/wire/console/ConsoleClientChannel.h"

namespace tron
{

ConsoleClientChannel::ConsoleClientChannel()
{
    name = "channel?-?";
}

ConsoleClientChannel::ConsoleClientChannel(int node, int channel) : ClientChannel(node, channel)
{
    name = "channel" + std::to_string(node) + "-" + std::to_string(channel);
}

bool ConsoleClientChannel::open()
{
    bopen = true;
    return true;    
}

bool ConsoleClientChannel::close()
{
    bopen = false;
    return true;        
}

bool ConsoleClientChannel::sendMsg(std::string text)
{
    std::cout << name + ":" + text << std::endl;        
}
}