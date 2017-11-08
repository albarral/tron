#ifndef __COMY_NODE_H
#define __COMY_NODE_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "comy/Channel.h"

namespace comy
{
// Base class for comy communication nodes
// The channel must be defined before connecting the node.
class ComyNode
{        
protected:
    Channel oChannel;         // comunications channel  
    bool bconnected;            // connected node
    
public:
    ComyNode();
    
    // sets communications channel
    virtual void connect(std::string topic, std::string category) = 0;
    Channel& getChannel() {return oChannel;};
    bool isConnected() {return bconnected;};

protected:
    void setChannel(int type, std::string topic, std::string category);

};
}
#endif
