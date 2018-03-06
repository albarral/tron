/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/talky2/channel/ChannelPublisher.h"

using namespace log4cxx;

namespace tron
{
ChannelPublisher::ChannelPublisher(int node, int topic) : ChannelCommunicator(node, topic)
{    
    setIdentity();
}

//ChannelPublisher::~ChannelPublisher()
//{    
//}


bool ChannelPublisher::publishMessage(int code, float value)
{    
    if (btuned)
    {
        // build message with topic talker
        if (pTalker->buildMessage(code, value, message))
        {
            // publish message through wire (wire establishes a publish connection)
            if (oWire.publishMsg(node, topic, message))
                return true;
            else
            {
                LOG4CXX_WARN(logger, identity + ": publish message failed, no transmission channel");                                      
                return false;        
            }
        }
        else
        {
            LOG4CXX_WARN(logger, identity + ": publish message failed, message not built");                       
            return false;        
        }
    }
    else
    {
        LOG4CXX_WARN(logger, identity + ": publish message failed, communicator not tuned");            
        return false;
    }
}

bool ChannelPublisher::clearChannel()
{
    // clear the info in our wire's publish channel
    if (oWire.clearPublishChannel(node, topic))
        return true;
    else
    {
        LOG4CXX_WARN(logger, identity + ": clear channel failed, no publisher channel");                                      
        return false;        
    }    
}

void ChannelPublisher::setIdentity()
{
    identity = "ChannelPublisher" + std::to_string(node) + "- " + std::to_string(topic);
    
}
}