/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <iostream>

#include "tron/wire/console/ConsolePublishChannel.h"

namespace tron
{
bool ConsolePublishChannel::open()
{
    bopen = true;
    return bopen;    
}

bool ConsolePublishChannel::close()
{
    bopen = false;
    return (bopen == false);        
}

bool ConsolePublishChannel::clearInfo()
{
    // not really an info clearing 
    std::cout << name + ":" << std::endl;                
    return true;    
}

bool ConsolePublishChannel::sendMsg(std::string message)
{
    // write message to console
    std::cout << name + ":" + message << std::endl;    
    return true;    
}

bool ConsolePublishChannel::sendMessages(std::vector<std::string>& listMessages)
{
    for (std::string message : listMessages)
    {       
        // write message to console
        std::cout << name + ":" + message << std::endl;    
    }
    return true;    
}

}