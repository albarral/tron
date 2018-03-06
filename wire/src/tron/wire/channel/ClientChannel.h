#ifndef __TRON_WIRE_CLIENTCHANNEL_H
#define __TRON_WIRE_CLIENTCHANNEL_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/wire/channel/OutputChannel.h"

namespace tron
{
// Base class used to transmit messages in unicast communications.
class ClientChannel : public OutputChannel
{           
public:
    ClientChannel();
    ClientChannel(int node, int channel);
    
    // clear info in channel
    virtual bool clearInfo();    
};
}
#endif
