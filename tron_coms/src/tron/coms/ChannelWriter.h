#ifndef __TRON_COMS_CHANNELWRITER_H
#define __TRON_COMS_CHANNELWRITER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include <ignition/transport.hh>

#include "tron/coms/ComsChannel.h"

namespace tron
{
// Channel reader class.
// ignition transport based
class ChannelWriter : public ComsChannel
{    
private:
    ignition::transport::Node::Publisher oPublisher;
        
public:
    ChannelWriter();
    //~ChannelWriter();
    
    // connect channel
    virtual bool connect(ignition::transport::Node& oNode);
    // send message
    bool sendMessage(std::string message);
};

}
#endif
