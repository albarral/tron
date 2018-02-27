/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/wire2/FileWire.h"
#include "tron/wire2/FileClientChannel.h"
#include "tron/wire2/FileServerChannel.h"
#include "tron/wire2/FilePublishChannel.h"
#include "tron/wire2/FileSubscribeChannel.h"

namespace tron
{
FileWire::FileWire()
{    
}

OutputChannel* FileWire::createClientChannel(int node, int channel)
{
    // pointer conversion (type slicing safe)
    return (new FileClientChannel(node, channel));
}

InputChannel* FileWire::createServerChannel(int node, int channel)
{
    // pointer conversion (type slicing safe)
    return (new FileServerChannel(node, channel));
}

OutputChannel* FileWire::createPublishChannel(int node, int channel)
{
    // pointer conversion (type slicing safe)
    return (new FilePublishChannel(node, channel));
}

InputChannel* FileWire::createSubscribeChannel(int node, int channel)
{
    // pointer conversion (type slicing safe)
    return (new FileSubscribeChannel(node, channel));
}

}
