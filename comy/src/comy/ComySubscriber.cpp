/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <vector>

#include "comy/ComySubscriber.h"

namespace comy
{

ComySubscriber::ComySubscriber()
{
    channelType = Channel::eCHANNEL_BROADCAST;    
}

bool ComySubscriber::readMessages()
{        
    std::vector<std::string> listMessages;
            
    // read new messages and put them in the queue
    if (getNewMessages(listMessages))
    {
        for (std::string message : listMessages)
            oMessageQueue.add(message);
    }

    if (!listMessages.empty())
    {
        listMessages.clear();
        return true;        
    }
    else 
        return false;
}

bool ComySubscriber::hasMessages()
{
    oMessageQueue.isFilled();
}

int ComySubscriber::getQueueSize()
{
    oMessageQueue.getSize();    
}

std::string ComySubscriber::fetchMessage()
{
    return oMessageQueue.fetch();
}

}