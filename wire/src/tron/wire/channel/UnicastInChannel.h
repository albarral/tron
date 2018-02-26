#ifndef __TRON_WIRE_UNICASTINCHANNEL_H
#define __TRON_WIRE_UNICASTINCHANNEL_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/wire/channel/InputChannel.h"

namespace tron
{
// Base class used to receive messages in unicast communications.
class UnicastInChannel : public InputChannel
{           
public:
    UnicastInChannel();
    UnicastInChannel(int node, int channel);
};
}
#endif
