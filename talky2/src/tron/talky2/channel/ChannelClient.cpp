/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/talky2/channel/ChannelClient.h"

using namespace log4cxx;

namespace tron
{
ChannelClient::ChannelClient(int node, int topic) : ChannelCommunicator(node, topic)
{    
    setIdentity();
}

//ChannelClient::~ChannelClient()
//{    
//}


bool ChannelClient::sendMessage(int code, float value)
{    
    if (btuned)
    {
        // build message with topic talker
        if (pTalker->buildMessage(code, value, message))
        {
            // send message through wire (wire establishes a client connection)
            if (oWire.sendMsg(node, topic, message))
                return true;
            else
            {
                LOG4CXX_WARN(logger, identity + ": send message failed, no transmission channel");                                      
                return false;        
            }
        }
        else
        {
            LOG4CXX_WARN(logger, identity + ": send message failed, message not built");                       
            return false;        
        }
    }
    else
    {
        LOG4CXX_WARN(logger, identity + ": send message failed, communicator not tuned");            
        return false;
    }
}

void ChannelClient::setIdentity()
{
    identity = "ChannelClient" + std::to_string(node) + "- " + std::to_string(topic);
    
}
}