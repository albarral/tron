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
    
    clearOutputChannelsList(listClientChannels);
    
    clearInputChannelsList(listServerChannels);

    clearOutputChannelsList(listPublishChannels);
    
    clearInputChannelsList(listSubscribeChannels);
}


void Wire::clearInputChannelsList(std::vector<InputChannel*>& listInputChannels)
{
    // delete input channel objects stored in given list
    for (InputChannel* pInputChannel : listInputChannels)
    {
        if (pInputChannel != 0) 
            delete (pInputChannel);
    }
    // and clear the list
    listInputChannels.clear();    
}


void Wire::clearOutputChannelsList(std::vector<OutputChannel*>& listOutputChannels)
{
    // delete output channel objects stored in given list
    for (OutputChannel* pOutputChannel : listOutputChannels)
    {
        if (pOutputChannel != 0) 
            delete (pOutputChannel);
    }
    // and clear the list
    listOutputChannels.clear();
}


// send message by client channel
bool Wire::sendMsg(int node, int channel, std::string text)
{
    // get proper client channel
    OutputChannel* pOutputChannel = searchOutputChannel(node, channel, listClientChannels);

     // if not found, create new 
    if (pOutputChannel == 0)    
    {
        pOutputChannel = createClientChannel(node, channel);
    
        // and add it to list
        if (pOutputChannel != 0)
        {
            listClientChannels.push_back(pOutputChannel);
            LOG4CXX_INFO(logger, "Wire: new client channel " << node << "-" << channel);
        }
    }
            
    // if output channel available, send message through it
    if (pOutputChannel != 0)    
        return pOutputChannel->sendMsg(text); 
    else
    {
        LOG4CXX_WARN(logger, "Wire: send message failed, no channel for node - channel = " << node << " - " << channel);
        return false;
    }
}


// publish message by broadcast channel
bool Wire::publishMsg(int node, int channel, std::string text)
{
    // get proper publish channel
    OutputChannel* pOutputChannel = searchOutputChannel(node, channel, listPublishChannels);

     // if not found, create new 
    if (pOutputChannel == 0)    
    {
        pOutputChannel = createPublishChannel(node, channel);
    
        // and add it to list
        if (pOutputChannel != 0)
        {
            listPublishChannels.push_back(pOutputChannel);
            LOG4CXX_INFO(logger, "Wire: new publish channel " << node << "-" << channel);
        }
    }
            
    // if output channel available, send message through it
    if (pOutputChannel != 0)    
        return pOutputChannel->sendMsg(text); 
    else
    {
        LOG4CXX_WARN(logger, "Wire: publish message failed, no channel for node - channel = " << node << " - " << channel);
        return false;
    }
}

// receive messages by server channel
bool Wire::receiveMessages(int node, int channel, std::vector<std::string>& listMessages)
{
    // get proper server channel
    InputChannel* pInputChannel = searchInputChannel(node, channel, listServerChannels);

     // if not found, create new 
    if (pInputChannel == 0)    
    {
        pInputChannel = createServerChannel(node, channel);
    
        // and add it to list
        if (pInputChannel != 0)
        {
            listServerChannels.push_back(pInputChannel);
            LOG4CXX_INFO(logger, "Wire: new server channel " << node << "-" << channel);
        }
    }
    
    // if input channel available, fetch messages through it
    if (pInputChannel != 0)    
    {   
        listMessages.clear();  
        return pInputChannel->receiveMessages(listMessages);
    }
    else
    {
        LOG4CXX_WARN(logger, "Wire: receive messages failed, no channel for node - channel = " << node << " - " << channel);
        return false;
    }
}


// receive messages by broadcast channel
bool Wire::hearMessages(int node, int channel, std::vector<std::string>& listMessages)
{
    // get proper subscribe channel
    InputChannel* pInputChannel = searchInputChannel(node, channel, listSubscribeChannels);

     // if not found, create new 
    if (pInputChannel == 0)    
    {
        pInputChannel = createSubscribeChannel(node, channel);
    
        // and add it to list
        if (pInputChannel != 0)
        {
            listSubscribeChannels.push_back(pInputChannel);
            LOG4CXX_INFO(logger, "Wire: new subscribe channel " << node << "-" << channel);
        }
    }
    
    // if input channel available, read messages through it
    if (pInputChannel != 0)    
    {   
        listMessages.clear();  
        return pInputChannel->receiveMessages(listMessages);
    }
    else
    {
        LOG4CXX_WARN(logger, "Wire: hear messages failed, no channel for node - channel = " << node << " - " << channel);
        return false;
    }
}


OutputChannel* Wire::searchOutputChannel(int node, int channel, std::vector<OutputChannel*>& listOutputChannels)
{
    // search output channel for given node/channel in the given channels list
    for (OutputChannel* pOutputChannel : listOutputChannels)
    {
        if (pOutputChannel->getNode() == node && pOutputChannel->getChannel() == channel)
            return pOutputChannel;
    }

    // if not found return 0
    return 0;
}


InputChannel* Wire::searchInputChannel(int node, int channel, std::vector<InputChannel*>& listInputChannels)
{
    // search input channel for given node/channel in the given channels list
    for (InputChannel* pInputChannel : listInputChannels)
    {
        if (pInputChannel->getNode() == node && pInputChannel->getChannel() == channel)
            return pInputChannel;
    }

    // if not found return 0
    return 0;
}



}
