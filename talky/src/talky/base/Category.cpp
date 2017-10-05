/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "talky/base/Category.h"

namespace talky
{
Category::Category(int topic, int id, std::string name)
{
    this->topic = topic;
    this->categoryId = id;
    this->name = name;
}

Category::~Category()
{
    listConcepts.clear();
}

void Category::build(std::vector<ConceptInfo>& listConceptsInfo, Slang& oSlang)
{
    std::string conceptName;
    // for each concept info
    for (ConceptInfo conceptInfo : listConceptsInfo)
    {
        // get the concept name (from the slang)
        conceptName = oSlang.getConceptName(conceptInfo.conceptId);
        // if exists, create concept object and add to category
        if (!conceptName.empty())
        {
            Concept oConcept(topic, categoryId, conceptInfo.conceptId, conceptName, conceptInfo.bneedsValue);
            listConcepts.push_back(oConcept);
        }
    }    
}


std::string Category::toString()
{
    std::string text = "[Category] " + name + ", topic: " + std::to_string(topic) + ", id: " + std::to_string(categoryId) + "\n"; 
    // and show all concepts
    for (Concept& oConcept : listConcepts) 
       text += oConcept.toString() + "\n";
    
    return text;
}

}