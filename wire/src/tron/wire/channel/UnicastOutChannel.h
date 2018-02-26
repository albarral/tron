#ifndef __TRON_WIRE_UNICASTOUTCHANNEL_H
#define __TRON_WIRE_UNICASTOUTCHANNEL_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/wire/channel/OutputChannel.h"

namespace tron
{
// Base class used to transmit messages in unicast communications.
class UnicastOutChannel : public OutputChannel
{           
public:
    UnicastOutChannel();
    UnicastOutChannel(int node, int channel);
};
}
#endif
