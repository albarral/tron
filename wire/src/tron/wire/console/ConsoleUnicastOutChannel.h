#ifndef __TRON_WIRE_CONSOLE_UNICASTOUTCHANNEL_H
#define __TRON_WIRE_CONSOLE_UNICASTOUTCHANNEL_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "tron/wire/channel/UnicastOutChannel.h"

namespace tron
{
// Implementation of the UnicastOutChannel class for console communications.
class ConsoleUnicastOutChannel : public UnicastOutChannel
{
private: 
    std::string name;   // channel name 
    
public:
    ConsoleUnicastOutChannel();
    ConsoleUnicastOutChannel(int node, int channel);

    // open channel
    virtual bool open();
    // close channel
    virtual bool close();
    // send message to destination, returns false if nothing sent
    virtual bool sendMsg(std::string text);
};
}
#endif
