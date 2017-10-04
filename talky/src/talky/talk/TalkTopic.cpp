/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "talky/talk/TalkTopic.h"

namespace talky
{
TalkTopic::TalkTopic(int id, std::string name)
{
    this->topicId = id;
    this->name = name;
}

TalkTopic::~TalkTopic()
{
    listCategories.clear();
}


void TalkTopic::build(Topic& oTopic, Language& oLanguage) 
{        
    std::string categoryName;
    // for each topic category
    for (int categoryId : oTopic.getListCategories())
    {
        // get the category name (from the language)
        categoryName = oLanguage.getCategoryName(categoryId);
        // if exists, build the category and add it to the topic
        if (!categoryName.empty())
        {
            Category oCategory(topicId, categoryId, categoryName);
            // build it with all its conceptual concepts and its associated slang
            oCategory.build(oTopic.getCategoryConcepts(categoryId), oLanguage.getCategorySlang(categoryId));
            
            listCategories.push_back(oCategory);
        }
    }    
}

std::string TalkTopic::toString()
{
    std::string text = "[TalkTopic] " + name + ", id: " + std::to_string(topicId) + "\n"; 
    // and show all categories
    for (Category& oCategory : listCategories) 
       text += oCategory.toString() + "\n";
    
    return text;
}

}