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

// main program of dady
int main(int argc, char** argv) 
{       
    std::string home = getHomePath();
    std::string configFile = home + "/.tron/log4cxx_config_dady.xml";
    log4cxx::xml::DOMConfigurator::configure(configFile);    
    
    // create commander 
    tron::DadyCommander oDadyCommander;

    // expected entry: dady node section channel value
    // if command has wrong number of params, show usage
    if (argc != oDadyCommander.getCommandSize() + 1)
    {
        LOG4CXX_WARN(logger, "usage: dady node section channel value");        
    }    
    
    // read command
    std::string userCommand = "";
    for (int i=1; i<argc; i++)
    {
        userCommand += argv[i]; 
        if (i != argc-1)
            userCommand += tron::DadyCommander::COMMAND_SEPARATOR;      
    }
            
    // check command validity (if it can be interpreted)
    bool bsent = false;
    if (oDadyCommander.checkValidCommand(userCommand))
    {
        // if valid, send it to proper node
        bsent = oDadyCommander.sendMessage();
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
