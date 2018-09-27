#ifndef __TRON_INTERFACE_SECTION_COMMUNICATOR_H
#define __TRON_INTERFACE_SECTION_COMMUNICATOR_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>

#include "tron/topics/Node.h"

namespace tron
{
// Base class for communication classes (clients, servers, informers and listeners) oriented to node sections.
class SectionCommunicator
{            
protected:
    static log4cxx::LoggerPtr logger;
    int node;       // target node
    int section;    // target section
    int topicType;  // topic type (control or sensor))
    bool btuned;   // true when communicator has channels connected

public:
    SectionCommunicator(int topicType);
    //~SectionCommunicator();

    int getNode() {return node;};
    int getSection() {return section;};
    bool isTuned() {return btuned;};
    
protected:    
    // tune communicator to given node & section
    bool tune4Node(Node& oNode, int section);
    // add channel for specified topic
    virtual void addChannel(std::string topic) = 0;
    // get all channels connected
    virtual void connect() = 0;
};

}
#endif
