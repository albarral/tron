#ifndef __TALKY_CATEGORY_H
#define __TALKY_CATEGORY_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <vector>
#include <string>

#include "talky/base/Concept.h"
#include "talky/base/ConceptInfo.h"
#include "talky/base/Slang.h"

namespace talky
{
/** 
 * Base class used to represent a topic category. It holds the list of concepts of that category.
 */
class Category
{    
protected:
    int topic;                /*! category's topic  */
    int categoryId;       /*! category id */
    std::string name;    /*! category name */    
    std::vector<Concept> listConcepts;      /*! list of concepts of the category */
    
public:
    Category(int topic, int id, std::string name);              	
    ~Category();

    int getTopic() {return topic;};
    int getId() {return categoryId;};
    std::string getName() {return name;};
    std::vector<Concept>& getListConcepts() {return listConcepts;};
        
    // builds a category using the given list of concepts and its associated slang
    void build(std::vector<ConceptInfo>& listConceptsInfo, Slang& oSlang);

    std::string toString();
};
}
#endif
