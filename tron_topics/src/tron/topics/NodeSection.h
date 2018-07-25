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
 private:
     int ID;     
     CodeMap oChannelsMap;
     
 public:     
     NodeSection(int id);
     
     int getID() {return ID;}

    // gets name for given section channel
    std::string getName4Channel(int channel);
     
    // return node section description
    virtual std::string toString();    
};
}
#endif
