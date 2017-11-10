/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <stdexcept>      // std::out_of_range

#include "talky/talk/Interpreter.h"
#include "talky/topics/ArmTopic.h"
#include "talky/topics/BodyTopic.h"
#include "talky/Topics.h"

using namespace log4cxx;

namespace talky
{
LoggerPtr Interpreter::logger(Logger::getLogger("talky"));
    
Interpreter::Interpreter()
{
}

Interpreter::~Interpreter()
{
    reset();
}

void Interpreter::reset()
{
    mapTopicNumbers.clear();
    mapTopicNames.clear();
    mapTalkers.clear();
    blockProcessing = false;
}

void Interpreter::addLanguage(int topicId)
{
    bool bvalidTopic = false;    
    // get topic name 
    std::string topicName = Topics::getTopicName(topicId);
    // create talker for topic
    Talker oTalker;
    
    // tune the talk topic for the specified topic and language 
    switch (topicId)
    {
        case Topics::eTOPIC_ARM:
        {
            // build arm topic
            ArmTopic oArmTopic;
            oArmTopic.build();
            // and apply it to talker
            oTalker.build(oArmTopic);
            bvalidTopic = true;
            break;            
        }

        case Topics::eTOPIC_BODYROLE:
        {
            // build body role topic
            BodyTopic oBodyTopic;
            oBodyTopic.build();
            // and apply it to talker
            oTalker.build(oBodyTopic);
            bvalidTopic = true;
            break;            
        }
    }
    
    // if talk topic created
    if (bvalidTopic)
    {        
        // add topic to maps
        mapTopicNumbers.emplace(topicName, topicId);    
        mapTopicNames.emplace(topicId, topicName);    
        // and add talker to interpreter
        mapTalkers.emplace(topicId, oTalker);        
    }
}

bool Interpreter::understandsLanguage(std::string topicName)
{
    return (mapTopicNumbers.find(topicName) != mapTopicNumbers.end());
}

bool Interpreter::processMessage(std::string text)
{
    // check message header to see if it's simple or a block
    std::string header = text.substr(0, Topics::BLOCK_HEADER.size());
    blockProcessing = (header.compare(Topics::BLOCK_HEADER) == 0);
    
    // process simple message
    if (!blockProcessing)
    {
        Message oMessage;
        oMessage.setRawText(text);
        return processSimpleMessage(oMessage, oCommand);
    }
    // process message block
    else
    {
        MessageBlock oMessageBlock;       
        oMessageBlock.setRawText(text);
        return processMessageBlock(oMessageBlock, oCommandBlock);
    }
}

// process the message using a talker suitable for the message's topic
bool Interpreter::processSimpleMessage(Message& oMessage, Command& oCommand)
{
    // reset command
    oCommand.reset();
 
    // digest simple message
    oMessage.digestMessage();

    // if message complete
    if (oMessage.isComplete())
    {
        // interpret topic 
        int topicId = getTopicNumber(oMessage.getTopic());
        
        // if known topic
        if (topicId != Topics::INVALID_VALUE)
        { 
            // get topic talker 
            Talker* pTalker = getTopicTalker(topicId);

            // if talker found, interpret rest of message                 
            if (pTalker != 0)
            {
                // inform command topic
                oCommand.setTopic(topicId);
                oMessage.setTopicValidity(true);

                pTalker->processMessage(oMessage, oCommand);     
            }
            // missing talker
            else
            {
                LOG4CXX_WARN(logger, "Interpreter: missing talker for topic " << oMessage.getTopic());
            }
        }
        // unknown topic
        else
        {
            LOG4CXX_WARN(logger, "Interpreter: unknown topic " << oMessage.getTopic());
        }
    }   
    // incomplete message
    else
        LOG4CXX_WARN(logger, "Interpreter: incomplete message " << oMessage.getRawText());          
    
    return oMessage.isInterpreted();
}


// process the given message block iterating through each forming simple message 
bool Interpreter::processMessageBlock(MessageBlock& oMessageBlock, CommandBlock& oCommandBlock)
{        
    // reset command block
    oCommandBlock.reset();
 
    // digest message block
    oMessageBlock.digestBlock();

    // if message block filled
    if (oMessageBlock.getListMessages().size() > 0)
    {
        // for each simple message
        for (Message& oMessage : oMessageBlock.getListMessages())
        {
            // create simple command
            Command oCommand;
            // interpret message 
            if (processSimpleMessage(oMessage, oCommand))
            {
                // if well interpreted add obtained command to resulting commands block
                oCommandBlock.addCommand(oCommand);
            }
        }
    }   
    // empty message block
    else
        LOG4CXX_WARN(logger, "Interpreter: incomplete message block " << oMessageBlock.getRawText());          
    
    return oMessageBlock.isInterpreted();
}


bool Interpreter::buildSimpleMessage(Command& oCommand, Message& oMessage)
{
    // reset message    
    oMessage.reset();
    
    // and reset command validity
    oCommand.resetValidityFlags();
            
    // if command complete
    if (oCommand.isComplete())
    {
        // get topic name 
        std::string topicName = getTopicName(oCommand.getTopic());

        // if known topic
        if (!topicName.empty())
        {
            // get topic talker 
            Talker* pTalker = getTopicTalker(oCommand.getTopic());

            // if talker found, build rest of message                 
            if (pTalker != 0)
            {
                // inform message topic
                oMessage.setTopic(topicName);
                oCommand.setTopicValidity(true);

                pTalker->buildMessage(oCommand, oMessage);        
                // compose message raw text
                oMessage.composeMessage();
            }
            // missing talker
            else
                LOG4CXX_WARN(logger, "Interpreter: missing talker for topic " << topicName);        
        }
        // unknown topic
        else
            LOG4CXX_WARN(logger, "Interpreter: unknown topic " << oCommand.getTopic());                
    }   
    // incomplete command
    else
        LOG4CXX_WARN(logger, "Interpreter: incomplete command " << oCommand.toString());          

    return oCommand.isInterpreted();
}


// build message block from given command block, iterating through each forming command
bool Interpreter::buildMessageBlock(CommandBlock& oCommandBlock, MessageBlock& oMessageBlock)
{        
    // reset message block    
    oMessageBlock.reset();
        
    // for each simple command
    for (Command& oCommand : oCommandBlock.getListCommands())
    {
        // create simple message
        Message oMessage;
        // build message from command
        if (buildSimpleMessage(oCommand, oMessage))
        {
            // if well built add obtained message to resulting message block
            oMessageBlock.addMessage(oMessage);            
        }
    }

    // compose message block raw text
    oMessageBlock.composeBlock();

    return oCommandBlock.isInterpreted();
}


int Interpreter::getTopicNumber(std::string topicName)
{
    try 
    {
        // get id of given topic name
        return mapTopicNumbers.at(topicName);
    }
    // return invalid if not found
    catch (const std::out_of_range& oor) 
    {                
        return Topics::INVALID_VALUE;
    }            
}        

std::string Interpreter::getTopicName(int topicId)
{
    try 
    {
        // get name of given topic id
        return mapTopicNames.at(topicId);
    }
    // return empty if not found
    catch (const std::out_of_range& oor) 
    {                
        return Topics::EMPTY_VALUE;
    }                
}

Talker* Interpreter::getTopicTalker(int topicId)
{
    try 
    {
        // get talker for given topic 
        return &(mapTalkers.at(topicId));
    }
    // return 0 if not found
    catch (const std::out_of_range& oor) 
    {                
        return 0;
    }            
}        

void Interpreter::showKnowledge()
{
    LOG4CXX_INFO(logger, "Interpreter knowledge ..."); 
    
    // for each topic show talker knowledge
    for (auto& x: mapTopicNames) 
    {
        std::string text = "\n* " + x.second + " topic *\n";
        int topicId = x.first;
        Talker* pTalker = getTopicTalker(topicId);
        if (pTalker != 0)
            text += pTalker->showKnowledge();        
        // missing talker
        else
            text += " no talker";
        
        LOG4CXX_INFO(logger, text);
    }    
    
}

}