/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/wire/console/ConsoleWire.h"
#include "tron/wire/console/ConsoleUnicastOutChannel.h"
#include "tron/wire/console/ConsoleUnicastInChannel.h"
#include "tron/wire/console/ConsolePublishChannel.h"
#include "tron/wire/console/ConsoleSubscribeChannel.h"

using namespace log4cxx;

namespace tron
{
ConsoleWire::ConsoleWire()
{    
}

OutputChannel* ConsoleWire::createUnicastOutputChannel(int node, int channel)
{
    // pointer conversion (type slicing safe)
    return (new ConsoleUnicastOutChannel(node, channel));
}

InputChannel* ConsoleWire::createUnicastInputChannel(int node, int channel)
{
    // pointer conversion (type slicing safe)
    return (new ConsoleUnicastInChannel(node, channel));
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
