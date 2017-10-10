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
    setTopic(topic);
    setCategory(category); 
    setConcept(concept);
}

Message::Message(std::string topic, std::string category, std::string concept, std::string quantity) : Message(topic, category, concept) 
{
    setQuantity(quantity);
}

void Message::reset()
{
    resetFields();
    resetFlags();    
}

void Message::resetFields()
{
    // not the raw text
    topic = category = concept = quantity = "";   
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

void Message::setQuantity(std::string word)
{
    quantity = word;
    setQuantityPresence(!word.empty());
}    


void Message::composeMessage()
{
    rawText = topic + Topics::FIELD_SEPARATOR +
            category + Topics::FIELD_SEPARATOR +
            concept + Topics::FIELD_SEPARATOR +
            quantity; 
}

void Message::digestMessage()
{
    // first we reset the message (fields and flags)
    reset();
        
    // split raw text in tokens 
    std::vector<std::string> listTokens = StringUtil::split(rawText, Topics::FIELD_SEPARATOR); 
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
    if (numTokens > eFIELD_QUANTITY)
        setQuantity(listTokens.at(eFIELD_QUANTITY));
}

std::string Message::toString()
{
    std::string desc = "[Message] topic: " + topic + ", category: " + category + 
            ", concept: " + concept + ", quantity: " + quantity + ", raw text: " + rawText;
    
    return desc;
}    

}