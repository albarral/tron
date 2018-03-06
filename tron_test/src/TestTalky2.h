#ifndef __TRON_TESTTALKY2_H
#define __TRON_TESTTALKY2_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <log4cxx/logger.h>

#include "tron/talky2/arm/ArmClient.h"
#include "tron/talky2/arm/ArmListener.h"
#include "tron/robot/sensors/ArmSensors.h"
#include "tron/talky2/channel/ChannelServer.h"

namespace tron
{
// Class used to test coms with libtron_talky2.
class TestTalky2
{
private:
    static log4cxx::LoggerPtr logger;

public:
    TestTalky2();
    //~TestTalky2();

    void makeTest();      
    
private:
    void testUnicastComs();      
    void testBroadcastComs();      

    // send commands ...
    void sendArmJointCommands(ArmClient& oArmClient, float value);
//    void sendCommand2ArmAxes(tron::ArmClient& oArmClient, tron::AxesData& axesData);
    
    // sense data ..
    void hearArmJointsData(ArmListener& oArmListener, JointsData& jointsData);                

        
    void checkServerChannel(ChannelServer& oChannelServer);
};

}
#endif
