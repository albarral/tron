#ifndef __COMY_SERVER_H
#define __COMY_SERVER_H

/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "comy/ComyNode.h"

namespace comy
{
// Base class used to listen to messages from clients.
class ComyServer : public ComyNode
{    
protected:
    int channelType; 
    std::string rawMessage;     // received message
    
public:
    ComyServer();
    
   // return obtained text
    std::string getRawMessage() {return rawMessage;};

    // read message from client, returns false if nothing read
    virtual bool readMessage() = 0; 
};
}
#endif
