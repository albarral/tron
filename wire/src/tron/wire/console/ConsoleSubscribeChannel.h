#ifndef __TRON_WIRE_CONSOLE_SUBSCRIBECHANNEL_H
#define __TRON_WIRE_CONSOLE_SUBSCRIBECHANNEL_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/wire/channel/SubscribeChannel.h"

namespace tron
{
// Implementation of the SubscribeChannel class for console communications.
class ConsoleSubscribeChannel : public SubscribeChannel
{
public:
    ConsoleSubscribeChannel() {};
    ConsoleSubscribeChannel(int node, int channel) : SubscribeChannel(node, channel) {};

    // open channel
    virtual bool open();
    // close channel
    virtual bool close();
    // receive messages from origin, returns false if nothing received
    virtual bool receiveMessages(std::vector<std::string>& listMessages);
};
}
#endif
