/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "comy/ComyNode.h"

namespace comy
{

ComyNode::ComyNode()
{    
    bconnected = false;
}

void ComyNode::setChannel(int type, std::string topic, std::string category)
{
    oChannel.setChannel(type, topic, category);
}
}