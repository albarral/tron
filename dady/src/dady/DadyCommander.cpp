/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "dady/DadyCommander.h"
#include "talky/Topics.h"

using namespace log4cxx;

namespace dady
{
LoggerPtr DadyCommander::logger(Logger::getLogger("dady"));

// Constructor 
DadyCommander::DadyCommander()
{    
    // prepary talky interpreter for arm topic communications
    oInterpreter.addLanguage(talky::Topics::eTOPIC_ARM);
}

bool DadyCommander::checkValidCommand(std::string entry)
{  
    bool bvalid;
    
    // interpret user command (expected in the form of talky message)
    if (oInterpreter.processMessage(entry))
    {
        bvalid = true;
        //LOG4CXX_INFO(logger, "DadyCommander: msg processed ok");        

        // if simple command
        if (!oInterpreter.isBlockProcessed())
        {
            msgTopic = oInterpreter.getCommand().getTopic();
            msgCategory = oInterpreter.getCommand().getCategory();
        }
        // if command block
        else
        {
            msgTopic = oInterpreter.getCommandBlock().getListCommands().at(0).getTopic();
            msgCategory = oInterpreter.getCommandBlock().getListCommands().at(0).getCategory();
        }            
    }
    else
    {
        bvalid = false;
        msgTopic = -1; 
        msgCategory = -1;
    }
    
    // anyway, show interpreted or misinterpreted command 
    // simple command
    if (!oInterpreter.isBlockProcessed())
    {
        LOG4CXX_INFO(logger, "DadyCommander: " + oInterpreter.getCommand().toString());        
    }
    // command block
    else
    {
        LOG4CXX_INFO(logger, "DadyCommander: " + oInterpreter.getCommandBlock().toString());        
    }            

    return bvalid;
}

void DadyCommander::showAvailableCommands()
{
    //show known languages
    oInterpreter.showKnowledge();    
}
}