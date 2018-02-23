#ifndef __TRON_WIRE_CONSOLEOUTCHANNEL_H
#define __TRON_WIRE_CONSOLEOUTCHANNEL_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "tron/wire/OutChannel.h"

namespace tron
{
// Implementation of the OutChannel class for console communications.
class ConsoleOutChannel : public OutChannel
{
private: 
    std::string name;   // channel name 
    
public:
    ConsoleOutChannel();
    ConsoleOutChannel(int node, int channel);

    // open channel
    virtual bool open();
    // close channel
    virtual bool close();
    // send message to destination, returns false if nothing sent
    virtual bool sendMsg(std::string text);
};
}
#endif
