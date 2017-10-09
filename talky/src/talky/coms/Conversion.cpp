/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "talky/coms/Conversion.h"
#include "talky/coms/StringUtil.h"
#include "talky/Topics.h"

namespace talky
{
Conversion::Conversion()
{
    resetPresenceFlags();
    resetValidityFlags();
}

void Conversion::resetPresenceFlags()
{
    bhasTopic = bhasCategory = bhasConcept = bhasValue = false;
    numFieldsPresent = 0;
}

void Conversion::resetValidityFlags()
{
    bvalidTopic = bvalidCategory = bvalidConcept = bvalidValue = false;
    numFieldsInterpreted = numFieldsMissing = 0;
}

void Conversion::setTopicPresence(bool val)
{
    // control present fields
    if (!bhasTopic && val)
        numFieldsPresent++;

    bhasTopic = val;
}    

void Conversion::setCategoryPresence(bool val)
{
    // control present fields
    if (!bhasCategory && val)
        numFieldsPresent++;

    bhasCategory = val;
}    

void Conversion::setConceptPresence(bool val)
{
    // control present fields
    if (!bhasConcept && val)
        numFieldsPresent++;

    bhasConcept = val;
}    

void Conversion::setValuePresence(bool val)
{
    // control present fields
    if (!bhasValue && val)
        numFieldsPresent++;

    bhasValue = val;
}    

void Conversion::setTopicValidity(bool val)
{
    // control interpreted fields
    if (!bvalidTopic && val)
        numFieldsInterpreted++;
        
    bvalidTopic = val;        
}    

void Conversion::setCategoryValidity(bool val)
{
    // control interpreted fields
    if (!bvalidCategory && val)
        numFieldsInterpreted++;
        
    bvalidCategory = val;        
}    

void Conversion::setConceptValidity(bool val)
{
    // control interpreted fields
    if (!bvalidConcept && val)
        numFieldsInterpreted++;
        
    bvalidConcept = val;        
}    

void Conversion::setValueValidity(bool val)
{
    // control interpreted fields
    if (!bvalidValue)
    { 
        if (val)
            numFieldsInterpreted++;
        else
            numFieldsMissing++;
    }
        
    bvalidValue = val;        
}    


bool Conversion::isComplete()
{
    // message is considered complete if it has at least the mandatory fields
    return (numFieldsPresent >= Topics::MIN_COMMAND_FIELDS &&  
               numFieldsPresent <= Topics::MAX_COMMAND_FIELDS);
}

bool Conversion::isInterpreted()
{
    return (isComplete() && numFieldsInterpreted == numFieldsPresent && numFieldsMissing == 0);
}

std::string Conversion::toStringValidity()
{
    std::string desc = "[Conversion validity] topic: " + StringUtil::getBooleanValue(bvalidTopic) + ", category: " + StringUtil::getBooleanValue(bvalidCategory) + 
            ", concept: " + StringUtil::getBooleanValue(bvalidConcept) + ", value: " + StringUtil::getBooleanValue(bvalidValue);
    
    return desc;
}    
}