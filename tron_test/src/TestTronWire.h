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
    std::thread t;        // aux thread       

public:
    TestTronWire();
    //~TestTronWire();

    void makeTest();      
    
private:
    void testP2P();       
    void launchListener();
    void wait4Listener();
    
    void receiveMessages();                
    //void testPubSub();
    
};
#endif
