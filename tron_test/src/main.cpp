/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/


#include <string>
#include <unistd.h> // for sleep() 

#include <log4cxx/logger.h>
#include <log4cxx/xml/domconfigurator.h>

#include "talky/Topics.h"
#include "talky/coms/Interpreter.h"

using namespace talky;

log4cxx::LoggerPtr logger(log4cxx::Logger::getLogger("tron"));

// main program
int main(int argc, char** argv) 
{
    log4cxx::xml::DOMConfigurator::configure("log4cxx_config.xml");
        
    LOG4CXX_INFO(logger, "\n\nSTART tron test\n");

    // test talky interpreter
    Interpreter oInterpreter;
    // prepare for arm topic
    oInterpreter.addLanguage(Topics::eTOPIC_ARM);
    
    oInterpreter.showKnowledge();

    LOG4CXX_INFO(logger, "tron test FINISHED\n");
    
    return 0;
}