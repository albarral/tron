/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <ignition/msgs.hh>

#include "tron/coms/ChannelWriter.h"

using namespace log4cxx;

namespace tron
{
ChannelWriter::ChannelWriter()
{    
}

//ChannelWriter::~ChannelWriter()
//{    
//}


bool ChannelWriter::connect(ignition::transport::Node& oNode)
{
    // try subscribing to defined topic
    if (!topic.empty())
    {
        oPublisher = oNode.Advertise<ignition::msgs::StringMsg>(topic);
        bconnected = (oPublisher != 0);
    }
    else
    {
        LOG4CXX_ERROR(logger, "ChannelWriter: failed connection, no topic defined");    
    }   
    
    if (bconnected)
    {
        LOG4CXX_INFO(logger, "ChannelWriter: connected to topic " + topic);
    }
    else
    {
        LOG4CXX_WARN(logger, "ChannelWriter: failed connection to topic " + topic);    
    }   
    return bconnected;
}
    
bool ChannelWriter::sendMessage(std::string message)
{
    ignition::msgs::StringMsg imessage;
    imessage.set_data(message);
    
    if (oPublisher.Publish(imessage))
    {
        LOG4CXX_INFO(logger, "ChannelWriter: sent message " + message);
        return true;        
    }
    else
    {
        LOG4CXX_INFO(logger, "ChannelWriter: failed message sending");
        return false;        
    }
}    

}