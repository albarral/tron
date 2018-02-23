#ifndef __TRON_WIRE_CONSOLEINCHANNEL_H
#define __TRON_WIRE_CONSOLEINCHANNEL_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "tron/wire/InChannel.h"

namespace tron
{
// Implementation of the InChannel class for console communications.
class ConsoleInChannel : public InChannel
{
private: 
    std::string name;   // channel name 
    
public:
    ConsoleInChannel();
    ConsoleInChannel(int node, int channel);

    // open channel
    virtual bool open();
    // close channel
    virtual bool close();
    // receive messages from origin, returns false if nothing received
    virtual bool receiveMessages(std::vector<std::string>& listMessages);
};
}
#endif
