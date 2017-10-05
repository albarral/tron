#ifndef __TALKY_TOPIC_H
#define __TALKY_TOPIC_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <map>
#include <vector>

#include "talky/base/ConceptInfo.h"

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
    std::vector<int> listCategories;     /*! list of categories */    
    std::map<int, std::vector<ConceptInfo>> mapConcepts;     /*! map of concepts divided by categories */
    
public:
    Topic();              	
    ~Topic();

    void reset();    
    // set represented topic
    void setTopic(int topic);
    int getTopic() {return topic;}; 
    
    std::vector<int>& getListCategories() {return listCategories;};
    std::map<int, std::vector<ConceptInfo>>& getMapConcepts() {return mapConcepts;};
    
    //get concepts of given category
    std::vector<ConceptInfo>& getCategoryConcepts(int category);
    
protected:
    // add category to topic
    void addCategory(int category, std::vector<ConceptInfo>& listConcepts);    
};
}
#endif
