/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/wire/console/ConsoleWire.h"
#include "tron/wire/console/ConsoleOutChannel.h"
#include "tron/wire/console/ConsoleInChannel.h"

using namespace log4cxx;

namespace tron
{
ConsoleWire::ConsoleWire()
{    
}

OutChannel* ConsoleWire::createOutChannel(int node, int channel)
{
    // pointer conversion (type slicing safe)
    return (new ConsoleOutChannel(node, channel));
}

InChannel* ConsoleWire::createInChannel(int node, int channel)
{
    // pointer conversion (type slicing safe)
    return (new ConsoleInChannel(node, channel));
}

}
