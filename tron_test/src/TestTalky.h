#ifndef __TRON_TESTTALKY_H
#define __TRON_TESTTALKY_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>

#include "talky/talk/Interpreter.h"

// Class used to test talky lib.
class TestTalky
{
private:
    static log4cxx::LoggerPtr logger;
    std::string modName;          // module name

public:
    TestTalky();
    //~TestTalky();

    void makeTest();      
    
private:
    void testMessageInterpretation(talky::Interpreter& oInterpreter);                
    void testCommandInterpretation(talky::Interpreter& oInterpreter);
    void testCommandBlockInterpretation(talky::Interpreter& oInterpreter);
    void testArmJointAnglesBlockInterpretation(talky::Interpreter& oInterpreter);
};
#endif
