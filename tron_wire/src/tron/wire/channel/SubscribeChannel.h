#ifndef __TRON_WIRE_SUBSCRIBECHANNEL_H
#define __TRON_WIRE_SUBSCRIBECHANNEL_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/wire/channel/InputChannel.h"

namespace tron
{
// Base class used to receive broadcasted messages.
class SubscribeChannel : public InputChannel
{           
public:
    SubscribeChannel();
    SubscribeChannel(int node, int channel);

    // clear info in channel
    virtual bool clearInfo();    
};
}
#endif
