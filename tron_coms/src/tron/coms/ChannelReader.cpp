/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/coms/ChannelReader.h"

using namespace log4cxx;

namespace tron
{
ChannelReader::ChannelReader()
{    
}

//ChannelReader::~ChannelReader()
//{    
//}

void ChannelReader::cb(const ignition::msgs::StringMsg& imessage)
{
    listMessages.push_back(imessage.data());
    LOG4CXX_DEBUG(logger, "ChannelReader: message received " + imessage.data());
}

bool ChannelReader::connect(ignition::transport::Node& oNode)
{
    // try subscribing to defined topic
    if (!topic.empty())
        bconnected = oNode.Subscribe(topic, ChannelReader::cb);
    else
    {
        LOG4CXX_ERROR(logger, "ChannelReader: failed connection, no topic defined");    
    }   
    
    if (bconnected)
    {
        LOG4CXX_INFO(logger, "ChannelReader: connected to topic " + topic);
    }
    else
    {
        LOG4CXX_WARN(logger, "ChannelReader: failed connection to topic " + topic);    
    }   
    return bconnected;
}
    
int ChannelReader::getMessages(std::vector<std::string>& listMessages)
{
    // overwrite destination list
    listMessages = this->listMessages;
    // clear source list
    this->listMessages.clear();
    return listMessages.size();
}    

}