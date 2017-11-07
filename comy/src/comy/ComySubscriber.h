#ifndef __COMY_SUBSCRIBER_H
#define __COMY_SUBSCRIBER_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "comy/ComyNode.h"

namespace comy
{
// Base class used to subscribe to communication messages.
class ComySubscriber : public ComyNode
{    
protected:
    int channelType; 
    std::string rawMessage;     // received message
        
public:
    ComySubscriber();

    // return obtained text
    std::string getRawMessage() {return rawMessage;};
       
    // info reading method 
    virtual bool readMessage() = 0;
};
}
#endif
