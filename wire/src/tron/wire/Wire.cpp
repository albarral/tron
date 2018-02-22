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

Wire::clearChannels()
{
    listOutputChannels.clear();
    listInputChannels.clear();
    listPublishChannels.clear();
    listSubscribeChannels.clear();    
}

// p2p send
bool Wire::sendMsg(int node, int channel, std::string text)
{
    // send message through the proper output channel
    OutChannel& oOutChannel = getOutChannel(node, channel); 
    
    return oOutChannel.sendMsg(text); 
}

OutChannel& Wire::getOutChannel(int node, int channel)
{
    // search proper channel in out channels list
    for (OutChannel& oOutChannel : listOutputChannels)
    {
        if (oOutChannel.getNode() == node && oOutChannel.getNode() == node)
            return oOutChannel;
    }
    
    // not found, create new one
    OutChannel* pOutChannel = createOutChannel(node, channel);
    
    // and add it to list
    if (pOutChannel != 0)
    {
        listOutputChannels.push_back(*pOutChannel);
        return listOutputChannels.back();
    }
    else
    {
        return NULL;
    }
}

}
