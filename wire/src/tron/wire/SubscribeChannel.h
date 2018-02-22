#ifndef __TRON_WIRE_SUBSCRIBECHANNEL_H
#define __TRON_WIRE_SUBSCRIBECHANNEL_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/wire/InChannel.h"

namespace tron
{
// Base class used to receive broadcasted messages.
class SubscribeChannel : public InChannel
{           
public:
    SubscribeChannel();
};
}
#endif
