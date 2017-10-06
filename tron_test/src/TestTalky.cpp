/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/


#include "TestTalky.h"
#include "talky/Topics.h"
#include "talky/talk/Interpreter.h"
#include "talky/coms/Command.h"

using namespace log4cxx;

LoggerPtr TestTalky::logger(Logger::getLogger("tron"));

// Constructor 
TestTalky::TestTalky()
{    
    modName = "TestTalky";
 }

void TestTalky::makeTest()
{
    LOG4CXX_INFO(logger, modName + ": test start \n");

    // create interpreter
    talky::Interpreter oInterpreter;
    // and prepare it for arm topic communications
    oInterpreter.addLanguage(talky::Topics::eTOPIC_ARM);
    // show known languages
    //oInterpreter.showKnowledge();
    
    // test message
    std::string sep = talky::Topics::FIELD_SEPARATOR;
    //std::string msg = "arm" + sep + "axis" + sep + "tilt" + sep + "10.0";            
    std::string msg = "arm" + sep + "cyclic" + sep + "move"; 
    LOG4CXX_INFO(logger, modName + ": msg > " + msg);

    // interpret test message
    if (oInterpreter.processMessage(msg))
    {
        // show obtained command
        talky::Command& oCommand = oInterpreter.getCommand();
        LOG4CXX_INFO(logger, modName + ": msg processed ok");        
        LOG4CXX_INFO(logger, modName + ": " + oCommand.toString());        
    }
    else
        LOG4CXX_WARN(logger, modName + ": msg processing failed! " + std::to_string(oInterpreter.getMessage().getStatus()));        
        
    LOG4CXX_INFO(logger, modName + ": test end \n");
};
