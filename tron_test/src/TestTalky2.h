#ifndef __TRON_TESTTALKY2_H
#define __TRON_TESTTALKY2_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>

#include "tron/talky2/arm/ArmClient.h"
#include "tron/talky2/arm/ArmListener.h"
#include "tron/robot/sensors/ArmSensors.h"

// Class used to test coms with libtron_talky2.
class TestTalky2
{
private:
    static log4cxx::LoggerPtr logger;
    std::string modName;          // module name
   

public:
    TestTalky2();
    //~TestTalky2();

    void makeTest();      
    
private:
    // send commands ...
    void sendCommand2ArmJoints(tron::ArmClient& oArmClient, tron::JointsData& jointsData);
//    void sendCommand2ArmAxes(tron::ArmClient& oArmClient, tron::AxesData& axesData);
    
    // sense data ..
    void senseDataFromArmJoints(tron::ArmListener& oArmListener, tron::JointsData& jointsData);                
//    void senseDataFromArmAxes(tron::ArmListener& oArmListener, tron::AxesData& axesData);                
};
#endif
