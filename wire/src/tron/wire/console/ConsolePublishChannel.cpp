/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <iostream>

#include "tron/wire/console/ConsolePublishChannel.h"

namespace tron
{

ConsolePublishChannel::ConsolePublishChannel()
{
    name = "channel?-?";
}

ConsolePublishChannel::ConsolePublishChannel(int node, int channel) : PublishChannel(node, channel)
{
    name = "channel" + std::to_string(node) + "-" + std::to_string(channel);
}

bool ConsolePublishChannel::open()
{
    bopen = true;
    return true;    
}

bool ConsolePublishChannel::close()
{
    bopen = false;
    return true;        
}

bool ConsolePublishChannel::sendMsg(std::string text)
{
    std::cout << name + ":" + text << std::endl;        
}
}