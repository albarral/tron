/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <unistd.h>

#include "TestComs.h"
#include "tron/coms/ComsReceiver.h"
#include "tron/coms/ComsSender.h"
#include "tron/coms/ChannelReader.h"
#include "tron/topics/RobotNodes.h"
#include "tron/topics/Topic.h"
#include "TestNode.h"

using namespace log4cxx;

LoggerPtr TestComs::logger(Logger::getLogger("tron.coms"));

// Constructor 
TestComs::TestComs()
{    
    modName = "TestComs";
 }

void TestComs::makeTest()
{
    LOG4CXX_INFO(logger, modName + ": test start \n");
    
    tron::ComsReceiver oComsReceiver;
    tron::ComsSender oComsSender;
    
    // define coms topic
    tron::Topic oTopic;
    TestNode oTestNode;
    
    oTopic.set(tron::RobotNodes::eNODE_ARM, TestNode::eSECTION_JOINTS, TestNode::eJOINTS_VS, tron::Topic::eTYPE_CONTROL);
    oTopic.build4Node(oTestNode);
    
    // set communication reader and writer
    if (oTopic.isBuilt())
    {
        oComsReceiver.addChannel(oTopic.getTopicName());
        oComsSender.addChannel(oTopic.getTopicName());  

        oComsReceiver.connect();
    }
    else
        return;

    oComsSender.getChannel(0)->sendMessage("hola");
    
    usleep(1000000);                  
        
    tron::ChannelReader* pChannelReader = oComsReceiver.getChannel(0);
        
    if (pChannelReader->hasNew())
    {
        LOG4CXX_INFO(logger, "testComs: received message = " + pChannelReader->getMessage());            
    }
    
    LOG4CXX_INFO(logger, modName + ": test end \n");
};

int TestComs::checkSize(std::string message)
{
    return message.size();
}


