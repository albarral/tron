#ifndef __TRON_DADY_ROBOTCHANNELS_H
#define __TRON_DADY_ROBOTCHANNELS_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>

#include "tron/topics/Node.h"
#include "tron/topics/NodeSection.h"

namespace tron
{
// Class for obtaining sections and channels of robot nodes.
 class RobotChannels
{         
 private:
    static log4cxx::LoggerPtr logger;    
     
 public:     
     // get section code for given node code and section name
    static int getCode4NodeSection(int node, std::string sectionName);
    
     // get channel code for given node-section codes and channel name
    static int getCode4NodeSectionChannel(int node, int section, std::string channelName);     
    
    // list sections available for specified node
    static std::string showAvailableSections4Node(int node);
    
    // list channels available for specified node-section
    static std::string showAvailableChannels4NodeSection(int node, int section);    

    // get topic name (of control type) for specified node-section-channel
    static std::string getTopic4NodeSectionChannel(int node, int section, int channel);     

    // get pointer to specified node
    static Node* getNode(int node);
};
}
#endif
