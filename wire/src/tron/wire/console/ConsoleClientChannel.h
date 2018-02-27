#ifndef __TRON_WIRE_CONSOLE_CLIENTCHANNEL_H
#define __TRON_WIRE_CONSOLE_CLIENTCHANNEL_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "tron/wire/channel/ClientChannel.h"

namespace tron
{
// Implementation of the ClientChannel class for console communications.
class ConsoleClientChannel : public ClientChannel
{
public:
    ConsoleClientChannel() {};
    ConsoleClientChannel(int node, int channel) : ClientChannel(node, channel) {};

    // open channel
    virtual bool open();
    // close channel
    virtual bool close();
    // send message to destination, returns false if nothing sent
    virtual bool sendMsg(std::string text);
};
}
#endif
