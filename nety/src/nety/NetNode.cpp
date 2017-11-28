/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/


#include "nety/NetNode.h"
#include "talky/coms/Message.h"

namespace nety
{
log4cxx::LoggerPtr NetNode::logger(log4cxx::Logger::getLogger("tron.nety"));

NetNode::NetNode()
{    
    btuned = false;
    bconnected = false;
}

NetNode::~NetNode()
{
    oCommandQueue.clean();
    oMessageQueue.clean();
}

void NetNode::init(int topic, int category)
{    
    // if reinitialization, reset interpreter
    if (btuned)
    {
        oInterpreter.reset();
        btuned = false;
    }
    
    // prepare interpreter for the topic
    oInterpreter.addLanguage(topic);

    // if category is known, initialization is good
    if (oInterpreter.knowsTopicCategory(topic, category))
    {        
        this->topic = topic;
        this->category = category;
        btuned = true;
        // if tuned, connect to proper link
        connect();
    }
}

bool NetNode::hasCommands()
{
    return oCommandQueue.isFilled();
}    

bool NetNode::hasMessages()
{
    return oMessageQueue.isFilled();
}  

int NetNode::getSizeCommandsQueue()
{
    return oCommandQueue.getSize();
}

int NetNode::getSizeMessagesQueue()
{
    return oMessageQueue.getSize();    
}

void NetNode::addCommand(int concept, float quantity)
{  
    // not allowed for input nodes
    if (!btypeOut)
    {
        LOG4CXX_WARN(logger, "NetNode: can't add command, not an output node");           
        return;
    }
    
    talky::Command oCommand;
    oCommand.setTopic(topic);
    oCommand.setCategory(category);
    oCommand.setConcept(concept);
    oCommand.setQuantity(quantity);    
    oCommandQueue.add(oCommand);
}

void NetNode::addCommand(int concept)
{  
    // not allowed for input nodes
    if (!btypeOut)
    {
        LOG4CXX_WARN(logger, "NetNode: can't add command, not an output node");           
        return;
    }

    talky::Command oCommand;
    oCommand.setTopic(topic);
    oCommand.setCategory(category);
    oCommand.setConcept(concept);
    oCommandQueue.add(oCommand);
}

bool NetNode::fetchCommand(talky::Command& oCommand)
{
    return oCommandQueue.fetch(oCommand);
}

void NetNode::clean()
{
    oCommandQueue.clean();
    oMessageQueue.clean();    
}
    
bool NetNode::process()
{
    if (btypeOut)
        return processCommandsQueue();
    else
        return processMessagesQueue();
}

bool NetNode::processCommandsQueue() 
{
    // if no commands to process, return all ok
    if (!oCommandQueue.isFilled())
        return true;
    
    talky::Command oCommand;        
    talky::Message oMessage;    
    int failed = 0;
    
    // consume the whole commands queue
    while (oCommandQueue.fetch(oCommand))
    {
        // build a message from each command & add it to the messages queue
        if (oInterpreter.buildSimpleMessage(oCommand, oMessage))
            oMessageQueue.add(oMessage.getRawText());      
        else
        {      
            failed++;
            LOG4CXX_WARN(logger, "NetNode: command processing failed, not interpreted - " + oCommand.toString());                                                                                   
        }
    }

    if (failed != 0)
    {
        LOG4CXX_WARN(logger, "NetNode: commands processing failed " << failed);
    }        
    
    // return true if all commands processed ok
    return (failed == 0);
}

bool NetNode::processMessagesQueue() 
{
    // if no messages to process, return all ok
    if (!oMessageQueue.isFilled())
        return true;
    
    std::string message;
    int failed = 0;

    // consume the whole messages queue
    while (oMessageQueue.isFilled())
    {
        message = oMessageQueue.fetch();
        if (!message.empty())
        {
            // interpret each message and add obtained command to commands queue
            if (oInterpreter.processMessage(message))
            {
                // just accept simple messages
                if (!oInterpreter.isBlockProcessed())
                    oCommandQueue.add(oInterpreter.getCommand());                
                else
                {
                    failed++;
                    LOG4CXX_WARN(logger, "NetNode: message processing failed, block interpreted - " + message);                                                       
                }                    
            }
            else
            {
                failed++;
                LOG4CXX_WARN(logger, "NetNode: message processing failed, not interpreted - " + message);                                                                       
            }                
        }
    }
    
    if (failed != 0)
    {
        LOG4CXX_WARN(logger, "NetNode: messages processing failed " << failed);
    }        
    
    // return true if all messages processed ok
    return (failed == 0);
}

}