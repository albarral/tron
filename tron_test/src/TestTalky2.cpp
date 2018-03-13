/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/


#include "TestTalky2.h"
#include "test/talky2/JointChannelServer.h"
#include "tron/robot/RobotNodes.h"
#include "tron/robot/sensors/ArmSensors.h"
#include "tron/robot/topics/ArmTopics.h"
#include "tron/talky2/arm/ArmClient.h"
#include "tron/talky2/arm/JointTalker.h"
#include "tron/talky2/body/BodyClient.h"
#include "tron/talky2/channel/ChannelPublisher.h"

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

    testUnicastComs();
    
    //testBroadcastComs();
        
    LOG4CXX_INFO(logger, "TestTalky2: test end \n");
}


void TestTalky2::testUnicastComs()
{
    LOG4CXX_INFO(logger, "TestTalky2::testUnicastComs \n");

    /*
    ArmClient oArmClient;
    JointChannelServer oJointChannelServer;

    float value = 10.0;
    oArmClient.setHS(value++);
    oArmClient.setVS(value++);
    oArmClient.setELB(value++);
    oArmClient.setHWRI(value++);
    oArmClient.setVWRI(value++);

    // serve joint commands
    checkServerChannel(oJointChannelServer);
     */
    
    BodyClient oBodyClient;
    oBodyClient.expressFeeling(10);
    oBodyClient.endNode();
}


void TestTalky2::testBroadcastComs()
{
    LOG4CXX_INFO(logger, "TestTalky2::testBroadcastComs \n");

    ChannelPublisher oChannelPublisher(RobotNodes::eNODE_ARM, ArmTopics::eARM_JOINT);

    float value = 80.0;

    oChannelPublisher.clearChannel();
    oChannelPublisher.addMessage(JointTalker::eJOINT_HS_POS, value++);
    oChannelPublisher.addMessage(JointTalker::eJOINT_VS_POS, value++);
    oChannelPublisher.addMessage(JointTalker::eJOINT_ELB_POS, value++);
    oChannelPublisher.addMessage(JointTalker::eJOINT_HWRI_POS, value++);
    oChannelPublisher.addMessage(JointTalker::eJOINT_VWRI_POS, value++);    
    oChannelPublisher.publishAll();
    
    ArmListener oArmListener;
            
    // read arm joints info
    hearArmJointsData(oArmListener);        
        
    LOG4CXX_INFO(logger, "TestTalky2: test end \n");
}

void TestTalky2::hearArmJointsData(ArmListener& oArmListener) 
{
    LOG4CXX_INFO(logger, "TestTalky2: hearArmJointsData ...");
    JointsData jointsData;

    // interpret test message
    if (oArmListener.senseChannels())
    {
        jointsData = oArmListener.getJointPositions();
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

}
