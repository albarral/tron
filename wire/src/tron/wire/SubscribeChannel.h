#ifndef __TRON_WIRE_SUBSCRIBECHANNEL_H
#define __TRON_WIRE_SUBSCRIBECHANNEL_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/wire/Channel.h"

namespace tron
{
// Base class used to receive broadcasted messages.
class SubscribeChannel : public Channel
{           
public:
    SubscribeChannel();
    SubscribeChannel(int node, int channel);

    // read broadcasted messages in this channel, returns false if nothing received
    virtual bool readMessages(std::vector<std::string>& listMessages) = 0;    
};
}
#endif
