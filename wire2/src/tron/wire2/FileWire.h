#ifndef __TRON_WIRE2_FILEWIRE_H
#define __TRON_WIRE2_FILEWIRE_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/


#include "tron/wire/Wire.h"
#include "tron/wire/channel/InputChannel.h"
#include "tron/wire/channel/OutputChannel.h"

namespace tron
{
// Implementation of the Wire class for multichannel communications using files.
class FileWire : public Wire
{            
public:
    FileWire();
//    ~FileWire();

private:    
    // create new unicast output channel for given node/channel 
    virtual OutputChannel* createClientChannel(int node, int channel);
    // create new unicast input channel for given node/channel
    virtual InputChannel* createServerChannel(int node, int channel);
    // create new publish channel for given node/channel
    virtual OutputChannel* createPublishChannel(int node, int channel);
//    // create new subscribe channel for given node/channel
    virtual InputChannel* createSubscribeChannel(int node, int channel);
};
}
#endif
