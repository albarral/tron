#ifndef __TALKY_TALKTOPIC_H
#define __TALKY_TALKTOPIC_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <vector>
#include <string>

#include "talky/base/Category.h"
#include "talky/base/Topic.h"
#include "talky/base/Language.h"

namespace talky
{
/** 
 * Base class used to represent a talking topic. 
 * Tool to communicate about a conceptual topic by means of a language.
 * It uses those categories defined in the topic.
 */
class TalkTopic
{    
protected:
    int topicId;       /*! topic id */
    std::string name;    /*! topic's name */    
    std::vector<Category> listCategories;      /*! list of categories of the topic */
    
public:
    TalkTopic(int id, std::string name);              	
    ~TalkTopic();

    int getTopicId() {return topicId;};
    std::string getName() {return name;};
    std::vector<Category>& getListCategories() {return listCategories;};
    
    // builds a talk topic using the given conceptual topic and its associated language
    void build(Topic& oTopic, Language& oLanguage);    

    std::string toString();
};
}
#endif
