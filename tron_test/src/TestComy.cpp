/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <unistd.h>

#include "TestComy.h"
#include "comy/file/ComyFileClient.h"
#include "comy/file/ComyFilePublisher.h"

using namespace log4cxx;

LoggerPtr TestComy::logger(Logger::getLogger("tron"));

// Constructor 
TestComy::TestComy()
{    
    modName = "TestComy";
 }

void TestComy::makeTest()
{
    LOG4CXX_INFO(logger, modName + ": test start \n");

    //testClientServerComs();
    testPublishSubscribeComs();       
        
    LOG4CXX_INFO(logger, modName + ": test end \n");
};

void TestComy::testClientServerComs()
{
    LOG4CXX_INFO(logger, modName + ": testClientServerComs ...");
    
    comy::ComyFileClient oComyClient;
    comy::ComyFileServer oComyServer;
    
    // connection
    // multichannel communication
    std::string topic = "topic";
    std::string category = "cat";
    oComyClient.connect(topic, category);
    oComyServer.connect(topic, category);
    
    if (!oComyClient.isConnected() || !oComyServer.isConnected())
    {
        LOG4CXX_ERROR(logger, modName + ": client or server not connected. Exit test!");                        
        return;
    }
    
    // send message 1
    std::string msg = "hola, que tal?";            
    oComyClient.sendMessage(msg);
    LOG4CXX_INFO(logger, modName + ": message sent ... " + msg);                

    // send message 2
    msg = "yo muy bien";            
    oComyClient.sendMessage(msg);
    LOG4CXX_INFO(logger, modName + ": message sent ... " + msg);                

    // receive message
    readByServer(oComyServer);

    // receive message
    readByServer(oComyServer);
}

void TestComy::testPublishSubscribeComs()
{
    LOG4CXX_INFO(logger, modName + ": testPublishSubscribeComs ...");
       
    comy::ComyFilePublisher oComyPublisher;
    comy::ComyFileSubscriber oComySubscriber;
    
    // connection
    // multichannel communication
    std::string topic = "topic";
    std::string category = "cat";
    oComyPublisher.connect(topic, category);
    oComySubscriber.connect(topic, category);
    
    if (!oComyPublisher.isConnected() || !oComySubscriber.isConnected())
    {
        LOG4CXX_ERROR(logger, modName + ": publisher or subscriber not connected. Exit test!");                        
        return;
    }
    
    // send message 1
    std::string msg = "hola, hay alguien?";            
    oComyPublisher.publishMessage(msg);
    LOG4CXX_INFO(logger, modName + ": message sent ... " + msg);                

    readBySubscriber(oComySubscriber);   

    // start new publishing (overwrite previous published info)
    oComyPublisher.newPublishing();

    // send message 2
    msg = "pero hay alguien?";            
    oComyPublisher.publishMessage(msg);
    LOG4CXX_INFO(logger, modName + ": message sent ... " + msg);                
    
    readBySubscriber(oComySubscriber);   
}

void TestComy::readByServer(comy::ComyFileServer& oComyServer)
{
    oComyServer.readMessages();
    LOG4CXX_INFO(logger, "server has messages " + std::to_string(oComyServer.getQueueSize()));                
    while (oComyServer.hasMessages())
    {
        std::string message = oComyServer.fetchMessage();
        if (!message.empty())
        {
            LOG4CXX_INFO(logger, modName + ": message received ... " + message);                
        }            
    }
}

void TestComy::readBySubscriber(comy::ComyFileSubscriber& oComySubscriber)
{
    oComySubscriber.readMessages();
    LOG4CXX_INFO(logger, "susbscriber has messages " + std::to_string(oComySubscriber.getQueueSize()));                
    while (oComySubscriber.hasMessages())
    {
        std::string message = oComySubscriber.fetchMessage();
        if (!message.empty())
        {
            LOG4CXX_INFO(logger, modName + ": message received ... " + message);                
        }            
    }    
}