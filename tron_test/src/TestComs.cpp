/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <unistd.h>

#include "TestComs.h"
#include "tron/coms/ComsReceiver.h"
#include "tron/coms/ComsSender.h"
#include "tron/topics/RobotNodes.h"
#include "tron/topics/Topic.h"


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
    
    oTopic.set(1, 2, 3, tron::Topic::eTYPE_CONTROL);
    oTopic.setNodeName("arm");
    oTopic.setSectionName("joints");
    oTopic.setChannelName("hs");
    oTopic.build();
    // test communication (reader and writer)
    if (oTopic.isBuilt())
    {
        oComsReceiver.addChannel(oTopic.getTopicName());
        oComsSender.addChannel(oTopic.getTopicName());    

        std::string message = "hola";
        oComsSender.getChannel(0)->sendMessage(message);
    }
    
    usleep(1000000);                  
        
    std::vector<std::string> listMessages;
    //oComsReceiver.getChannel(0)->getMessages(listMessages);
    listMessages = oComsReceiver.getChannel(0)->getMessages2();
    
    if (!listMessages.empty())
    {
        LOG4CXX_INFO(logger, "testComs: received message = " + listMessages.at(0));            
    }
    
    LOG4CXX_INFO(logger, modName + ": test end \n");
};

int TestComs::checkSize(std::string message)
{
    return message.size();
}


