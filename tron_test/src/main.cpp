/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <cstdlib>  // for getenv

#include <log4cxx/logger.h>
#include <log4cxx/xml/domconfigurator.h>

#include "TestTalky.h"
#include "TestComy.h"
#include "Listener.h"

// obtains user's home path
std::string getHomePath();

log4cxx::LoggerPtr logger(log4cxx::Logger::getLogger("tron"));

// main program
int main(int argc, char** argv) 
{
    std::string home = getHomePath();
    std::string configFile = home + "/.tron/log4cxx_config_trontest.xml";
    log4cxx::xml::DOMConfigurator::configure(configFile);    
        
    LOG4CXX_INFO(logger, "\n\nSTART tron test\n");

    // test talky lib
//    TestTalky oTestTalky;
//    oTestTalky.makeTest();

    // test comy lib
//    TestComy oTestComy;
//    oTestComy.makeTest();
    
    tron::Listener oListener;
    oListener.run(10);
        
    LOG4CXX_INFO(logger, "tron test FINISHED\n");
    
    return 0;
}

std::string getHomePath()
{    
    // obtain value of HOME environment variable
    char* pVar = getenv("HOME");    
    if (pVar!=NULL)
    {
        // transform it in a string
        std::string home(pVar);
        return home;
    }
    else
        return "";
}
