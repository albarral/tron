/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <stdexcept>      // std::out_of_range

#include "talky/coms/SlangTalker.h"
#include "talky/coms/StringUtil.h"
#include "talky/Topics.h"

using namespace log4cxx;

namespace talky
{
LoggerPtr SlangTalker::logger(Logger::getLogger("talky"));
    
SlangTalker::SlangTalker()
{
}

SlangTalker::~SlangTalker()
{
    reset();
}

void SlangTalker::reset()
{
    category = -1;
    mapConceptNumbers.clear();
    mapConceptNames.clear();
    mapConcepts.clear();
}

void SlangTalker::build(Category& oCategory)
{
    setCategory(oCategory.getId());
    
    // for each category concept, add it to maps
    for (Concept& oConcept : oCategory.getListConcepts())
    {        
        // add concept to maps
        mapConceptNumbers.emplace(oConcept.getName(), oConcept.getMeaning());    
        mapConceptNames.emplace(oConcept.getMeaning(), oConcept.getName());    
        // and add concept to slang talker
        mapConcepts.emplace(oConcept.getMeaning(), oConcept);
    }
}

bool SlangTalker::understandsConcept(std::string conceptName)
{
    return (mapConceptNumbers.find(conceptName) != mapConceptNumbers.end());
}

bool SlangTalker::processMessage(Message& oMessage, Command& oCommand)
{
    bool bprocessed = false;

    // interpret concept 
    int conceptId = getConceptNumber(oMessage.getConcept());

    // if known concept 
    if (conceptId != Topics::INVALID_VALUE)
    {
        // find corresponding concept
        Concept* pConcept = getTopicConcept(conceptId);

        // if concept found, interpret it
        if (pConcept != 0)
        {
            // inform command concept
            oCommand.setConcept(conceptId);

            // if extra value needed, process value
            if (pConcept->needsValue())
            {
                float value;
                
                // if value is valid
                if (StringUtil::convert2Float(oMessage.getValue(), value))
                {
                    // inform command value
                    oCommand.setValue(value);
                    // message processed ok
                    bprocessed = true;
                }
                // invalid value
                else
                    LOG4CXX_WARN(logger, "SlangTalker: invalid value " << oMessage.getValue());          
            }
            // if no extra value needed, message processed ok
            else
                bprocessed = true;                

            LOG4CXX_INFO(logger, "SlangTalker: message processed " << oMessage.getRawText());      
        }
        // missing concept
        else
            LOG4CXX_WARN(logger, "SlangTalker: missing concept for " << oMessage.getConcept());
    }
    // unknown concept 
    else
        LOG4CXX_WARN(logger, "SlangTalker: unknown concept " << oMessage.getConcept());          

    return bprocessed;
}


bool SlangTalker::buildMessage(Command& oCommand, Message& oMessage)
{
    bool bcomposed = false;
    
    // get concept name 
    std::string conceptName = getConceptName(oCommand.getConcept());

    // if known concept
    if (!conceptName.empty())
    {
        // find corresponding concept
        Concept* pConcept = getTopicConcept(oCommand.getConcept());

        // if concept found, interpret it
        if (pConcept != 0)
        {
            // inform message concept
            oMessage.setConcept(conceptName);            
                    
            // if extra value needed
            if (pConcept->needsValue())
            {
                std::string value = std::to_string(oCommand.getValue());

                // inform message value
                oMessage.setValue(value);
                // message composed ok           
                bcomposed = true;
            }
            // if no extra value needed, message composed ok            
            else
                bcomposed = true;
        }
        // missing concept
        else
            LOG4CXX_WARN(logger, "SlangTalker: missing concept for " << conceptName);        
    }
    // unknown concept
    else
        LOG4CXX_WARN(logger, "SlangTalker: unknown concept " << oCommand.getConcept());
    
    return bcomposed;    
}

int SlangTalker::getConceptNumber(std::string conceptName)
{
    try 
    {
        // get id of given concept name
        return mapConceptNumbers.at(conceptName);
    }
    // return invalid if not found
    catch (const std::out_of_range& oor) 
    {                
        return Topics::INVALID_VALUE;
    }            
}        

std::string SlangTalker::getConceptName(int conceptId)
{
    try 
    {
        // get name of given concept id
        return mapConceptNames.at(conceptId);
    }
    // return empty if not found
    catch (const std::out_of_range& oor) 
    {                
        return Topics::EMPTY_VALUE;
    }                
}

Concept* SlangTalker::getTopicConcept(int conceptId)
{
    try 
    {
        // get corresponding concept
        return &(mapConcepts.at(conceptId));
    }
    // if concept not found, return 0
    catch (const std::out_of_range& oor) 
    {                
        return 0;
    }            
}        

std::string SlangTalker::showKnowledge()
{
    std::string text = "SlangTalker knowledge ... \n"; 
            
    // for each concept
    for (auto& x: mapConcepts) 
    {
        text += x.second.toString() + "\n";
    }    

    return text;
}

}