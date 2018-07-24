/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <unistd.h>

#include "TestComs.h"
#include "tron/coms/Communicator.h"

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

    std::string message = "hola";
    
    tron::Communicator oCommunicator;
    oCommunicator.setChannelReader("arm", "joints", "hs", tron::ComsChannel::eCHANNEL_CONTROL);
    oCommunicator.setChannelWriter("arm", "joints", "hs", tron::ComsChannel::eCHANNEL_CONTROL);
    
    oCommunicator.getChannelWriter()->sendMessage(message);
    
    usleep(1000000);                  
        
    LOG4CXX_INFO(logger, modName + ": test end \n");
};

//void TestComs::makeTest()
//{
//    LOG4CXX_INFO(logger, modName + ": test start \n");
//
//    std::string message = "hola";
//    
//    std::function<int(std::string)> func = std::bind(&TestComs::checkSize, this, std::placeholders::_1);
//    analyseMessage(message, func);
//        
//    LOG4CXX_INFO(logger, modName + ": test end \n");
//};

void TestComs::analyseMessage(std::string message, std::function<int(std::string)> cb)
{
    int size = cb(message);
    LOG4CXX_INFO(logger, "size of " + message + " is " + std::to_string(size));
}

int TestComs::checkSize(std::string message)
{
    return message.size();
}


