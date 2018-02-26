/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/wire/console/ConsoleWire.h"
#include "tron/wire/console/ConsoleClientChannel.h"
#include "tron/wire/console/ConsoleServerChannel.h"
#include "tron/wire/console/ConsolePublishChannel.h"
#include "tron/wire/console/ConsoleSubscribeChannel.h"

using namespace log4cxx;

namespace tron
{
ConsoleWire::ConsoleWire()
{    
}

OutputChannel* ConsoleWire::createClientChannel(int node, int channel)
{
    // pointer conversion (type slicing safe)
    return (new ConsoleClientChannel(node, channel));
}

InputChannel* ConsoleWire::createServerChannel(int node, int channel)
{
    // pointer conversion (type slicing safe)
    return (new ConsoleServerChannel(node, channel));
}

OutputChannel* ConsoleWire::createPublishChannel(int node, int channel)
{
    // pointer conversion (type slicing safe)
    return (new ConsolePublishChannel(node, channel));
}

InputChannel* ConsoleWire::createSubscribeChannel(int node, int channel)
{
    // pointer conversion (type slicing safe)
    return (new ConsoleSubscribeChannel(node, channel));
}

}
