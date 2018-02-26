#ifndef __TRON_WIRE_CONSOLE_PUBLISHCHANNEL_H
#define __TRON_WIRE_CONSOLE_PUBLISHCHANNEL_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "tron/wire/channel/PublishChannel.h"

namespace tron
{
// Implementation of the PublishChannel class for console communications.
class ConsolePublishChannel : public PublishChannel
{
private: 
    std::string name;   // channel name 
    
public:
    ConsolePublishChannel();
    ConsolePublishChannel(int node, int channel);

    // open channel
    virtual bool open();
    // close channel
    virtual bool close();
    // send message to destination, returns false if nothing sent
    virtual bool sendMsg(std::string text);
};
}
#endif
