/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <stdexcept>      // std::out_of_range

#include "talky/talk/Talker.h"
#include "talky/Topics.h"

using namespace log4cxx;

namespace talky
{
LoggerPtr Talker::logger(Logger::getLogger("talky"));
    
Talker::Talker()
{
}

Talker::~Talker()
{
    reset();
}

void Talker::reset()
{
    topic = -1;
    mapCategoryNumbers.clear();
    mapCategoryNames.clear();
    mapSlangTalkers.clear();
}

void Talker::build(TalkTopic& oTalkTopic)
{
    setTopic(oTalkTopic.getTopicId());

    SlangTalker oSlangTalker;   
    // for each topic category
    for (Category& oCategory : oTalkTopic.getListCategories())
    {        
        // create a slang talker 
        oSlangTalker.reset();
        oSlangTalker.build(oCategory);
        // add category to maps
        mapCategoryNumbers.emplace(oCategory.getName(), oCategory.getId());    
        mapCategoryNames.emplace(oCategory.getId(), oCategory.getName());    
        // and add slang talker to talker
        mapSlangTalkers.emplace(oCategory.getId(), oSlangTalker);
    }
}

bool Talker::understandsSlang(std::string categoryName)
{
    return (mapCategoryNumbers.find(categoryName) != mapCategoryNumbers.end());
}

void Talker::processMessage(Message& oMessage, Command& oCommand)
{
    // interpret category 
    int categoryId = getCategoryNumber(oMessage.getCategory());

    // if known category
    if (categoryId != Topics::INVALID_VALUE)
    {
        // get slang talker 
        SlangTalker* pSlangTalker = getCategorySlangTalker(categoryId);

        // if slang talker found, interpret rest of message                 
        if (pSlangTalker != 0)
        {
            // inform command category
            oCommand.setCategory(categoryId);
            oMessage.setCategoryValidity(true);
            
            pSlangTalker->processMessage(oMessage, oCommand);        
        }
        // missing slang talker
        else
        {
            LOG4CXX_WARN(logger, "Talker: missing slang talker for category " << oMessage.getCategory());
        }
    }
    // unknown category
    else
    {
        LOG4CXX_WARN(logger, "Talker: unknown category " << oMessage.getCategory());
    }
}


void Talker::buildMessage(Command& oCommand, Message& oMessage)
{
    // get category name 
    std::string categoryName = getCategoryName(oCommand.getCategory());

    // if known category
    if (!categoryName.empty())
    {
        // get slang talker 
        SlangTalker* pSlangTalker = getCategorySlangTalker(oCommand.getCategory());

        // if slang talker found, compose rest of message                 
        if (pSlangTalker != 0)
        {
            // inform message category
            oMessage.setCategory(categoryName);
            oCommand.setCategoryValidity(true);
            
            pSlangTalker->buildMessage(oCommand, oMessage);        
        }
        // missing slang talker
        else
            LOG4CXX_WARN(logger, "Talker: missing slang talker for category " << categoryName);        
    }
    // unknown category
    else
        LOG4CXX_WARN(logger, "Talker: unknown category " << oCommand.getCategory());
}


int Talker::getCategoryNumber(std::string categoryName)
{
    try 
    {
        // get id of given category name
        return mapCategoryNumbers.at(categoryName);
    }
    // return invalid if not found
    catch (const std::out_of_range& oor) 
    {                
        return Topics::INVALID_VALUE;
    }            
}        

std::string Talker::getCategoryName(int categoryId)
{
    try 
    {
        // get name of given category id
        return mapCategoryNames.at(categoryId);
    }
    // return empty if not found
    catch (const std::out_of_range& oor) 
    {                
        return Topics::EMPTY_VALUE;
    }                
}

SlangTalker* Talker::getCategorySlangTalker(int categoryId)
{
    try 
    {
        // get slang talker for given category
        return &(mapSlangTalkers.at(categoryId));
    }
    // return 0 if not found
    catch (const std::out_of_range& oor) 
    {                
        return 0;
    }            
}        

std::string Talker::showKnowledge()
{
    std::string text;
            
    // for each category show slang talker knowledge
    for (auto& x: mapCategoryNames) 
    {
        text += "\n- " + x.second + " category: \n";
        int categoryId = x.first;
        // get slang talker 
        SlangTalker* pSlangTalker = getCategorySlangTalker(categoryId);
        if (pSlangTalker != 0)
            text += pSlangTalker->showKnowledge();               
        // missing talker
        else
            text += " no slang talker \n";
    }    

    return text;
}

}