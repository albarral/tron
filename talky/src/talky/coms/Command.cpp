/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "talky/coms/Command.h"
#include "talky/Topics.h"

namespace talky
{
Command::Command()
{
    resetFields();
}

Command::Command(int topic, int category, int concept)
{
    setTopic(topic);
    setCategory(category); 
    setConcept(concept);
}

Command::Command(int topic, int category, int concept, float quantity) : Command(topic, category, concept) 
{
    setQuantity(quantity);
}

void Command::reset()
{
    resetFields();
    resetFlags();        
}

void Command::resetFields()
{
    topic = category = concept = quantity = Topics::INVALID_VALUE;    
}

void Command::setTopic(int value)
{
    topic = value;
    setTopicPresence(value != Topics::INVALID_VALUE);
}    

void Command::setCategory(int value)
{
    category = value;
    setCategoryPresence(value != Topics::INVALID_VALUE);
}    

void Command::setConcept(int value)
{
    concept = value;
    setConceptPresence(value != Topics::INVALID_VALUE);
}    

void Command::setQuantity(float value)
{ 
    quantity = value;  
    setQuantityPresence(true); // quantity field must accept any value 
}    

std::string Command::toString()
{
    std::string desc = "[Command] topic: " + std::to_string(topic) + ", category: " + std::to_string(category) + 
            ", concept: " + std::to_string(concept) + ", quantity: " + std::to_string(quantity);

    return desc;
}    
}