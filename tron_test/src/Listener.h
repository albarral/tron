#ifndef __TRON_TEST_LISTERNER_H
#define __TRON_TEST_LISTERNER_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>

#include "comy/file/ComyFileSubscriber.h"
#include "talky/talk/Interpreter.h"
#include "talky2/arm/ArmJointAngles.h"


namespace tron
{
// Class used to listen to robotic nodes
class Listener
{
private:
    static log4cxx::LoggerPtr logger;
    std::string modName;          // module name
    comy::ComyFileSubscriber oComySubscriber;     // comy coms subscriber
    talky::Interpreter oInterpreter;                           // talky language interpreter        
    talky2::ArmJointAngles oJointAngles;                    // talky2 utility to process arm joints info
    talky2::ArmJointAngles oJointAngles0;                  // talky2 utility to process arm joints info
    

public:
    Listener();
    //~Listener();

    void run(int numIterations);
    
private:
    void listen();      
    bool processMessage(std::string rawMessage);    
    void showAngles();  

};

}
#endif
