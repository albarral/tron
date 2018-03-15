/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/talky2/channel/ChannelSubscriber.h"

using namespace log4cxx;

namespace tron
{
ChannelSubscriber::ChannelSubscriber(int node, int topic) : ChannelCommunicator(node, topic)
{    
    setIdentity();
}

ChannelSubscriber::~ChannelSubscriber()
{    
    listMessages.clear();
}


bool ChannelSubscriber::senseChannel()
{    
    // clear messages queue
    listMessages.clear();  
    // hear messages from wire (wire establishes a subscriber connection)
    if (oWire.hearMessages(node, topic, listMessages))                    
        return true;
    else
    {
        LOG4CXX_WARN(logger, identity + ": sense channel failed, no reception channel");                                      
        return false;        
    }
}

void ChannelSubscriber::setIdentity()
{
    identity = "ChannelSubscriber" + std::to_string(node) + "- " + std::to_string(topic);
    
}
}