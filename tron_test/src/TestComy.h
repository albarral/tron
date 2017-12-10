#ifndef __TRON_TESTCOMY_H
#define __TRON_TESTCOMY_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/


#include <string>
#include <log4cxx/logger.h>
#include <zmq.hpp>

#include "comy/zero/ComyZeroServer.h"
#include "comy/zero/ComyZeroSubscriber.h"


// Class used to test comy lib.
class TestComy
{
private:
    static log4cxx::LoggerPtr logger;
    std::string modName;          // module name

public:
    TestComy();
    //~TestComy();

    void makeTest();      
    
private:
    void testClientServerComs();                
    void testPublishSubscribeComs();
    void readByServer(comy::ComyZeroServer& oComyServer);
    void readBySubscriber(comy::ComyZeroSubscriber& oComySubscriber);
    
};
#endif
