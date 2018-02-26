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
    std::thread thread1;        // aux thread   
    std::thread thread2;        // aux thread   
    int node;
    int channel;

public:
    TestTronWire();
    //~TestTronWire();

    void makeTest();      
    
private:
    void testUnicast();       
    void launchListener1();
    void wait4Listener1();    
    void receiveMessages();                
    
    void testBroadcast();
    void launchListener2();
    void wait4Listener2();    
    void hearMessages();                
};
#endif
