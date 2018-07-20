#ifndef __TRON_COMS_CHANNELREADER_H
#define __TRON_COMS_CHANNELREADER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <ignition/transport.hh>

#include "ComsChannel.h"

namespace tron
{
// Channel reader class.
// ignition transport based
class ChannelReader : public ComsChannel
{    
private:
    int type;                       // channel type (one of eTypes)
    std::string nodeName;       
    std::string sectionName;    
    std::string channelName;   
    std::string topic;              // topic name
    bool bconnected;            // channel is connected (has a registered publisher or subscriber) 
        
public:
    ChannelReader();
    //~ChannelReader();
    
    // set channel elements
    void setChannel(std::string node, std::string section, std::string channel, int type);
    // connect channel
    virtual bool connect() = 0;
    bool isConnected() {return bconnected;};
    
    int getType() {return type;};
    std::string getNodeName() {return nodeName;};
    std::string getSectionName() {return sectionName;};
    std::string getChannelName() {return channelName;};
    std::string getTopic() {return topic;};
    
    static std::string getTypeName(int type);
};

}
#endif
