/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <cstdlib>  // for getenv

#include <log4cxx/logger.h>
#include <log4cxx/xml/domconfigurator.h>

#include "TestComy.h"
#include "TestMaty.h"
#include "TestNety.h"
#include "TestTivy.h"
#include "TestTalky.h"
#include "TestTalky2.h"
#include "TestTuly.h"
#include "TestTronWire.h"

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
    
     // test maty lib
//    TestMaty oTestMaty;
//    oTestMaty.makeTest();

    // test nety llib
//    TestNety oTestNety;
//    oTestNety.makeTest();

    // test tivy lib
//    TestTivy oTestTivy;
//    oTestTivy.makeTest();
    
     // test tuly lib
//    TestTuly oTestTuly;
//    oTestTuly.makeTest();
    
    // test tron_wire lib
//    TestTronWire oTestTronWire;
//    oTestTronWire.makeTest();

    // test talky2 lib
    TestTalky2 oTestTalky2;
    oTestTalky2.makeTest();
    
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
