#ifndef __TRON_WIRE_CONSOLE_UNICASTINCHANNEL_H
#define __TRON_WIRE_CONSOLE_UNICASTINCHANNEL_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "tron/wire/channel/UnicastInChannel.h"

namespace tron
{
// Implementation of the UnicastInChannel class for console communications.
class ConsoleUnicastInChannel : public UnicastInChannel
{
private: 
    std::string name;   // channel name 
    
public:
    ConsoleUnicastInChannel();
    ConsoleUnicastInChannel(int node, int channel);

    // open channel
    virtual bool open();
    // close channel
    virtual bool close();
    // receive messages from origin, returns false if nothing received
    virtual bool receiveMessages(std::vector<std::string>& listMessages);
};
}
#endif
