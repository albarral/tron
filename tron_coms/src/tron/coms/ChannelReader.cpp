/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <functional>

#include "tron/coms/ChannelReader.h"

using namespace log4cxx;

namespace tron
{
ChannelReader::ChannelReader()
{    
}

ChannelReader::~ChannelReader()
{    
    listMessages.clear();
}

bool ChannelReader::connect(ignition::transport::Node& oNode)
{
    // try subscribing to defined topic
    if (!topic.empty())
    {
        std::function<void(const ignition::msgs::StringMsg& imessage)> cb = std::bind(&ChannelReader::processMessage, this, std::placeholders::_1);
        bconnected = oNode.Subscribe(topic, cb);
    }
    else
    {
        LOG4CXX_ERROR(logger, "ChannelReader: failed connection, no topic defined");    
    }   
    
    if (bconnected)
    {
        LOG4CXX_DEBUG(logger, "ChannelReader: connected to topic " + topic);
    }
    else
    {
        LOG4CXX_WARN(logger, "ChannelReader: failed connection to topic " + topic);    
    }   
    return bconnected;
}
    
int ChannelReader::getMessages(std::vector<std::string>& listMessages)
{
    // TO DO: needs mutex
    
    // overwrite destination list
    listMessages = this->listMessages;
    // clear source list
    this->listMessages.clear();
    return listMessages.size();
}    

void ChannelReader::processMessage(const ignition::msgs::StringMsg& imessage)
{
    // TO DO: needs mutex

    listMessages.push_back(imessage.data());
    LOG4CXX_DEBUG(logger, "ChannelReader: message received " + imessage.data());
}

}