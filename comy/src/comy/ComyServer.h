#ifndef __COMY_SERVER_H
#define __COMY_SERVER_H

/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "comy/ComyNode.h"
#include "tuly/utils/MessageQueue.h"

namespace comy
{
// Base class used to read communication messages sent by comy clients.
// It works with a message queue to be consumed on demand.
class ComyServer : public ComyNode
{    
protected:
    tuly::MessageQueue oMessageQueue;       // messages queue
    
public:
    ComyServer();
    //~ComyFileServer();
    
    // read messages from client and puts them in the queue, returns false if nothing read
    bool readMessages();
    // checks if queue has pending messages
    bool hasMessages();
    // fetches first message in the queue
    std::string getMessage();
    
protected:    
    // read message from client, returns empty if nothing read
    virtual std::string readMessage() = 0; 
    // informs the read messages call has finished 
    //virtual void readFinished() = 0;
};
}
#endif
