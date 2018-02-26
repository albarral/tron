#ifndef __TRON_WIRE_PUBLISHCHANNEL_H
#define __TRON_WIRE_PUBLISHCHANNEL_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/wire/channel/OutputChannel.h"

namespace tron
{
// Base class used to broadcast messages.
class PublishChannel : public OutputChannel
{           
public:
    PublishChannel();
    PublishChannel(int node, int channel);
};
}
#endif
