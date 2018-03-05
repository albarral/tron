/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/talky2/channel/ChannelServer.h"

using namespace log4cxx;

namespace tron
{
ChannelServer::ChannelServer(int node, int topic) : ChannelCommunicator(node, topic)
{    
    setIdentity();
}

ChannelServer::~ChannelServer()
{    
    listMessages.clear();
}


bool ChannelServer::senseChannel()
{    
    // clear message queue
    listMessages.clear();  
    // hear messages in joints channel
    if (oWire.receiveMessages(node, topic, listMessages))                    
        return true;
    else
    {
        LOG4CXX_WARN(logger, identity + ": sense channel failed, no reception channel");                                      
        return false;        
    }
}

void ChannelServer::setIdentity()
{
    identity = "ChannelServer" + std::to_string(node) + "- " + std::to_string(topic);
    
}
}