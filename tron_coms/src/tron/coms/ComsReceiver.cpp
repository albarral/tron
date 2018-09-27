/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/coms/ComsReceiver.h"

using namespace log4cxx;

namespace tron
{
ComsReceiver::ComsReceiver()
{    
    type = Communicator::eTYPE_RECEIVER;
}

ComsReceiver::~ComsReceiver()
{
    listChannelReaders.clear();
}
    
void ComsReceiver::addChannel(std::string topic)
{
    // create channel reader and add it to list
    ChannelReader oChannelReader;
    oChannelReader.setTopic(topic);    
    listChannelReaders.push_back(oChannelReader);

    LOG4CXX_INFO(logger, "ComsReceiver: added channel reader for topic " + topic);
}

void ComsReceiver::connect()
{
    // (IMPORTANT) we must connect all readers when the list is stable (to grant callbacks bound to final objects).
    for (ChannelReader& oChannelReader : listChannelReaders)
        oChannelReader.connect(oNode);
    LOG4CXX_INFO(logger, "ComsReceiver: channels connected");
}

ChannelReader* ComsReceiver::getChannel(int i)
{
    if (i >= 0 && i < listChannelReaders.size())
        return &(listChannelReaders.at(i));
    else
        return nullptr;    
}

std::string ComsReceiver::toString()
{
    std::string desc = "ComsReceiver channel readers:";
    for (ChannelReader& oChannelReader : listChannelReaders)
    {
        desc += oChannelReader.getTopic() + "\n";        
    }
    
    return desc;    
}
}