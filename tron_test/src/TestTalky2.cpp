/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/


#include "TestTalky2.h"

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

    tron::JointsData jointsData1;
    tron::JointsData jointsData2;
    
    jointsData1.hs = 22.0;
    jointsData1.vs = 23.0;
    jointsData1.elb = 24.0;
    jointsData1.hwri = 25.0;
    jointsData1.vwri = 26.0;
    
    // send command to arm joints
    sendCommand2ArmJoints(oArmClient, jointsData1);        
    // read arm joints info
    senseDataFromArmJoints(oArmListener, jointsData2);        
        
    LOG4CXX_INFO(logger, modName + ": test end \n");
};

void TestTalky2::sendCommand2ArmJoints(tron::ArmClient& oArmClient, tron::JointsData& jointsData)
{
    LOG4CXX_INFO(logger, modName + ": sendCommand2ArmJoints ...");

    oArmClient.setHS(jointsData.hs);
    oArmClient.setVS(jointsData.vs);
    oArmClient.setELB(jointsData.elb);
    oArmClient.setHWRI(jointsData.hwri);
    oArmClient.setVWRI(jointsData.vwri);
}

void TestTalky2::senseDataFromArmJoints(tron::ArmListener& oArmListener, tron::JointsData& jointsData) 
{
    LOG4CXX_INFO(logger, modName + ": senseDataFromArmJoints ...");

    // interpret test message
    if (oArmListener.getJointPositions(jointsData))
    {
        // show obtained values
        LOG4CXX_INFO(logger, modName + ": sensed HS < " << std::to_string(jointsData.hs));
        LOG4CXX_INFO(logger, modName + ": sensed VS < " << std::to_string(jointsData.vs));
        LOG4CXX_INFO(logger, modName + ": sensed EL < " << std::to_string(jointsData.elb));
        LOG4CXX_INFO(logger, modName + ": sensed HW < " << std::to_string(jointsData.hwri));
        LOG4CXX_INFO(logger, modName + ": sensed VW < " << std::to_string(jointsData.vwri));
    }
    else
    {
        LOG4CXX_WARN(logger, modName + ": arm listener failed!");            
    }
}


