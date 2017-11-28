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
    
    // if command has wrong number of params, show usage
    if (argc == 1 || argc > MAX_PARTS)
    {
        LOG4CXX_WARN(logger, "usage: dady <talky message>");        
        LOG4CXX_INFO(logger, "Talky available language ...");        
        oDadyCommander.showAvailableCommands();
        return 0;
    }    
    
    // read command
    std::string userMessage = argv[1];      
    
    // check command validity (if it can be interpreted)
    bool bsent = false;
    if (oDadyCommander.checkValidCommand(userMessage))
    {
        // if valid, send it to proper node
        bsent = oDadyCommander.sendMessage(userMessage, oDadyCommander.getInterpretedTopic(), oDadyCommander.getInterpretedCategory());
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
