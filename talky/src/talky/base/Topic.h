#ifndef __TALKY_TOPIC_H
#define __TALKY_TOPIC_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <map>
#include <vector>

#include "talky/base/Category.h"
#include "talky/base/Language.h"

namespace talky
{
/** 
 * Base class used to represent a topic conceptually. 
 * A topic is composed by concepts distributed by categories.
 */
class Topic
{    
protected:
    int topic;                                      /*! topic identifier */        
    std::vector<Category> listCategories;     /*! list of categories */        
    
public:
    Topic();              	
    ~Topic();

    void reset();    
    // set represented topic
    void setTopicId(int value) {topic = value;};
    int getTopic() {return topic;}; 
    
    // add category to topic
    void addCategory(Category& oCategory);    
    std::vector<Category>& getListCategories() {return listCategories;};

    // apply the given language to the topic (applying slangs to all categories)    
    void applyLanguage(Language& oLanguage);
};
}
#endif
