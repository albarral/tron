/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "comy/ComyPublisher.h"

namespace comy
{

ComyPublisher::ComyPublisher()
{    
}

void ComyPublisher::setChannel(std::string topic, std::string category)
{
    oChannel.setChannel(Channel::eCHANNEL_BROADCAST, topic, category);
}

}