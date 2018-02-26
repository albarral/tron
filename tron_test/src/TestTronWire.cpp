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

    //testUnicast();
    testBroadcast();
        
    LOG4CXX_INFO(logger, modName + ": test end \n");
};

void TestTronWire::testUnicast()
{
    LOG4CXX_INFO(logger, modName + ": testUnicast ...");
        
    node = 1;
    channel = 2;
        
    tron::ConsoleWire oWire;

    launchListener1();    
    usleep(1000000);
    
    std::string message1 = "hola, que tal?\n";
    std::string message2 = "me alegro\n";
    std::string message3 = "ok, bye!\n";
    oWire.sendMsg(node, channel, message1);
    oWire.sendMsg(node, channel, message2);
    oWire.sendMsg(node, channel, message3);
        
    wait4Listener1();
}


void TestTronWire::testBroadcast()
{
    LOG4CXX_INFO(logger, modName + ": testBroadcast ...");
        
    node = 1;
    channel = 3;
        
    tron::ConsoleWire oWire;

    launchListener2();    
    usleep(1000000);
    
    std::string message1 = "hola, que tal?\n";
    std::string message2 = "me alegro\n";
    std::string message3 = "ok, bye!\n";
    oWire.publishMsg(node, channel, message1);
    oWire.publishMsg(node, channel, message2);
    oWire.publishMsg(node, channel, message3);
        
    wait4Listener2();
}


void TestTronWire::launchListener1()
{
    LOG4CXX_INFO(logger, "TestTronWire::launchListener1");
    thread1 = std::thread(&TestTronWire::receiveMessages, this);              
}


void TestTronWire::launchListener2()
{
    LOG4CXX_INFO(logger, "TestTronWire::launchListener2");
    thread2 = std::thread(&TestTronWire::hearMessages, this);              
}


void TestTronWire::wait4Listener1()
{
    thread1.join();
}

void TestTronWire::wait4Listener2()
{
    thread2.join();
}


void TestTronWire::receiveMessages()
{
    LOG4CXX_INFO(logger, "TestTronWire::receiveMessages");

    std::vector<std::string> listMessages;
    std::string stop = "stop";

    tron::ConsoleWire oWire;    
    
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

void TestTronWire::hearMessages()
{
    LOG4CXX_INFO(logger, "TestTronWire::hearMessages");

    std::vector<std::string> listMessages;
    std::string stop = "stop";

    tron::ConsoleWire oWire;    
    
    bool bend = false;
    // get messages from channel until stop is received
    while (!bend)
    {    
        bool bok = oWire.hearMessages(node, channel, listMessages);

        if (bok)
        {
            LOG4CXX_INFO(logger, modName + ": messages heard ...");
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


