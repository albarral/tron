/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <iostream>

#include "tron/wire/console/ConsoleInChannel.h"

namespace tron
{

ConsoleInChannel::ConsoleInChannel()
{
    name = "channel?-?";
}

ConsoleInChannel::ConsoleInChannel(int node, int channel) : InChannel(node, channel)
{
    name = "channel" + std::to_string(node) + "-" + std::to_string(channel);
}

bool ConsoleInChannel::open()
{
    bopen = true;
    return true;    
}

bool ConsoleInChannel::close()
{
    bopen = false;
    return true;        
}

bool ConsoleInChannel::receiveMessages(std::vector<std::string>& listMessages)
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