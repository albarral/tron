#ifndef __COMY_SUBSCRIBER_H
#define __COMY_SUBSCRIBER_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "comy/ComyNode.h"
#include "tuly/utils/MessageQueue.h"

namespace comy
{
// Base class used to subscribe to communication messages.
// It works with a message queue to be consumed on demand.
class ComySubscriber : public ComyNode
{    
protected:
    tuly::MessageQueue oMessageQueue;       // messages queue
        
public:
    ComySubscriber();

    // read messages from publishers and puts them in the queue, returns false if nothing read
    bool readMessages();
    // checks if queue has pending messages
    bool hasMessages();
    // returns number of messages in queue
    int getQueueSize();
    // fetches first message in the queue
    std::string fetchMessage();
       
protected:    
    // read message from publishers, returns empty if nothing read
    virtual std::string readSingleMessage() = 0; 
    // get all new messages received
    virtual bool getNewMessages(std::vector<std::string>& listMessages) = 0; 
};
}
#endif
