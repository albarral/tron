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

bool ConsolePublishChannel::sendMsg(std::string text)
{
    std::cout << name + ":" + text << std::endl;    
    return true;    
}
}