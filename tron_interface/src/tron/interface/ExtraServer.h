#ifndef __TRON_INTERFACE_EXTRASERVER_H
#define __TRON_INTERFACE_EXTRASERVER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <log4cxx/logger.h>

#include "tron/coms/ComsReceiver.h"
#include "tron/coms/ChannelReader.h"
#include "tron/topics/Node.h"

namespace tron
{
// Extra section server for control of robot nodes.
// Uses ComsReceiver (from tron_coms lib) for communications    
class ExtraServer
{            
private:
    static log4cxx::LoggerPtr logger;
    bool btuned;            // server tuned to a node
    tron::ComsReceiver oComsReceiver;  // communications object     
    tron::ChannelReader* pStopChannel;    // channel reader for stop commands
    tron::ChannelReader* pEndChannel;    // channel reader for end commands

public:
    ExtraServer();
    //~ExtraServer();

    bool isTuned() {return btuned;};
    // tune server to given node & section
    bool tune4Node(Node& oNode, int section);

    // get received stop command
    bool getStop(float& value);
    // get received end command 
    bool getEnd(float& value);
};

}
#endif
