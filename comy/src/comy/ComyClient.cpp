/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "comy/ComyClient.h"

namespace comy
{

ComyClient::ComyClient()
{    
}

void ComyClient::setChannel(std::string topic, std::string category)
{
    oChannel.setChannel(Channel::eCHANNEL_SERVED, topic, category);
}
}