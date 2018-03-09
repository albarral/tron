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
    bool bok = false;
    if (btuned)
    {
        // build message with topic talker
        if (pTalker->buildMessage(code, value, message))
        {
            // send message through wire (wire establishes a client connection)
            if (oWire.sendMsg(node, topic, message))
                bok = true;
            else
            {
                LOG4CXX_WARN(logger, identity + ": send message failed, no transmission channel");                                      
            }
        }
        else
        {
            LOG4CXX_WARN(logger, identity + ": send message failed, message not built");                       
        }
    }
    else
    {
        LOG4CXX_WARN(logger, identity + ": send message failed, communicator not tuned");            
    }
    return bok;
}

void ChannelClient::setIdentity()
{
    identity = "ChannelClient" + std::to_string(node) + "- " + std::to_string(topic);
    
}
}