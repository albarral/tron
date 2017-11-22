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
    
void NetNode::processCommandsQueue() 
{
    // not allowed for input nodes
    if (!btypeOut)
    {
        LOG4CXX_WARN(logger, "NetNode: can't process commands queue, not an output node");           
        return;
    }
    
    // skip if no commands to process
    if (!oCommandQueue.isFilled())
        return;
    
    talky::Command oCommand;        
    talky::Message oMessage;
    
    // consume the whole commands queue
    while (oCommandQueue.fetch(oCommand))
    {
        // build a message from each command & add it to the messages queue
        if (oInterpreter.buildSimpleMessage(oCommand, oMessage))
            oMessageQueue.add(oMessage.getRawText());      
        else
        {                
            LOG4CXX_WARN(logger, "NetNode.processCommandsQueue: command not interpreted, discarded - " + oCommand.toString());                                                                                   
        }
    }
}

void NetNode::processMessagesQueue() 
{
    // not allowed for output nodes
    if (btypeOut)
    {
        LOG4CXX_WARN(logger, "NetNode: can't process messages queue, not an input node");           
        return;
    }
    
    // skip if no messages to process
    if (!oMessageQueue.isFilled())
        return;
    
    std::string message;

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
                    LOG4CXX_WARN(logger, "NetNode.processMessagesQueue: message block received, discarded - " + message);                                                       
                }                    
            }
            else
            {
                LOG4CXX_WARN(logger, "NetNode.processMessagesQueue: message misinterpreted, discarded - " + message);                                                                       
            }                
        }
    }                
}

}