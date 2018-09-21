#ifndef __TRON_INTERFACE_EXTRASERVER_H
#define __TRON_INTERFACE_EXTRASERVER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <log4cxx/logger.h>

#include "tron/interface/SectionServer.h"
#include "tron/coms/ChannelReader.h"
#include "tron/topics/Node.h"

namespace tron
{
// Extra section server for control of robot nodes.
class ExtraServer : public SectionServer
{            
private:
    static log4cxx::LoggerPtr logger2;
    tron::ChannelReader* pStopChannel;    // channel reader for stop commands
    tron::ChannelReader* pEndChannel;    // channel reader for end commands

public:
    ExtraServer();
    //~ExtraServer();

    // init communicator for given node & section
    bool init(Node& oNode, int section);

    // get received stop command
    bool getStop();
    // get received end command 
    bool getEnd();
};

}
#endif
