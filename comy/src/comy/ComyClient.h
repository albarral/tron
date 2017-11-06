#ifndef __COMY_CLIENT_H
#define __COMY_CLIENT_H

/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "comy/ComyNode.h"

namespace comy
{
// Base class used to transmit messages to a server.
class ComyClient : public ComyNode
{        
public:
    ComyClient();

    // sets communications channel
    virtual void setChannel(std::string topic, std::string category);
    virtual void connect() = 0;

    // send message to server, returns false if nothing sent
    virtual bool sendMessage(std::string text) = 0;
};
}
#endif
