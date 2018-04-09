/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "TestUtil.h"
#include "tron/util/MessageQueue.h"

using namespace log4cxx;

LoggerPtr TestUtil::logger(Logger::getLogger("tron"));

// Constructor 
TestUtil::TestUtil()
{    
    modName = "TestUtil";
 }

void TestUtil::makeTest()
{
    LOG4CXX_INFO(logger, modName + ": test start \n");

    testMessageQueue();        
        
    LOG4CXX_INFO(logger, modName + ": test end \n");
};

void TestUtil::testMessageQueue()
{
    LOG4CXX_INFO(logger, modName + ": testMessageQueue ...");

    std::string msg;
    tron::MessageQueue oMessageQueue;
        
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

