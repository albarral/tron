/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "talky/base/Topic.h"

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
}

void Topic::addCategory(Category& oCategory)
{
    oCategory.setTopicId(topic);
    
    listCategories.push_back(oCategory);    
}

void Topic::applyLanguage(Language& oLanguage)
{        
    std::string categoryName;
    // for each topic category
    for (Category& oCategory : listCategories)
    {        
        // get its associated slang
        Slang* pSlang = oLanguage.getCategorySlang(oCategory.getId());
        // and its category name 
        categoryName = oLanguage.getCategoryName(oCategory.getId());
        // if both exist
        if (pSlang != 0 && !categoryName.empty())
        {
            // set category name
            oCategory.setName(categoryName);
            // and apply the slang to the category 
            oCategory.applySlang(*pSlang);
        }
    }    
}

}