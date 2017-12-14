/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "dady/DadyCommander.h"
#include "comy/file/ComyFileClient.h"
#include "talky/Topics.h"

using namespace log4cxx;

namespace dady
{
LoggerPtr DadyCommander::logger(Logger::getLogger("dady"));

// Constructor 
DadyCommander::DadyCommander()
{    
    // prepare talky interpreter for all necessary topics 
    oInterpreter.addLanguage(talky::Topics::eTOPIC_ARM);
    oInterpreter.addLanguage(talky::Topics::eTOPIC_VISION);
    oInterpreter.addLanguage(talky::Topics::eTOPIC_BODYROLE);
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

bool DadyCommander::sendMessage(std::string message, int topic, int category)
{
    // get names of topic & category
    std::string topicName = oInterpreter.getTopicName(topic);
    std::string categoryName = oInterpreter.getCategoryName(topic, category);
    
    // skip if topic or category unknown
    if (topicName.empty() || categoryName.empty())
    {    
        LOG4CXX_WARN(logger, "DadyCommander: can't send message, unknown topic - category");                        
        return false;
    }
    
    // create client and connect it to proper node
    comy::ComyFileClient oComyClient;
    oComyClient.connect(topicName, categoryName);
    // skip if client not connected
    if (!oComyClient.isConnected())
    {
        LOG4CXX_WARN(logger, "DadyCommander: can't send message, coms client couldn't connect");                        
        return false;        
    }
    
    // send message 
    bool bsent = oComyClient.sendMessage(message);
    
    if (!bsent)
    {
        LOG4CXX_WARN(logger, "DadyCommander: message not sent");                        
    }

    return bsent;
}

void DadyCommander::showAvailableCommands()
{
    //show known languages
    oInterpreter.showKnowledge();    
}
}