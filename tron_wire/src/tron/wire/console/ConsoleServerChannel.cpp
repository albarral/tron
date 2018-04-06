/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <iostream>

#include "tron/wire/console/ConsoleServerChannel.h"

namespace tron
{
bool ConsoleServerChannel::open()
{
    bopen = true;
    return bopen;    
}

bool ConsoleServerChannel::close()
{
    bopen = false;
    return (bopen == false);        
}

bool ConsoleServerChannel::clearInfo()
{
    // not really an info clearing 
    std::cout << name + ":" << std::endl;                    
    return true;    
}

bool ConsoleServerChannel::receiveMessages(std::vector<std::string>& listMessages)
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