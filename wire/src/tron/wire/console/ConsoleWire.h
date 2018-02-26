#ifndef __TRON_WIRE_CONSOLEWIRE_H
#define __TRON_WIRE_CONSOLEWIRE_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/


#include "tron/wire/Wire.h"
#include "tron/wire/channel/InputChannel.h"
#include "tron/wire/channel/OutputChannel.h"

namespace tron
{
// Implementation of the Wire class for multichannel communications through the console..
class ConsoleWire : public Wire
{            
public:
    ConsoleWire();
//    ~ConsoleWire();

private:    
    // create new unicast output channel for given node/channel 
    virtual OutputChannel* createUnicastOutputChannel(int node, int channel);
    // create new unicast input channel for given node/channel
    virtual InputChannel* createUnicastInputChannel(int node, int channel);
    // create new publish channel for given node/channel
    virtual OutputChannel* createPublishChannel(int node, int channel);
//    // create new subscribe channel for given node/channel
    virtual InputChannel* createSubscribeChannel(int node, int channel);
};
}
#endif
