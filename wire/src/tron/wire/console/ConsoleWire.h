#ifndef __TRON_WIRE_CONSOLEWIRE_H
#define __TRON_WIRE_CONSOLEWIRE_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/


#include "tron/wire/InChannel.h"
#include "tron/wire/OutChannel.h"
#include "tron/wire/PublishChannel.h"
#include "tron/wire/SubscribeChannel.h"
#include "tron/wire/Wire.h"

namespace tron
{
// Implementation of the Wire class for multichannel communications through the console..
class ConsoleWire : public Wire
{            
public:
    ConsoleWire();
//    ~ConsoleWire();

private:    
    // create new output channel for given node/channel 
    virtual OutChannel* createOutChannel(int node, int channel);
    // create new input channel for given node/channel
    virtual InChannel* createInChannel(int node, int channel);
//    // create new publish channel for given node/channel
//    virtual PublishChannel* createPublishChannel(int node, int channel);
//    // create new subscribe channel for given node/channel
//    virtual SubscribeChannel* createSubscribeChannel(int node, int channel);
};
}
#endif
