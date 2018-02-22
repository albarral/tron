/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/wire/Channel.h"

using namespace log4cxx;

namespace tron
{
LoggerPtr Channel::logger(Logger::getLogger("tron.wire"));

Channel::Channel()
{    
    type = Channel::eCHANNEL_P2P;
    node = -1;
    channel = -1;
    bopen = false;
}
}