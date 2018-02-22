#ifndef __TRON_WIRE_INCHANNEL_H
#define __TRON_WIRE_INCHANNEL_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <vector>

#include "tron/wire/Channel.h"

namespace tron
{
// Base class used to receive messages from an origin node.
class InChannel : public Channel
{           
public:
    InChannel();
   
    // receive messages from origin, returns false if nothing received
    virtual bool receiveMessages(std::vector<std::string>& listMessages) = 0;
};
}
#endif
