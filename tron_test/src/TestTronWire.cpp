/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <unistd.h>
#include <vector>
#include "log4cxx/ndc.h"

#include "TestTronWire.h"
#include "tron/wire/Wire.h"
#include "tron/wire/console/ConsoleWire.h"
#include "tron/wire2/FileWire.h"

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

    bfileComs = true;   // use file coms
    testClientServer();
    //testBroadcast();
        
    LOG4CXX_INFO(logger, modName + ": test end \n");
};

void TestTronWire::testClientServer()
{
    log4cxx::NDC::push("Client");   	
    
    LOG4CXX_INFO(logger, "test client server ...");
        
    node = 1;
    channel = 2;
        
    tron::Wire* pWire = 0;
    if (bfileComs)
        pWire = new tron::FileWire();
    else
        pWire = new tron::ConsoleWire();

    launchCSListener();    
    usleep(1000000);                
    
    std::string message1 = "hola, que tal?";
    std::string message2 = "me alegro";
    std::string message3 = "ok, bye!";
    pWire->sendMsg(node, channel, message1);
    pWire->sendMsg(node, channel, message2);
    pWire->sendMsg(node, channel, message3);
    pWire->sendMsg(node, channel, "stop");
        
    wait4CSListener();
    
    if (pWire != 0)
        delete pWire;
}


void TestTronWire::testBroadcast()
{
    log4cxx::NDC::push("Broadcaster");   	
    
    LOG4CXX_INFO(logger, "test broadcast ...");
        
    node = 1;
    channel = 3;
        
    tron::Wire* pWire = 0;
    if (bfileComs)
        pWire = new tron::FileWire();
    else
        pWire = new tron::ConsoleWire();

    launchPSListener();    
    usleep(1000000);                
    
    std::string message1 = "hola, que tal?";
    std::string message2 = "me alegro";
    std::string message3 = "ok, bye!";
    pWire->publishMsg(node, channel, message1);
    pWire->publishMsg(node, channel, message2);
    pWire->publishMsg(node, channel, message3);
    pWire->publishMsg(node, channel, "stop");
        
    wait4PSListener();
    
    if (pWire != 0)
        delete pWire;    
}


void TestTronWire::launchCSListener()
{
    LOG4CXX_INFO(logger, "launchCSListener");
    threadCS = std::thread(&TestTronWire::receiveMessages, this);              
}


void TestTronWire::launchPSListener()
{
    LOG4CXX_INFO(logger, "launchPSListener");
    threadPS = std::thread(&TestTronWire::hearMessages, this);              
}


void TestTronWire::wait4CSListener()
{
    threadCS.join();
}

void TestTronWire::wait4PSListener()
{
    threadPS.join();
}


void TestTronWire::receiveMessages()
{
    log4cxx::NDC::push("CSListener");   	
    
    LOG4CXX_INFO(logger, "receive messages ...");

    std::vector<std::string> listMessages;
    std::string stop = "stop";

    tron::Wire* pWire = 0;
    if (bfileComs)
        pWire = new tron::FileWire();
    else
        pWire = new tron::ConsoleWire();
    
    bool bend = false;
    // get messages from channel until stop is received
    while (!bend)
    {    
        bool bok = pWire->receiveMessages(node, channel, listMessages);
        // if messages received    
        if (bok)
        {
            LOG4CXX_INFO(logger, "messages received ...");
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
        
        usleep(1000000);                
    }    

    if (pWire != 0)
        delete pWire;    
}

void TestTronWire::hearMessages()
{
    log4cxx::NDC::push("PSListener");   	

    LOG4CXX_INFO(logger, "hearMessages ...");

    std::vector<std::string> listMessages;
    std::string stop = "stop";

    tron::Wire* pWire = 0;
    if (bfileComs)
        pWire = new tron::FileWire();
    else
        pWire = new tron::ConsoleWire();
    
    bool bend = false;
    // get messages from channel until stop is received
    while (!bend)
    {    
        bool bok = pWire->hearMessages(node, channel, listMessages);
        // if messages received    
        if (bok)
        {
            LOG4CXX_INFO(logger, "messages heard ...");
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
        
        usleep(1000000);        
    }    
    
    if (pWire != 0)
        delete pWire;    
}


