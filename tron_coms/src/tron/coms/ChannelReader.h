#ifndef __TRON_COMS_CHANNELREADER_H
#define __TRON_COMS_CHANNELREADER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

//#include <mutex>
#include <string>

#include <ignition/msgs.hh>
#include <ignition/transport.hh>

#include "tron/coms/ComsChannel.h"

namespace tron
{
// Channel reader class (thread safe).
// ignition transport based
class ChannelReader : public ComsChannel
{    
private:
    //std::mutex mutex;    
    std::string message;      // last received message
    bool bnew;                     // new message flag (raised on message arrival, lowered on message reading)
        
public:
    ChannelReader();
    ~ChannelReader();
    
    // connect channel
    virtual bool connect(ignition::transport::Node& oNode);    
    // check new message flag
    bool hasNew() {return bnew;};    
    // clear new message flag
    void clear() {bnew = false;};
    // read received message (clears new message flag)
    std::string getMessage();    
    
private:
    // callback for ignition subscriber  (thread safe - TO DO)
    void processMessage(const ignition::msgs::StringMsg& imessage);
};

}
#endif
