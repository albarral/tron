#ifndef __TRON_WIRE_PUBLISHCHANNEL_H
#define __TRON_WIRE_PUBLISHCHANNEL_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/wire/OutChannel.h"

namespace tron
{
// Base class used to broadcast messages.
class PublishChannel : public OutChannel
{           
public:
    PublishChannel();
};
}
#endif
