/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/


#include "TestTalky2.h"
#include "test/talky2/JointChannelServer.h"
#include "tron/talky2/arm/JointTalker.h"
#include "tron/robot/RobotNodes.h"
#include "tron/robot/topics/ArmTopics.h"

using namespace log4cxx;

namespace tron
{
LoggerPtr TestTalky2::logger(Logger::getLogger("tron"));

// Constructor 
TestTalky2::TestTalky2()
{    
 }

void TestTalky2::makeTest()
{
    LOG4CXX_INFO(logger, "TestTalky2: test start \n");

    //testUnicastComs();
    
    testBroadcastComs();
        
    LOG4CXX_INFO(logger, "TestTalky2: test end \n");
}


void TestTalky2::testUnicastComs()
{
    LOG4CXX_INFO(logger, "TestTalky2::testUnicastComs \n");

    ArmClient oArmClient1;
    ArmClient oArmClient2;
    JointChannelServer oJointChannelServer;

    float val1 = 10.0;
    float val2 = 20.0;

    for (int i=0; i<3; i++)
    {
        // send joint commands 
        sendArmJointCommands(oArmClient1, val1);        
        sendArmJointCommands(oArmClient2, val2);        

        // serve joint commands
        checkServerChannel(oJointChannelServer);
        
        val1 += 100;
        val2 += 100;
    }
}


void TestTalky2::testBroadcastComs()
{
    LOG4CXX_INFO(logger, "TestTalky2::testBroadcastComs \n");

    ChannelPublisher oJointChannelPublisher(RobotNodes::eNODE_ARM, ArmTopics::eARM_JOINT);

    publishData2Channel(oJointChannelPublisher, 80.0);
    oJointChannelPublisher.clearChannel();
    publishData2Channel(oJointChannelPublisher, 90.0);
    
    ArmListener oArmListener;
    JointsData jointsData;
            
    // read arm joints info
    hearArmJointsData(oArmListener, jointsData);        
        
    LOG4CXX_INFO(logger, "TestTalky2: test end \n");
}

void TestTalky2::sendArmJointCommands(ArmClient& oArmClient, float value)
{
    LOG4CXX_INFO(logger, "TestTalky2: sendArmJointCommands ...");

    oArmClient.setHS(value++);
    oArmClient.setVS(value++);
    oArmClient.setELB(value++);
    oArmClient.setHWRI(value++);
    oArmClient.setVWRI(value++);
}


void TestTalky2::hearArmJointsData(ArmListener& oArmListener, JointsData& jointsData) 
{
    LOG4CXX_INFO(logger, "TestTalky2: hearArmJointsData ...");

    // interpret test message
    if (oArmListener.getJointPositions(jointsData))
    {
        // show obtained values
        LOG4CXX_INFO(logger, "TestTalky2: sensed HS < " << std::to_string(jointsData.hs));
        LOG4CXX_INFO(logger, "TestTalky2: sensed VS < " << std::to_string(jointsData.vs));
        LOG4CXX_INFO(logger, "TestTalky2: sensed EL < " << std::to_string(jointsData.elb));
        LOG4CXX_INFO(logger, "TestTalky2: sensed HW < " << std::to_string(jointsData.hwri));
        LOG4CXX_INFO(logger, "TestTalky2: sensed VW < " << std::to_string(jointsData.vwri));
    }
    else
    {
        LOG4CXX_WARN(logger, "TestTalky2: arm listener failed!");            
    }
}

void TestTalky2::checkServerChannel(ChannelServer& oChannelServer)
{    
    LOG4CXX_INFO(logger, "TestTalky2::checkServerChannel ...");

    // get messages in channel
    if (oChannelServer.senseChannel())
    {
        // and process them
        oChannelServer.processCommands();
    }
    // warn if no messages read
    else
    {
        LOG4CXX_WARN(logger, "TestTalky2: no messages in channel ...");
    }
}


void TestTalky2::publishData2Channel(ChannelPublisher& oChannelPublisher, float value)
{
    oChannelPublisher.publishMessage(JointTalker::eJOINT_HS_POS, value++);
    oChannelPublisher.publishMessage(JointTalker::eJOINT_VS_POS, value++);
    oChannelPublisher.publishMessage(JointTalker::eJOINT_ELB_POS, value++);
    oChannelPublisher.publishMessage(JointTalker::eJOINT_HWRI_POS, value++);
    oChannelPublisher.publishMessage(JointTalker::eJOINT_VWRI_POS, value++);    
}

}
