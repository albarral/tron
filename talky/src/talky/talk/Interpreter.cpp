/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <stdexcept>      // std::out_of_range

#include "talky/talk/Interpreter.h"
#include "talky/topics/ArmTopic.h"
#include "talky/languages/ArmLanguage.h"
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
    // create talker for topic
    Talker oTalker;
    
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
            // apply language to topic
            oArmTopic.applyLanguage(oArmLanguage);            
            // apply topic to talker
            oTalker.build(oArmTopic);
            bvalidTopic = true;
            break;            
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
    // reset command
    oCommand.reset();
 
    // set raw message text and analyze its structure
    oMessage.setRawText(text);
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
        LOG4CXX_WARN(logger, "Interpreter: incomplete message " << text);          
    
    return oMessage.isInterpreted();
}


bool Interpreter::buildMessage(Command& oCommandOut)
{
    // reset message    
    oMessage.reset();
    
    // and reset command validity
    oCommandOut.resetValidityFlags();
            
    // if command complete
    if (oCommandOut.isComplete())
    {
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
                oCommandOut.setTopicValidity(true);

                pTalker->buildMessage(oCommandOut, oMessage);        
                // compose message
                oMessage.composeMessage();
            }
            // missing talker
            else
                LOG4CXX_WARN(logger, "Interpreter: missing talker for topic " << topicName);        
        }
        // unknown topic
        else
            LOG4CXX_WARN(logger, "Interpreter: unknown topic " << oCommandOut.getTopic());                
    }   
    // incomplete command
    else
        LOG4CXX_WARN(logger, "Interpreter: incomplete command " << oCommandOut.toString());          

    return oCommandOut.isInterpreted();
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