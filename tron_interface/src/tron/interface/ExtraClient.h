#ifndef __TRON_INTERFACE_EXTRACLIENT_H
#define __TRON_INTERFACE_EXTRACLIENT_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <log4cxx/logger.h>

#include "tron/coms/ComsSender.h"
#include "tron/coms/ChannelWriter.h"
#include "tron/topics/Node.h"

namespace tron
{
// Extra section client for control of robot nodes.
// Uses ComsSender (from tron_coms lib)  for communications
class ExtraClient
{            
private:
    static log4cxx::LoggerPtr logger;
    bool btuned;            // client tuned to a node
    tron::ComsSender oComsSender;   // communications object
    tron::ChannelWriter* pStopChannel;    // channel writer for stop requests
    tron::ChannelWriter* pEndChannel;    // channel writer for end requests

public:
    ExtraClient();
    //~ExtraClient();

    bool isTuned() {return btuned;};
    // tune client to given node & section
    bool tune4Node(Node& oNode, int section);

    // ask node to stop (emergency stop)
    bool stopNode();
    // ask node to end (finish process)
    bool endNode();
};

}
#endif
