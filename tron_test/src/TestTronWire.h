#ifndef __TRON_TEST_WIRE_H
#define __TRON_TEST_WIRE_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <thread>

#include <log4cxx/logger.h>

// Class used to test tron_wire lib.
class TestTronWire
{
private:
    static log4cxx::LoggerPtr logger;
    std::string modName;          // module name
    std::thread threadCS;        // aux thread   
    std::thread threadPS;        // aux thread   
    int node;
    int channel;
    bool bfileComs;                 // use file coms

public:
    TestTronWire();
    //~TestTronWire();

    void makeTest();      
    
private:
    void testClientServer();       
    void launchCSListener();
    void wait4CSListener();    
    void receiveMessages();                
    
    void testBroadcast();
    void launchPSListener();
    void wait4PSListener();    
    void hearMessages();                
};
#endif
