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
    resetFields();
    setTopic(topic);
    setCategory(category); 
    setConcept(concept);
}

Message::Message(std::string topic, std::string category, std::string concept, std::string value) : Message(topic, category, concept) 
{
    setValue(value);
}

void Message::resetFields()
{
    topic = category = concept = value = "";   
    resetPresenceFlags();
}

void Message::setTopic(std::string word)
{
    topic = word;
    setTopicPresence(!word.empty());
}    

void Message::setCategory(std::string word)
{
    category = word;    
    setCategoryPresence(!word.empty());
}    

void Message::setConcept(std::string word)
{
    concept = word;
    setConceptPresence(!word.empty());
}    

void Message::setValue(std::string word)
{
    value = word;
    setValuePresence(!word.empty());
}    


void Message::composeMessage()
{
    rawText = topic + Topics::FIELD_SEPARATOR +
            category + Topics::FIELD_SEPARATOR +
            concept + Topics::FIELD_SEPARATOR +
            value; 
}

void Message::splitFields(std::string text)
{
    resetFields();
    resetValidityFlags();
    
    rawText = text;    
    
    // split raw text in tokens 
    std::vector<std::string> listTokens = StringUtil::split(text, Topics::FIELD_SEPARATOR); 
    int numTokens = listTokens.size();

    // get topic field 
    if (numTokens > eFIELD_TOPIC)
        setTopic(listTokens.at(eFIELD_TOPIC));            
    
    // get category field 
    if (numTokens > eFIELD_CATEGORY)
        setCategory(listTokens.at(eFIELD_CATEGORY));
        
    // get concept field 
    if (numTokens > eFIELD_CONCEPT)
        setConcept(listTokens.at(eFIELD_CONCEPT));

    // get value field 
    if (numTokens > eFIELD_VALUE)
        setValue(listTokens.at(eFIELD_VALUE));
}

std::string Message::toString()
{
    std::string desc = "[Message] topic: " + topic + ", category: " + category + 
            ", concept: " + concept + ", value: " + value + ", raw text: " + rawText;
    
    return desc;
}    

}