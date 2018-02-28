#ifndef __TRON_TESTTALKY2_H
#define __TRON_TESTTALKY2_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>

#include "tron/talky2/clients/ArmClient.h"
#include "tron/talky2/listeners/ArmListener.h"

// Class used to test coms with libtron_talky2.
class TestTalky2
{
private:
    static log4cxx::LoggerPtr logger;
    std::string modName;          // module name
   

public:
    TestTalky2();
    //~TestTalky2();

    void makeTest();      
    
private:
    void sendArmCommand(tron::ArmClient& oArmClient, float hs);
    void senseArmInfo(tron::ArmListener& oArmListener);                
};
#endif
