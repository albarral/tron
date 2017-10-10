/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "talky/base/Category.h"

namespace talky
{

Category::~Category()
{
    listConcepts.clear();
}

void Category::addConcept(Concept& oConcept)
{
    oConcept.setTopicId(topic);
    oConcept.setCategory(id);
    
    listConcepts.push_back(oConcept);    
}


void Category::applySlang(Slang& oSlang)
{
    std::string conceptName;
    // for each concept 
    for (Concept& oConcept : listConcepts)
    {
        // search its name (from the slang)
        conceptName = oSlang.getConceptName(oConcept.getMeaning());
        // if found, assign name to concept
        if (!conceptName.empty())
        {
            oConcept.setName(conceptName);
        }
    }    
}


std::string Category::toString()
{
    std::string text = "[Category] " + name + ", topic: " + std::to_string(topic) + ", id: " + std::to_string(id) + "\n"; 
    // and show all concepts
    for (Concept& oConcept : listConcepts) 
       text += oConcept.toString() + "\n";
    
    return text;
}

}