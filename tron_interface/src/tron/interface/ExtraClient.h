#ifndef __TRON_INTERFACE_EXTRACLIENT_H
#define __TRON_INTERFACE_EXTRACLIENT_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <log4cxx/logger.h>

#include "tron/interface/SectionClient.h"
#include "tron/coms/ChannelWriter.h"
#include "tron/topics/Node.h"

namespace tron
{
// Extra section client for control of robot nodes.
class ExtraClient  : public tron::SectionClient
{            
private:
    static log4cxx::LoggerPtr logger2;
    tron::ChannelWriter* pStopChannel;    // channel writer for stop requests
    tron::ChannelWriter* pEndChannel;    // channel writer for end requests

public:
    ExtraClient();
    //~ExtraClient();

    // init communicator for given node & section
    bool init(Node& oNode, int section);

    // ask node to stop (emergency stop)
    bool stopNode();
    // ask node to end (finish process)
    bool endNode();
};

}
#endif
