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
    bool bok = false;
    if (btuned)
    {
        // build message with topic talker
        if (pTalker->buildMessage(code, value, message))
        {
            // publish message through wire (wire establishes a publish connection)
            if (oWire.publishMsg(node, topic, message))
                bok = true;
            else
            {
                LOG4CXX_WARN(logger, identity + ": publish message failed, no transmission channel");                                      
            }
        }
        else
        {
            LOG4CXX_WARN(logger, identity + ": publish message failed, message not built");                       
        }
    }
    else
    {
        LOG4CXX_WARN(logger, identity + ": publish message failed, communicator not tuned");            
    }
    return bok;
}

bool ChannelPublisher::addMessage(int code, float value)
{    
    bool bok = false;
    if (btuned)
    {
        // build message with topic talker
        if (pTalker->buildMessage(code, value, message))
        {
            // and add it to output queue
            listMessages.push_back(message);
            bok = true;
        }
        else
        {
            LOG4CXX_WARN(logger, identity + ": add message failed, message not built");                       
        }
    }
    else
    {
        LOG4CXX_WARN(logger, identity + ": add message failed, communicator not tuned");            
    }
    return bok;
}


// publish all messages of the output queue 
bool ChannelPublisher::publishAll()
{
    bool bok = false;
    // if output queue is filled
    if (!listMessages.empty())
    {
        // publish messages through wire (wire establishes a publish connection)
        if (oWire.publishMessages(node, topic, listMessages))
            bok = true;
        else
        {
            LOG4CXX_WARN(logger, identity + ": publish messages failed, no transmission channel");                                      
        }
        // anyway clear output queue
        listMessages.clear();
    }
    else
    {
        LOG4CXX_WARN(logger, identity + ": publish messages ignored, output queue is empty");                       
    }    
    return bok;
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