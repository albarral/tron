#ifndef __TRON_WIRE_PUBLISHCHANNEL_H
#define __TRON_WIRE_PUBLISHCHANNEL_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/wire/Channel.h"

namespace tron
{
// Base class used to broadcast messages.
class PublishChannel : public Channel
{           
public:
    PublishChannel();
    PublishChannel(int node, int channel);
    
    // broadcast message through this channel, returns false if nothing sent
    virtual bool publishMsg(std::string text) = 0;    
};
}
#endif
