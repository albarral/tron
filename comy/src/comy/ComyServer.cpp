/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/


#include "comy/ComyServer.h"

namespace comy
{

ComyServer::ComyServer()
{    
}

void ComyServer::setChannel(std::string topic, std::string category)
{
    oChannel.setChannel(Channel::eCHANNEL_SERVED, topic, category);
}

}