#ifndef __TRON_TEST_ARMSERVER_H
#define __TRON_TEST_ARMSERVER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <log4cxx/logger.h>

#include "JointChannelServer.h"

namespace tron
{
// Arm server class
class ArmServer
{    
private:
    static log4cxx::LoggerPtr logger;
    JointChannelServer oJointChannelServer;
        
public:
    ArmServer();
    //~ArmServer();

    bool checkJointsChannel();
};

}
#endif
