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
    resetFlags();
}

void Conversion::resetFlags()
{
    resetPresenceFlags();
    resetValidityFlags();    
}

void Conversion::resetPresenceFlags()
{
    bhasTopic = bhasCategory = bhasConcept = bhasQuantity = false;
    numFieldsPresent = 0;
    bmissingFields = false;
}

void Conversion::resetValidityFlags()
{
    bvalidTopic = bvalidCategory = bvalidConcept = bvalidQuantity = false;
    numFieldsInterpreted = 0;
}

void Conversion::setTopicPresence(bool value)
{
    // update present fields counter
    if (!bhasTopic && value)
        numFieldsPresent++;

    bhasTopic = value;
}    

void Conversion::setCategoryPresence(bool value)
{
    // update present fields counter
    if (!bhasCategory && value)
        numFieldsPresent++;

    bhasCategory = value;
}    

void Conversion::setConceptPresence(bool value)
{
    // update present fields counter
    if (!bhasConcept && value)
        numFieldsPresent++;

    bhasConcept = value;
}    

void Conversion::setQuantityPresence(bool value)
{
    // update present fields counter
    if (!bhasQuantity && value)
        numFieldsPresent++;

    bhasQuantity = value;
}    

void Conversion::setTopicValidity(bool value)
{
    // update interpreted fields counter
    if (!bvalidTopic && value)
        numFieldsInterpreted++;
        
    bvalidTopic = value;        
}    

void Conversion::setCategoryValidity(bool value)
{
    // update interpreted fields counter
    if (!bvalidCategory && value)
        numFieldsInterpreted++;
        
    bvalidCategory = value;        
}    

void Conversion::setConceptValidity(bool value)
{
    // update interpreted fields counter
    if (!bvalidConcept && value)
        numFieldsInterpreted++;
        
    bvalidConcept = value;        
}    

void Conversion::setQuantityValidity(bool value)
{
    // update interpreted fields counter
    if (!bvalidQuantity && value)
        numFieldsInterpreted++;
        
    bvalidQuantity = value;        
}    


bool Conversion::isComplete()
{
    // message is considered complete if it has at least the mandatory fields
    return (numFieldsPresent >= Topics::MIN_COMMAND_FIELDS &&  
               numFieldsPresent <= Topics::MAX_COMMAND_FIELDS);
}

bool Conversion::isInterpreted()
{
    // message is considered interpreted if all present fields have been interpreted and there are no missing fields
    return (isComplete() && numFieldsInterpreted == numFieldsPresent && !bmissingFields);
}

std::string Conversion::toStringValidity()
{
    std::string desc = "[Conversion validity] topic: " + StringUtil::getBooleanValue(bvalidTopic) + ", category: " + StringUtil::getBooleanValue(bvalidCategory) + 
            ", concept: " + StringUtil::getBooleanValue(bvalidConcept) + ", quantity: " + StringUtil::getBooleanValue(bvalidQuantity);
    
    return desc;
}    
}