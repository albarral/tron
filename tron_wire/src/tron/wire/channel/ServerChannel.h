#ifndef __TRON_WIRE_SERVERCHANNEL_H
#define __TRON_WIRE_SERVERCHANNEL_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/wire/channel/InputChannel.h"

namespace tron
{
// Base class used to receive messages in unicast communications.
class ServerChannel : public InputChannel
{           
public:
    ServerChannel();
    ServerChannel(int node, int channel);
};
}
#endif
