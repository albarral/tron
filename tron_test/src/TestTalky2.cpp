/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/


#include "TestTalky2.h"
#include "tron/robot/sensors/ArmSensors.h"

using namespace log4cxx;

LoggerPtr TestTalky2::logger(Logger::getLogger("tron"));

// Constructor 
TestTalky2::TestTalky2()
{    
    modName = "TestTalky2";
 }

void TestTalky2::makeTest()
{
    LOG4CXX_INFO(logger, modName + ": test start \n");

    tron::ArmClient oArmClient;
    tron::ArmListener oArmListener;

    // send command to arm
    sendArmCommand(oArmClient, 22.0);        
    // read arm info
    senseArmInfo(oArmListener);        
        
    LOG4CXX_INFO(logger, modName + ": test end \n");
};

void TestTalky2::sendArmCommand(tron::ArmClient& oArmClient, float hs)
{
    LOG4CXX_INFO(logger, modName + ": sendArmCommand ...");

    if (oArmClient.setHS(hs))
    {
        LOG4CXX_INFO(logger, modName + ": sent HS > " << std::to_string(hs));
    }
    else
    {
        LOG4CXX_ERROR(logger, modName + ": sent HS failed");
    }        
}

void TestTalky2::senseArmInfo(tron::ArmListener& oArmListener) 
{
    LOG4CXX_INFO(logger, modName + ": senseArmInfo ...");

    tron::JointsData jointsData;
    // interpret test message
    if (oArmListener.getJointPositions(jointsData))
    {
        // show obtained hs value
        LOG4CXX_INFO(logger, modName + ": sensed HS < " << std::to_string(jointsData.hs));
    }
    else
    {
        LOG4CXX_WARN(logger, modName + ": arm listener failed!");            
    }
}


