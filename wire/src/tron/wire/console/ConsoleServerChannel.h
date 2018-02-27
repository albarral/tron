#ifndef __TRON_WIRE_CONSOLE_SERVERCHANNEL_H
#define __TRON_WIRE_CONSOLE_SERVERCHANNEL_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "tron/wire/channel/ServerChannel.h"

namespace tron
{
// Implementation of the ServerChannel class for console communications.
class ConsoleServerChannel : public ServerChannel
{
public:
    ConsoleServerChannel() {};
    ConsoleServerChannel(int node, int channel) : ServerChannel(node, channel) {};

    // open channel
    virtual bool open();
    // close channel
    virtual bool close();
    // receive messages from origin, returns false if nothing received
    virtual bool receiveMessages(std::vector<std::string>& listMessages);
};
}
#endif
