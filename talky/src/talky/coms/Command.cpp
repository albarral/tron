/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "talky/coms/Command.h"


namespace talky
{
Command::Command()
{
    resetFields();
}

Command::Command(int topic, int category, int concept, int val)
{
    setTopic(topic);
    setCategory(category); 
    setConcept(concept);
    setValue(val);
}

void Command::resetFields()
{
    topic = category = concept = value = INVALID_VALUE;    
    bhasTopic = bhasCategory = bhasConcept = bhasValue = false;
}

void Command::setTopic(int val)
{
        topic = val;
        bhasTopic = (val != INVALID_VALUE);
}    

void Command::setCategory(int val)
{
        category = val;
        bhasCategory = (val != INVALID_VALUE);
}    

void Command::setConcept(int val)
{
        concept = val;
        bhasConcept = (val != INVALID_VALUE);
}    

void Command::setValue(int val)
{
        value = val;
        bhasValue = (val != INVALID_VALUE);
}    

std::string Command::toString()
{
    std::string desc = "[Command] topic: " + std::to_string(topic) + ", category: " + std::to_string(category) + 
            ", concept: " + std::to_string(concept) + ", value: " + std::to_string(value);

    return desc;
}    
}