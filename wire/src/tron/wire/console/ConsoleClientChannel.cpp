/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <iostream>

#include "tron/wire/console/ConsoleClientChannel.h"

namespace tron
{
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