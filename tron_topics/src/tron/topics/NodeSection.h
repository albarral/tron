#ifndef __TRON_TOPICS_NODESECTION_H
#define __TRON_TOPICS_NODESECTION_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "tron/topics/Topic.h"
#include "tron/util/CodeMap.h"

namespace tron
{
// Class for definition of topics for a node section.
// A NodeSection is composed by channels. Each channel will have a specific topic for communication.
 class NodeSection
{          
 protected:
     int ID;     
     CodeMap oChannelsMap;  // section channels
     
 public:     
     NodeSection(int id);
     
     int getID() {return ID;}
     int getNumChannels() {return oChannelsMap.getSize();};

    // gets name for given section channel
    std::string getName4Channel(int channel);
    // gets code for given channel name (returns -1 if unknown)
    int getChannel4Name(std::string name);
     
    void addChannel(int code, std::string name);
    
    // return node section description
    std::string toString();    
};
}
#endif
