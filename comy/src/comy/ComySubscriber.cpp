/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "comy/ComySubscriber.h"

namespace comy
{

ComySubscriber::ComySubscriber()
{    
}

void ComySubscriber::setChannel(std::string topic, std::string category)
{
    oChannel.setChannel(Channel::eCHANNEL_BROADCAST, topic, category);
}
}