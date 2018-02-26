/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <iostream>

#include "tron/wire/console/ConsoleUnicastInChannel.h"

namespace tron
{

ConsoleUnicastInChannel::ConsoleUnicastInChannel()
{
    name = "channel?-?";
}

ConsoleUnicastInChannel::ConsoleUnicastInChannel(int node, int channel) : UnicastInChannel(node, channel)
{
    name = "channel" + std::to_string(node) + "-" + std::to_string(channel);
}

bool ConsoleUnicastInChannel::open()
{
    bopen = true;
    return true;    
}

bool ConsoleUnicastInChannel::close()
{
    bopen = false;
    return true;        
}

bool ConsoleUnicastInChannel::receiveMessages(std::vector<std::string>& listMessages)
{
    std::string text;
    int channelLen = name.length(); 
    
    // read console
    std::getline(std::cin, text);   

    // if text received, extract message (checking proper channel)
    if (!text.empty() && text.length() > channelLen+1)
    {
        std::string prefix = text.substr(0, channelLen);
        std::string message = text.substr(channelLen+1, 100);

        // if proper channel, return message
        if (prefix.compare(name) == 0)
            listMessages.push_back(message);        
    }
    
    return true;
}
}