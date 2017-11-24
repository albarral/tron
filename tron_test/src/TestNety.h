#ifndef __TRON_TESTNETY_H
#define __TRON_TESTNETY_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/


#include <string>
#include <log4cxx/logger.h>

#include "nety/NetNodeServer.h"
#include "nety/NetNodeSubscriber.h"


// Class used to test nety lib.
class TestNety
{
private:
    static log4cxx::LoggerPtr logger;
    std::string modName;          // module name

public:
    TestNety();
    //~TestNety();

    void makeTest();      
    
private:
    void testCSComs();                
    void testPSComs();
    void readByServer(nety::NetNodeServer& oNetyServer);
    void readBySubscriber(nety::NetNodeSubscriber& oNetySubscriber);
    
};
#endif
