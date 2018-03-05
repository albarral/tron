#ifndef __TALKY2_CHANNELCOMMUNICATOR_H
#define __TALKY2_CHANNELCOMMUNICATOR_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>

#include "tron/talky2/Talker.h"
#include "tron/wire2/FileWire.h"

namespace tron
{
// Base class for channel communication classes (client, server, broadcaster & listener)
class ChannelCommunicator 
{    
protected:
    static log4cxx::LoggerPtr logger;
    int node;
    int topic;
    Talker* pTalker;
    bool btuned;
    std::string identity;    
    FileWire oWire;                                     // communications wire   
        
public:
    ChannelCommunicator(int node, int topic);
    ~ChannelCommunicator();
    
protected:    
    virtual void setIdentity() = 0;
    
private:
    // create talker for this channel node & topic
    bool createTalker();        
    // create talker for specific arm topic
    Talker* createTalker4ArmTopic();
};

}
#endif
