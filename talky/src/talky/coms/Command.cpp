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

Command::Command(int topic, int category, int concept)
{
    status = Command::eCMD_INCOMPLETE;
    setTopic(topic);
    setCategory(category); 
    setConcept(concept);
    
    // all mandatory fields set
    if (bhasTopic && bhasCategory && bhasConcept)
        status = Command::eCMD_COMPLETE_SIMPLE;
    
}

Command::Command(int topic, int category, int concept, int val) : Command(topic, category, concept) 
{
    setValue(val);
    
    // all fields set
    if (bhasValue)
        status = Command::eCMD_COMPLETE_EXTENDED;
}

void Command::resetFields()
{
    topic = category = concept = value = INVALID_VALUE;    
    bhasTopic = bhasCategory = bhasConcept = bhasValue = false;
    status = Command::eCMD_INCOMPLETE;
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

void Command::checkFields()
{
    // all mandatory fields set
    if (bhasTopic && bhasCategory && bhasConcept)
    {
        status = Command::eCMD_COMPLETE_SIMPLE;
        // all fields set
        if (bhasValue)
            status = Command::eCMD_COMPLETE_EXTENDED;
    }
}

bool Command::isCommandComplete()
{
    // command is considered complete if it has at least the mandatory fields
    return (status == Command::eCMD_COMPLETE_SIMPLE || 
            status == Command::eCMD_COMPLETE_EXTENDED);
}

bool Command::isCommandProcessed()
{
    return (status == Command::eCMD_PROCESSED_OK);
}

std::string Command::toString()
{
    std::string desc = "[Command] topic: " + std::to_string(topic) + ", category: " + std::to_string(category) + 
            ", concept: " + std::to_string(concept) + ", value: " + std::to_string(value);

    return desc;
}    
}