/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <unistd.h>

#include "TestNety.h"
#include "nety/NetNodeClient.h"
#include "nety/NetNodePublisher.h"
#include "talky/Topics.h"
#include "talky/coms/Command.h"
#include "talky/topics/ArmTopic.h"


using namespace log4cxx;

LoggerPtr TestNety::logger(Logger::getLogger("tron"));

// Constructor 
TestNety::TestNety()
{    
    modName = "TestNety";
 }

void TestNety::makeTest()
{
    LOG4CXX_INFO(logger, modName + ": test start \n");

    //testCSComs();
    testPSComs();       
        
    LOG4CXX_INFO(logger, modName + ": test end \n");
};

void TestNety::testCSComs()
{
    LOG4CXX_INFO(logger, modName + ": testCSComs ...");
    
    nety::NetNodeClient oNetyClient;
    nety::NetNodeServer oNetyServer;
    
    int topic = talky::Topics::eTOPIC_ARM;
    int category = talky::ArmTopic::eCAT_ARM_JOINT;
    // connection nodes
    oNetyClient.init(topic, category);
    oNetyServer.init(topic, category);
    
    if (!oNetyClient.isConnected() || !oNetyServer.isConnected())
    {
        LOG4CXX_ERROR(logger, modName + ": client or server not connected. Exit test!");                        
        return;
    }
        
    // push commands
    oNetyClient.addCommand(talky::ArmTopic::eJOINT_HS_POS, 10);
    oNetyClient.addCommand(talky::ArmTopic::eJOINT_VS_POS, 20);
    oNetyClient.addCommand(talky::ArmTopic::eJOINT_ELB_POS, 30);
    oNetyClient.process();    

    LOG4CXX_INFO(logger, modName + ": send messages " << oNetyClient.getSizeMessagesQueue());                
    // and send them
   oNetyClient.flush();

    // receive message
    readByServer(oNetyServer);
}

void TestNety::testPSComs()
{
    LOG4CXX_INFO(logger, modName + ": testPSComs ...");
       
    nety::NetNodePublisher oNetyPublisher;
    nety::NetNodeSubscriber oNetySubscriber;
    
    // connection
    int topic = talky::Topics::eTOPIC_ARM;
    int category = talky::ArmTopic::eCAT_ARM_JOINT;
    // connection nodes
    oNetyPublisher.init(topic, category);
    oNetySubscriber.init(topic, category);
    
    if (!oNetyPublisher.isConnected() || !oNetySubscriber.isConnected())
    {
        LOG4CXX_ERROR(logger, modName + ": publisher or subscriber not connected. Exit test!");                        
        return;
    }
    
    // push commands
    oNetyPublisher.addCommand(talky::ArmTopic::eJOINT_HS_POS, 10);
    oNetyPublisher.addCommand(talky::ArmTopic::eJOINT_VS_POS, 20);
    oNetyPublisher.addCommand(talky::ArmTopic::eJOINT_ELB_POS, 30);
    oNetyPublisher.process();    

    LOG4CXX_INFO(logger, modName + ": send messages " << oNetyPublisher.getSizeMessagesQueue());                
    // and send them
   oNetyPublisher.flush();

    readBySubscriber(oNetySubscriber);   
}

void TestNety::readByServer(nety::NetNodeServer& oNetyServer)
{
    oNetyServer.absorb();
    LOG4CXX_INFO(logger, "server has messages " << oNetyServer.getSizeMessagesQueue());                
    oNetyServer.process();
    talky::Command oCommand;
    while (oNetyServer.hasCommands())
    {
        oNetyServer.fetchCommand(oCommand);
        LOG4CXX_INFO(logger, modName + ": " + oCommand.toString());                
    }
}

void TestNety::readBySubscriber(nety::NetNodeSubscriber& oNetySubscriber)
{
    oNetySubscriber.absorb();
    LOG4CXX_INFO(logger, "subscriber has messages " << oNetySubscriber.getSizeMessagesQueue());                
    oNetySubscriber.process();
    talky::Command oCommand;
    while (oNetySubscriber.hasCommands())
    {
        oNetySubscriber.fetchCommand(oCommand);
        LOG4CXX_INFO(logger, modName + ": " + oCommand.toString());                
    }
}