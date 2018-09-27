/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/coms/ComsSender.h"

using namespace log4cxx;

namespace tron
{
ComsSender::ComsSender()
{    
    type = Communicator::eTYPE_SENDER;
}

ComsSender::~ComsSender()
{
    listChannelWriters.clear();
}
    
void ComsSender::addChannel(std::string topic)
{
    ChannelWriter oChannelWriter;
    oChannelWriter.setTopic(topic);
    oChannelWriter.connect(oNode);
    
    listChannelWriters.push_back(oChannelWriter);
    LOG4CXX_INFO(logger, "ComsSender: added channel writer for topic " + topic);
}

ChannelWriter* ComsSender::getChannel(int i)
{
    if (i >= 0 && i < listChannelWriters.size())
        return &(listChannelWriters.at(i));
    else
        return nullptr;    
}

std::string ComsSender::toString()
{
    std::string desc = "ComsSender channel writers:";
    for (ChannelWriter& oChannelWriter : listChannelWriters)
    {
        desc += oChannelWriter.getTopic() + "\n";        
    }
    
    return desc;    
}
}