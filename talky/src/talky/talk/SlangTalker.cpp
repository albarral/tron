/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <stdexcept>      // std::out_of_range

#include "talky/talk/SlangTalker.h"
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

void SlangTalker::processMessage(Message& oMessage, Command& oCommand)
{
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
            oMessage.setConceptValidity(true);

            // if quantity needed, process quantity
            if (pConcept->needsQuantity())
                processQuantity(oMessage, oCommand);
        }
        // missing concept
        else
        {
            LOG4CXX_WARN(logger, "SlangTalker: missing concept for " << oMessage.getConcept());
        }
    }
    // unknown concept 
    else
    {
        LOG4CXX_WARN(logger, "SlangTalker: unknown concept " << oMessage.getConcept());          
    }
}


void SlangTalker::buildMessage(Command& oCommand, Message& oMessage)
{
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
            oCommand.setConceptValidity(true);
                    
            // if quantity needed
            if (pConcept->needsQuantity())
                buildQuantity(oCommand, oMessage);
        }
        // missing concept
        else
            LOG4CXX_WARN(logger, "SlangTalker: missing concept for " << conceptName);        
    }
    // unknown concept
    else
        LOG4CXX_WARN(logger, "SlangTalker: unknown concept " << oCommand.getConcept());
}

void SlangTalker::processQuantity(Message& oMessage, Command& oCommand)
{
    // if message has quantity, interpret it
    if (oMessage.hasQuantity())
    {
        float quantity;

        // if quantity valid
        if (StringUtil::convert2Float(oMessage.getQuantity(), quantity))
        {
            // inform command quantity
            oCommand.setQuantity(quantity);
            oMessage.setQuantityValidity(true);
        }
        // invalid quantity
        else
            LOG4CXX_WARN(logger, "SlangTalker: invalid quantity " << oMessage.getQuantity());          
    }
    // missing quantity
    else
    {
        oMessage.setMissingFields();
        LOG4CXX_WARN(logger, "SlangTalker: missing quantity in message");
    }
}

void SlangTalker::buildQuantity(Command& oCommand, Message& oMessage)
{
    // if command has quantity
    if (oCommand.hasQuantity())
    {
        std::string quantity = std::to_string(oCommand.getQuantity());

        // inform message quantity (all values accepted)
        oMessage.setQuantity(quantity);
        oCommand.setQuantityValidity(true);
    }
    // missing quantity
    else
    {
        oCommand.setMissingFields();
        LOG4CXX_WARN(logger, "SlangTalker: missing quantity in command");
    }    
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
    std::string text;
            
    // for each concept
    for (auto& x: mapConcepts) 
    {
        text += x.second.toString() + "\n";
    }    

    return text;
}

}