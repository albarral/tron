/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/


#include "TestTuly.h"
#include "tuly/utils/MessageQueue.h"

using namespace log4cxx;

LoggerPtr TestTuly::logger(Logger::getLogger("tron"));

// Constructor 
TestTuly::TestTuly()
{    
    modName = "TestTuly";
 }

void TestTuly::makeTest()
{
    LOG4CXX_INFO(logger, modName + ": test start \n");

    testMessageQueue();        
        
    LOG4CXX_INFO(logger, modName + ": test end \n");
};

void TestTuly::testMessageQueue()
{
    LOG4CXX_INFO(logger, modName + ": testMessageQueue ...");

    std::string msg;
    tuly::MessageQueue oMessageQueue;
        
    msg = "message1";
    oMessageQueue.add(msg);
    msg = "message2";
    oMessageQueue.add(msg);
    
    LOG4CXX_INFO(logger, "message queue has messages " + std::to_string(oMessageQueue.getSize()));
    
    while (oMessageQueue.isFilled())
    {
        msg = oMessageQueue.fetch();
        
        LOG4CXX_INFO(logger, "message fetched: " + msg);
    }        

}
