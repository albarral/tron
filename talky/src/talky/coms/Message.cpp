/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "talky/coms/Message.h"
#include "talky/coms/StringUtil.h"

namespace talky
{
Message::Message()
{
    resetFields();
}

Message::Message(std::string topic, std::string category, std::string concept, std::string value)
{
    setTopic(topic);
    setCategory(category); 
    setConcept(concept);
    setValue(value);
}

void Message::resetFields()
{
    topic = category = concept = value = "";    
    bhasTopic = bhasCategory = bhasConcept = bhasValue = false;
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
    rawText = topic + FIELD_SEPARATOR +
            category + FIELD_SEPARATOR +
            concept + FIELD_SEPARATOR +
            value; 
}

void Message::splitMessage(std::string text)
{
    resetFields();
    
    rawText = text;    
    
    // split raw text in tokens 
    std::vector<std::string> listTokens = StringUtil::split(text, FIELD_SEPARATOR); 
    int numFields = listTokens.size();

    // get topic field 
    if (numFields > ePOS_TOPIC)
        setTopic(listTokens.at(ePOS_TOPIC));            
    
    // get category field 
    if (numFields > ePOS_CATEGORY)
        setCategory(listTokens.at(ePOS_CATEGORY));
        
    // get concept field 
    if (numFields > ePOS_CONCEPT)
        setConcept(listTokens.at(ePOS_CONCEPT));

    // get value field 
    if (numFields > ePOS_VALUE)
        setValue(listTokens.at(ePOS_VALUE));
}

//void Message::toString()
//{
//    return "[Message] " + name + ", topic: " + std::to_string(topic) + ", category: " + std::to_string(category) + 
//            ", meaning: " + std::to_string(value) + ", needs value: " + std::to_string(bneedsValue);
//}    
}