/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/talky2/channel/ChannelListener.h"

using namespace log4cxx;

namespace tron
{
ChannelListener::ChannelListener(int node, int topic) : ChannelCommunicator(node, topic)
{    
    setIdentity();
}

ChannelListener::~ChannelListener()
{    
    listMessages.clear();
}


bool ChannelListener::senseChannel()
{    
    // clear message queue
    listMessages.clear();  
    // hear messages in joints channel
    if (oWire.hearMessages(node, topic, listMessages))                    
        return true;
    else
    {
        LOG4CXX_WARN(logger, identity + ": sense channel failed, no reception channel");                                      
        return false;        
    }
}

void ChannelListener::setIdentity()
{
    identity = "ChannelListener" + std::to_string(node) + "- " + std::to_string(topic);
    
}
}