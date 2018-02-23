#ifndef __TRON_WIRE_OUTCHANNEL_H
#define __TRON_WIRE_OUTCHANNEL_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "tron/wire/Channel.h"

namespace tron
{
// Base class used to transmit messages to a destination node.
class OutChannel : public Channel
{           
public:
    OutChannel();
    OutChannel(int node, int channel);
   
    // send message to destination, returns false if nothing sent
    virtual bool sendMsg(std::string text) = 0;
};
}
#endif
