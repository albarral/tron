/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/wire/Wire.h"

using namespace log4cxx;

namespace tron
{
LoggerPtr Wire::logger(Logger::getLogger("tron.wire"));

Wire::Wire()
{    
}

Wire::~Wire()
{
    clearChannels();
}

void Wire::clearChannels()
{
    LOG4CXX_INFO(logger, "Wire: clearing channels ...");
    // delete out channel objects pointed to from the lists
    for (OutChannel* pOutChannel : listOutChannels)
    {
        if (pOutChannel != 0) 
            delete (pOutChannel);
    }
    // and clear the list
    listOutChannels.clear();
    
    // delete in channel objects pointed to from the lists
    for (InChannel* pInChannel : listInChannels)
    {
        if (pInChannel != 0) 
            delete (pInChannel);
    }
    // and clear the list
    listInChannels.clear();

    // delete publish channel objects pointed to from the lists
    for (PublishChannel* pPublishChannel : listPublishChannels)
    {
        if (pPublishChannel != 0) 
            delete (pPublishChannel);
    }
    // and clear the list
    listPublishChannels.clear();
    
    // delete subscribe channel objects pointed to from the lists
    for (SubscribeChannel* pSubscribeChannel : listSubscribeChannels)
    {
        if (pSubscribeChannel != 0) 
            delete (pSubscribeChannel);
    }
    // and clear the list
    listSubscribeChannels.clear();    
}

// send message by p2p channel
bool Wire::sendMsg(int node, int channel, std::string text)
{
    // get proper output channel
    OutChannel* pOutChannel = getOutChannel(node, channel); 
    
    // and send message through it
    if (pOutChannel != 0)    
        return pOutChannel->sendMsg(text); 
    else
    {
        LOG4CXX_WARN(logger, "Wire: send message failed, no channel for node - channel = " << node << " - " << channel);
        return false;
    }
}


// receive messages by p2p channel
bool Wire::receiveMessages(int node, int channel, std::vector<std::string>& listMessages)
{
    // get proper in channel
    InChannel* pInChannel = getInChannel(node, channel); 
    
    // and fetch messages through it
    if (pInChannel != 0)    
    {   
        listMessages.clear();  
        return pInChannel->receiveMessages(listMessages);
    }
    else
    {
        LOG4CXX_WARN(logger, "Wire: receive messages failed, no channel for node - channel = " << node << " - " << channel);
        return false;
    }
}


OutChannel* Wire::getOutChannel(int node, int channel)
{
    // search proper out channel (pointer) in the channels list
    for (OutChannel* pOutChannel : listOutChannels)
    {
        if (pOutChannel->getNode() == node && pOutChannel->getChannel() == channel)
            return pOutChannel;
    }
    
    LOG4CXX_INFO(logger, "Wire: new out channel for " << node << "-" << channel);

    // if not found, create new out channel
    OutChannel* pOutChannel2 = createOutChannel(node, channel);
    
    // and add it (pointer) to list
    if (pOutChannel2 != 0)
    {
        listOutChannels.push_back(pOutChannel2);
    }

    // return pointer to the created channel
    return pOutChannel2;
}


InChannel* Wire::getInChannel(int node, int channel)
{
    // search proper out channel (pointer) in the channels list
    for (InChannel* pInChannel : listInChannels)
    {
        if (pInChannel->getNode() == node && pInChannel->getChannel() == channel)
            return pInChannel;
    }
    
    LOG4CXX_INFO(logger, "Wire: new in channel for " << node << "-" << channel);

    // if not found, create new in channel
    InChannel* pInChannel2 = createInChannel(node, channel);
    
    // and add it (pointer) to list
    if (pInChannel2 != 0)
    {
        listInChannels.push_back(pInChannel2);
    }

    // return pointer to the created channel
    return pInChannel2;
}
}
