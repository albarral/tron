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
    deleteChannels();
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
    
        // open channel and add it to list
        if (pOutputChannel != 0)
        {
             if (pOutputChannel->open())
            {
                listClientChannels.push_back(pOutputChannel);
                LOG4CXX_INFO(logger, "Wire: new client channel " + pOutputChannel->getName());
            }
            else
                pOutputChannel = 0;
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
    
        // open channel and add it to list
        if (pOutputChannel != 0)
        {
            if (pOutputChannel->open())
            {
                listPublishChannels.push_back(pOutputChannel);
                LOG4CXX_INFO(logger, "Wire: new publish channel " + pOutputChannel->getName());
            }
            else
                pOutputChannel = 0;
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
    
        // open channel and add it to list
        if (pInputChannel != 0)
        {
            if (pInputChannel->open())
            {
                listServerChannels.push_back(pInputChannel);
                LOG4CXX_INFO(logger, "Wire: new server channel " + pInputChannel->getName());
            }
            else
                pInputChannel = 0;
        }
    }
    
    // if input channel available, fetch messages through it
    if (pInputChannel != 0)    
    {   
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
    
        // open channel and add it to list
        if (pInputChannel != 0)
        {
            if (pInputChannel->open())
            {
                listSubscribeChannels.push_back(pInputChannel);
                LOG4CXX_INFO(logger, "Wire: new subscribe channel " + pInputChannel->getName());
            }
            else
                pInputChannel = 0;
        }
    }
    
    // if input channel available, read messages through it
    if (pInputChannel != 0)    
    {   
        return pInputChannel->receiveMessages(listMessages);
    }
    else
    {
        LOG4CXX_WARN(logger, "Wire: hear messages failed, no channel for node - channel = " << node << " - " << channel);
        return false;
    }
}


bool Wire::clearPublishChannel(int node, int channel)
{
    // get proper publish channel
    OutputChannel* pOutputChannel = searchOutputChannel(node, channel, listPublishChannels);
            
    // if publish channel available, clear its info
    if (pOutputChannel != 0)    
        return pOutputChannel->clearInfo();
    else
    {
        LOG4CXX_WARN(logger, "Wire: clear publish channel failed, no channel for node - channel = " << node << " - " << channel);
        return false;
    }    
}


bool Wire::clearServerChannel(int node, int channel)
{
    // get proper server channel
    InputChannel* pInputChannel = searchInputChannel(node, channel, listServerChannels);
    
    // if input server available, clear its info
    if (pInputChannel != 0)    
    {   
        return pInputChannel->clearInfo();
    }
    else
    {
        LOG4CXX_WARN(logger, "Wire: clear server channel failed, no channel for node - channel = " << node << " - " << channel);
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


void Wire::deleteChannels()
{    
    deleteOutputChannels(listClientChannels);    
    deleteInputChannels(listServerChannels);
    deleteOutputChannels(listPublishChannels);   
    deleteInputChannels(listSubscribeChannels);
}


void Wire::deleteInputChannels(std::vector<InputChannel*>& listInputChannels)
{
    // delete input channel objects stored in given list
    for (InputChannel* pInputChannel : listInputChannels)
    {    
       LOG4CXX_INFO(logger, "Wire: clear " + pInputChannel->getMode() + " channel " + pInputChannel->getName());
       if (pInputChannel != 0) 
            delete (pInputChannel);
    }
    // and clear the list
    listInputChannels.clear();    
}


void Wire::deleteOutputChannels(std::vector<OutputChannel*>& listOutputChannels)
{
    // delete output channel objects stored in given list
    for (OutputChannel* pOutputChannel : listOutputChannels)
    {    
       LOG4CXX_INFO(logger, "Wire: clear " + pOutputChannel->getMode() + " channel " + pOutputChannel->getName());
        if (pOutputChannel != 0) 
            delete (pOutputChannel);
    }
    // and clear the list
    listOutputChannels.clear();
}

}
