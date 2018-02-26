/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <iostream>

#include "tron/wire/console/ConsoleUnicastOutChannel.h"

namespace tron
{

ConsoleUnicastOutChannel::ConsoleUnicastOutChannel()
{
    name = "channel?-?";
}

ConsoleUnicastOutChannel::ConsoleUnicastOutChannel(int node, int channel) : UnicastOutChannel(node, channel)
{
    name = "channel" + std::to_string(node) + "-" + std::to_string(channel);
}

bool ConsoleUnicastOutChannel::open()
{
    bopen = true;
    return true;    
}

bool ConsoleUnicastOutChannel::close()
{
    bopen = false;
    return true;        
}

bool ConsoleUnicastOutChannel::sendMsg(std::string text)
{
    std::cout << name + ":" + text << std::endl;        
}
}