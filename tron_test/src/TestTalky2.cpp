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

    tron::ArmClient oArmClient1;
    tron::ArmClient oArmClient2;
    tron::ArmListener oArmListener;
    tron::ArmServer oArmServer;

    tron::JointsData jointsData2;

    float val1 = 10.0;
    float val2 = 20.0;

    for (int i=0; i<3; i++)
    {
        // send joint commands 
        sendArmJointCommands(oArmClient1, val1);        
        sendArmJointCommands(oArmClient2, val2);        

        // serve joint commands
        serveArmJointCommands(oArmServer);
        
        val1 += 100;
        val2 += 100;
    }
            
    // read arm joints info
    //hearArmJointsData(oArmListener, jointsData2);        
        
    LOG4CXX_INFO(logger, modName + ": test end \n");
};

void TestTalky2::sendArmJointCommands(tron::ArmClient& oArmClient, float value)
{
    LOG4CXX_INFO(logger, modName + ": sendArmJointCommands ...");

    oArmClient.setHS(value++);
    oArmClient.setVS(value++);
    oArmClient.setELB(value++);
    oArmClient.setHWRI(value++);
    oArmClient.setVWRI(value++);
}

void TestTalky2::serveArmJointCommands(tron::ArmServer& oArmServer)
{
    LOG4CXX_INFO(logger, modName + ": serveArmJointCommands ...");

    if (oArmServer.checkJointsChannel())
    {
        // show obtained values
        LOG4CXX_INFO(logger, modName + ": commands processed");
    }
    else
    {
        LOG4CXX_WARN(logger, modName + ": arm server didn't receive commands");            
    }    
}


void TestTalky2::hearArmJointsData(tron::ArmListener& oArmListener, tron::JointsData& jointsData) 
{
    LOG4CXX_INFO(logger, modName + ": hearArmJointsData ...");

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


