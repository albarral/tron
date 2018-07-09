#include "ZeroWire.h"
#include "ZeroClientChannel.h"
#include "ZeroServerChannel.h"
#include "ZeroPublisherChannel.h"
#include "ZeroSubscriberChannel.h"

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   oriolorra@migtron.com   *
 ***************************************************************************/

namespace tron{
    
    ZeroWire::ZeroWire() {
        
    }

    OutputChannel* ZeroWire::createClientChannel(int node, int channel){
        return (new ZeroClientChannel(node, channel));
    }

    InputChannel* ZeroWire::createServerChannel(int node, int channel){
        return (new ZeroServerChannel(node, channel));
    }

    //OutputChannel* ZeroWire::createPublishChannel(int node, int channel){
    //    return (new ZeroPublisherChannel());
    //}

    //InputChannel* ZeroWire::createSubscriberChannel(int node, int channel){
    //    return (new ZeroSubscriberChannel());
    //}
}

