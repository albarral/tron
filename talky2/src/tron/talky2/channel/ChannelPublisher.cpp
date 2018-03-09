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

ChannelPublisher::~ChannelPublisher()
{    
    listMessages.clear();
}


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

bool ChannelPublisher::addMessage(int code, float value)
{    
    if (btuned)
    {
        // build message with topic talker
        if (pTalker->buildMessage(code, value, message))
        {
            // and add it to output queue
            listMessages.push_back(message);
        }
        else
        {
            LOG4CXX_WARN(logger, identity + ": add message failed, message not built");                       
            return false;        
        }
    }
    else
    {
        LOG4CXX_WARN(logger, identity + ": add message failed, communicator not tuned");            
        return false;
    }
}


// publish all messages of the output queue 
bool ChannelPublisher::publishAll()
{
    // if output queue is filled
    if (!listMessages.empty())
    {
        // publish messages through wire (wire establishes a publish connection)
        if (oWire.publishMessages(node, topic, listMessages))
            return true;
        else
        {
            LOG4CXX_WARN(logger, identity + ": publish messages failed, no transmission channel");                                      
            return false;        
        }
        // clear output queue
        listMessages.clear();
    }
    else
    {
        LOG4CXX_WARN(logger, identity + ": publish messages ignored, output queue is empty");                       
        return true;        
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