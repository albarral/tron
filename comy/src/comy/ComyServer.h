#ifndef __COMY_COMYSERVER_H
#define __COMY_COMYSERVER_H

/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <vector>

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
    // returns number of messages in queue
    int getQueueSize();
    // fetches first message in the queue
    std::string getMessage();
    
protected:    
    // read message from client, returns empty if nothing read
    virtual std::string readSingleMessage() = 0; 
    // get all new messages received
    virtual bool getNewMessages(std::vector<std::string>& listMessages) = 0; 
};
}
#endif
