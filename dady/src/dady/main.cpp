/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <cstdlib>  // for getenv
#include <iostream>
#include <string>

#include <log4cxx/logger.h>
#include <log4cxx/xml/domconfigurator.h>

#include "dady/DadyCommander.h"
#include "dady/DadyCommunicator.h"

// obtains user's home path
std::string getHomePath();

log4cxx::LoggerPtr logger(log4cxx::Logger::getLogger("dady"));

// main program of amy2
int main(int argc, char** argv) 
{       
    std::string home = getHomePath();
    std::string configFile = home + "/.tron/log4cxx_config_dady.xml";
    log4cxx::xml::DOMConfigurator::configure(configFile);    
    
    const int MAX_PARTS = 2;    // command must have to parts: amy2 + talky message (with no spaces)
    // create commander and communicator
    dady::DadyCommander oDadyCommander;
    dady::DadyCommunicator oDadyCommunicator;
    
    // if command has wrong number of params, show usage
    if (argc == 1 || argc > MAX_PARTS)
    {
        LOG4CXX_WARN(logger, "usage: dady <talky message>");        
        LOG4CXX_INFO(logger, "Talky available language ...");        
        oDadyCommander.showAvailableCommands();
        return 0;
    }    
    
    // read command
    std::string userCommand = argv[1];      // read user talky message
//    std::string sep = "*";
//    std::string userCommand = "arm" + sep + "axis" + sep + "tilt" + sep + "10.0";            
    
    // interpret command
    // if valid, send it to amy
    bool bsent = false;
    if (oDadyCommander.checkValidCommand(userCommand))
    {
        if (oDadyCommunicator.connect2Amy())
            bsent = oDadyCommunicator.sendCommand(userCommand);
    }
    
    if (bsent)
    {
        LOG4CXX_INFO(logger, "dady: msg sent");                            
    }
    else
    {
        LOG4CXX_WARN(logger, "dady: msg not sent");            
    }
    
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
