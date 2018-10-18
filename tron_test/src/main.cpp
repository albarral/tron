/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <cstdlib>  // for getenv

#include <log4cxx/logger.h>
#include <log4cxx/xml/domconfigurator.h>

#include "TestControl.h"
#include "TestComs.h"
#include "TestDiagram.h"
#include "TestDisplay.h"
#include "TestMath.h"
#include "TestSignals.h"
#include "TestUtil.h"
#include "TestTools.h"

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
    
//    TestControl oTestControl;
//    oTestControl.makeTest();

//    TestComs oTestComs;
//    oTestComs.makeTest();

    TestDiagram oTestDiagram;
    oTestDiagram.makeTest();
    
    //    TestDisplay oTestDisplay;
//    oTestDisplay.makeTest();

//    TestMath oTestMath;
//    oTestMath.makeTest();

//    TestSignals oTestSignals;
//    oTestSignals.makeTest();
    
//    TestUtil oTestUtil;
//    oTestUtil.makeTest();

    //    TestTool oTestTool;
//    oTestTool.makeTest();
    
    
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
