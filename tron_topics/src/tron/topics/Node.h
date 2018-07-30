#ifndef __TRON_TOPICS_NODE_H
#define __TRON_TOPICS_NODE_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "tron/topics/Topic.h"
#include "tron/util/CodeMap.h"

namespace tron
{
// Base class for definition of node topics.
// A Node is composed by sections, which are composed by channels. Each channel will have a specific topic for communication.
 class Node
{        
 protected:
     int ID;     
     CodeMap oSectionsMap;  // node sections
     
 public:     
     Node(int id);
     
     int getID() {return ID;}

    // gets name for given section
    std::string getName4Section(int section);
     
    // build given topic (build topic name from its node/section/channel/type codes)
    virtual bool buildTopic(tron::Topic & oTopic) = 0;

    // return node description
    virtual std::string toString();    
};
}
#endif
