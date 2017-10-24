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
    void testReadMessage(talky::Interpreter& oInterpreter, std::string msg);                
    std::string testWriteMessage(talky::Interpreter& oInterpreter);
    std::string testWriteMessageBlock(talky::Interpreter& oInterpreter);
    std::string testWriteMessageArmAngles(talky::Interpreter& oInterpreter);
};
#endif
