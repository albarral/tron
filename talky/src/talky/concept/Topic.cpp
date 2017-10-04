/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "talky/concept/Topic.h"

namespace talky
{
Topic::Topic()
{
}

Topic::~Topic()
{
    reset();
}

void Topic::reset()
{
    topic = -1;
    listCategories.clear();
    mapConcepts.clear();    
}

void Topic::setTopic(int topic)
{
    this->topic = topic;    
}

void Topic::addCategory(int category, std::vector<ConceptInfo>& listConcepts)
{    
    // add category
    listCategories.push_back(category);
    // add category concepts
    mapConcepts.emplace(category, listConcepts);
}

std::vector<ConceptInfo>& Topic::getCategoryConcepts(int category)
{
    try 
    {
        return (mapConcepts.at(category));
    }
    // if key not found, return dummy slang 
    catch (const std::out_of_range& oor) 
    {
        // dummy list of concepts
        std::vector<ConceptInfo>* pDummyList = new std::vector<ConceptInfo>();
        return *pDummyList;
    }            
}
}