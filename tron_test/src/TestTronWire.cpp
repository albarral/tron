/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <unistd.h>
#include <vector>

#include "TestTronWire.h"
#include "tron/wire/console/ConsoleWire.h"

using namespace log4cxx;

LoggerPtr TestTronWire::logger(Logger::getLogger("tron.wire"));

// Constructor 
TestTronWire::TestTronWire()
{    
    modName = "TestTronWire";
 }

void TestTronWire::makeTest()
{
    LOG4CXX_INFO(logger, modName + ": test start \n");

    testP2P();
        
    LOG4CXX_INFO(logger, modName + ": test end \n");
};

void TestTronWire::testP2P()
{
    LOG4CXX_INFO(logger, modName + ": testP2P ...");
        
    launchListener();
    
    usleep(1000000);
    
    tron::ConsoleWire oWire;
    std::string message1 = "hola, que tal?\n";
    std::string message2 = "me alegro\n";
    std::string message3 = "ok, bye!\n";
    
    int node = 1; 
    int channel = 2;
    
    oWire.sendMsg(node, channel, message1);
    oWire.sendMsg(node, channel, message2);
    oWire.sendMsg(node, channel, message3);
        
    wait4Listener();
}

void TestTronWire::launchListener()
{
    LOG4CXX_INFO(logger, "TestTronWire::launchListener");
    t = std::thread(&TestTronWire::receiveMessages, this);              
}

void TestTronWire::wait4Listener()
{
    t.join();
}

void TestTronWire::receiveMessages()
{
    LOG4CXX_INFO(logger, "TestTronWire::receiveMessages");

    std::vector<std::string> listMessages;
    std::string stop = "stop";

    tron::ConsoleWire oWire;    
    int node = 1; 
    int channel = 2;
    
    bool bend = false;
    // get messages from channel until stop is received
    while (!bend)
    {    
        bool bok = oWire.receiveMessages(node, channel, listMessages);

        if (bok)
        {
            LOG4CXX_INFO(logger, modName + ": messages received ...");
            for (std::string message : listMessages)
            {
                LOG4CXX_INFO(logger, message);
                if (message.compare(stop) == 0)
                {
                    bend = true;
                    break;
                }
            }
        }
        else 
            bend = true;
    }
    
}
