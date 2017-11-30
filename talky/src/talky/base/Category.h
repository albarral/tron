#ifndef __TALKY_CATEGORY_H
#define __TALKY_CATEGORY_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <vector>
#include <string>

#include "talky/base/Concept.h"
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
    int id;                    /*! category id */
    std::string name;    /*! category name */    
    std::vector<Concept> listConcepts;      /*! list of concepts of the category */
    
public:
    ~Category();

    void setTopicId(int value) {topic = value;};
    void setId(int value) {id = value;};
    void setName(std::string value) {name = value;};
    
    int getTopic() {return topic;};    
    int getId() {return id;};
    std::string getName() {return name;};
    
    void addConcept(Concept& oConcept);
    std::vector<Concept>& getListConcepts() {return listConcepts;};
        
    // apply the given slang to the category (setting all concept names)
    void applySlang(Slang& oSlang);
    
    // utility function to find a value in a list, returns true if found
    static bool findValueInList(int value, std::vector<int>& list);
    
    std::string toString();
};
}
#endif
