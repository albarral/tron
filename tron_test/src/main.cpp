/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/


#include <unistd.h> // for sleep() 

#include <log4cxx/logger.h>
#include <log4cxx/xml/domconfigurator.h>

#include "TestTalky.h"
#include "TestComy.h"

log4cxx::LoggerPtr logger(log4cxx::Logger::getLogger("tron"));

// main program
int main(int argc, char** argv) 
{
    log4cxx::xml::DOMConfigurator::configure("log4cxx_config.xml");
        
    LOG4CXX_INFO(logger, "\n\nSTART tron test\n");

    // test talky lib
//    TestTalky oTestTalky;
//    oTestTalky.makeTest();
    // test comy lib
    TestComy oTestComy;
    oTestComy.makeTest();
        
    LOG4CXX_INFO(logger, "tron test FINISHED\n");
    
    return 0;
}