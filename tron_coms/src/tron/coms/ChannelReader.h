#ifndef __TRON_COMS_CHANNELREADER_H
#define __TRON_COMS_CHANNELREADER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <vector>

#include <ignition/msgs.hh>
#include <ignition/transport.hh>

#include "tron/coms/ComsChannel.h"

namespace tron
{
// Channel reader class.
// ignition transport based
class ChannelReader : public ComsChannel
{    
private:
    std::vector<std::string> listMessages;      // queue of received messages
        
public:
    ChannelReader();
    ~ChannelReader();
    
    // connect channel
    virtual bool connect(ignition::transport::Node& oNode);
    // read received messages (and clear queue)
    int getMessages(std::vector<std::string>& listMessages);
    
private:
    void processMessage(const ignition::msgs::StringMsg& imessage);
};

}
#endif
