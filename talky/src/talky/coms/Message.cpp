/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "talky/coms/Message.h"
#include "talky/coms/StringUtil.h"
#include "talky/Topics.h"

namespace talky
{
Message::Message()
{
    resetFields();
}

// mandatory fields constructor
Message::Message(std::string topic, std::string category, std::string concept) 
{
    status = Message::eSTATE_INCOMPLETE;
    setTopic(topic);
    setCategory(category); 
    setConcept(concept);
    
    // all mandatory fields set
    if (bhasTopic && bhasCategory && bhasConcept)
        status = Message::eSTATE_COMPLETE_SIMPLE;
}

Message::Message(std::string topic, std::string category, std::string concept, std::string value) : Message(topic, category, concept) 
{
    setValue(value);

    // all fields set
    if (bhasValue)
        status = Message::eSTATE_COMPLETE_EXTENDED;
}

void Message::resetFields()
{
    topic = category = concept = value = "";    
    bhasTopic = bhasCategory = bhasConcept = bhasValue = false;
    status = Message::eSTATE_INCOMPLETE;
}

void Message::setTopic(std::string word)
{
        topic = word;
        bhasTopic = !word.empty();
}    

void Message::setCategory(std::string word)
{
        category = word;
        bhasCategory = !word.empty();
}    

void Message::setConcept(std::string word)
{
        concept = word;
        bhasConcept = !word.empty();
}    

void Message::setValue(std::string word)
{
        value = word;
        bhasValue = !word.empty();
}    

void Message::composeMessage()
{
    rawText = topic + Topics::FIELD_SEPARATOR +
            category + Topics::FIELD_SEPARATOR +
            concept + Topics::FIELD_SEPARATOR +
            value; 
}

void Message::splitMessage(std::string text)
{
    resetFields();
    
    rawText = text;    
    
    // split raw text in tokens 
    std::vector<std::string> listTokens = StringUtil::split(text, Topics::FIELD_SEPARATOR); 
    int numFields = listTokens.size();

    // get topic field 
    if (numFields > eMSG_TOPIC)
        setTopic(listTokens.at(eMSG_TOPIC));            
    
    // get category field 
    if (numFields > eMSG_CATEGORY)
        setCategory(listTokens.at(eMSG_CATEGORY));
        
    // get concept field 
    if (numFields > eMSG_CONCEPT)
    {
        setConcept(listTokens.at(eMSG_CONCEPT));
        // all mandatory fields set
        if (bhasTopic && bhasCategory && bhasConcept)
            status = Message::eSTATE_COMPLETE_SIMPLE;
    }

    // get value field 
    if (numFields > eMSG_VALUE)
    {
        setValue(listTokens.at(eMSG_VALUE));
        // all fields set
        if (bhasValue)
            status = Message::eSTATE_COMPLETE_EXTENDED;
    }
}

bool Message::checkMessageComplete()
{
    // message is considered complete if it has at least the mandatory fields
    return (status == Message::eSTATE_COMPLETE_SIMPLE || 
            status == Message::eSTATE_COMPLETE_EXTENDED);
}

bool Message::checkMessageInterpreted()
{
    return (status == Message::eSTATE_INTERPRETED_OK);
}

std::string Message::toString()
{
    std::string desc = "[Message] topic: " + topic + ", category: " + category + 
            ", concept: " + concept + ", value: " + value + ", raw text: " + rawText;
    
    return desc;
}    
}