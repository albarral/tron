/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/


#include "comy/ComyServer.h"

namespace comy
{

ComyServer::ComyServer()
{    
    channelType = Channel::eCHANNEL_P2P;
}

//ComyServer::~ComyServer()
//{
//}

bool ComyServer::readMessages()
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

bool ComyServer::hasMessages()
{
    oMessageQueue.isFilled();
}

int ComyServer::getQueueSize()
{
    oMessageQueue.getSize();    
}

std::string ComyServer::fetchMessage()
{
    return oMessageQueue.fetch();
}

}