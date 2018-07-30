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
    // (IMPORTANT) We must connect the real reader existing in the list (as the callback is bound to the object).
    listChannelReaders.back().connect(oNode);
    LOG4CXX_INFO(logger, "ComsReceiver: added channel reader for topic " + topic);
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