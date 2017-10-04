/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <stdexcept>      // std::out_of_range

#include "talky/coms/Interpreter.h"
#include "talky/concept/ArmTopic.h"
#include "talky/language/ArmLanguage.h"
#include "talky/talk/TalkTopic.h"
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
}

void Interpreter::addLanguage(int topicId)
{
    bool bvalidTopic = false;
    
    // get topic name 
    std::string topicName = Topics::getTopicName(topicId);
    // and create an empty talk topic 
    TalkTopic oTalkTopic(topicId, topicName);
    
    // tune the talk topic for the specified topic and language 
    switch (topicId)
    {
        case Topics::eTOPIC_ARM:
            // build arm topic
            ArmTopic oArmTopic;
            oArmTopic.build();
            // build arm language
            ArmLanguage oArmLanguage;            
            oArmLanguage.build();
            // join both to form the arm talk topic
            oTalkTopic.build(oArmTopic, oArmLanguage);            
            bvalidTopic = true;
            break;            
    }
    
    // if talk topic created
    if (bvalidTopic)
    {
        // create talker for topic
        Talker oTalker;
        oTalker.build(oTalkTopic);
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
    bool bprocessed = false;
    // reset command
    oCommand.resetFields();
 
    // analyze message (obtain fields)
    oMessage.splitMessage(text);

    // if message complete
    if (checkMessageComplete())
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

                bprocessed = pTalker->processMessage(oMessage, oCommand);        
            }
            // missing talker
            else
                LOG4CXX_WARN(logger, "Interpreter: missing talker for topic " << oMessage.getTopic());
        }
        // unknown topic
        else
            LOG4CXX_WARN(logger, "Interpreter: unknown topic " << oMessage.getTopic());
    }   
    // incomplete message
    else
        LOG4CXX_WARN(logger, "Interpreter: incomplete message " << text);          
    
    return bprocessed;
}


bool Interpreter::checkMessageComplete()
{
    // checks that message has all fields
    return (oMessage.hasTopic() && oMessage.hasCategory() && oMessage.hasConcept() && oMessage.hasValue());
}


bool Interpreter::buildMessage(Command& oCommandOut)
{
    bool bcomposed = false;
    // reset message
    oMessage.resetFields();
    
    // get topic name 
    std::string topicName = getTopicName(oCommandOut.getTopic());

    // if known topic
    if (!topicName.empty())
    {
        // get topic talker 
        Talker* pTalker = getTopicTalker(oCommandOut.getTopic());

        // if talker found, compose rest of message                 
        if (pTalker != 0)
        {
            // inform message topic
            oMessage.setTopic(topicName);

            bcomposed = pTalker->buildMessage(oCommandOut, oMessage);        
        }
        // missing talker
        else
            LOG4CXX_WARN(logger, "Interpreter: missing talker for topic " << topicName);        
    }
    // unknown topic
    else
        LOG4CXX_WARN(logger, "Interpreter: unknown topic " << oCommandOut.getTopic());

    return bcomposed;
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

}