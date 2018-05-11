#ifndef __TRON_UTIL_GROUP_H
#define __TRON_UTIL_GROUP_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <vector>

#include "tron/util/groups/Element.h"

namespace tron
{
// Base class definition of a group of elements.    
// A group is itself an element. 
class Group : public Element 
{
protected:
    std::vector<Element> listElements; 

public:
    Group();
    Group(int id);
    Group(int id, std::string name);
    Group(int id, std::string name, int nature);
    ~Group ();
    
    void clear();
    void addElement(Element& oElement);
    std::vector<Element>& getElements() {return listElements;};
    int getNumElements() {return listElements.size();};    

    virtual std::string toString();
};

}  

#endif
