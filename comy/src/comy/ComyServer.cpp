/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/


#include "comy/ComyServer.h"

namespace comy
{

ComyServer::ComyServer()
{    
    channelType = Channel::eCHANNEL_SERVED;
}

bool ComyServer::readMessages()
{
    bool bend = false;
    int reads = 0;
    // read messages iteratively putting them in the queue 
    while (!bend)
    {
        std::string message = readMessage();
        if (!message.empty())
        {
            oMessageQueue.add(message);
            reads++;
        }
        else
            bend = true;
    }
    
    // informs the read has finished
    //readFinished();
    
    return (reads > 0);
}

bool ComyServer::hasMessages()
{
    oMessageQueue.isFilled();
}

std::string ComyServer::getMessage()
{
    return oMessageQueue.fetch();
}

}