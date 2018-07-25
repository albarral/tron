/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/coms/ComsChannel.h"

using namespace log4cxx;

namespace tron
{
LoggerPtr ComsChannel::logger(Logger::getLogger("tron.com"));

ComsChannel::ComsChannel()
{    
    topic = "";
    bconnected = false;
}

//ComsChannel::~ComsChannel()
//{    
//}

}