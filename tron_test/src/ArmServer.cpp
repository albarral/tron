/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "ArmServer.h"

using namespace log4cxx;

namespace tron
{
LoggerPtr ArmServer::logger(Logger::getLogger("tron_test"));

ArmServer::ArmServer()
{    
}

//ArmServer::~ArmServer()
//{    
//}

bool ArmServer::checkJointsChannel()
{    
    // hear messages in joints channel
    if (oJointChannelServer.senseChannel())
    {
        // process received messages
        oJointChannelServer.processCommands();
        return true;
    }
    // if no messages could be read
    else
        return false;
}

}