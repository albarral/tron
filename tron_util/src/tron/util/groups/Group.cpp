/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/util/groups/Group.h"

namespace tron
{
Group::Group()
{          
    type = Element::eTYPE_GROUP;
}

Group::Group(int id, std::string name) : Element(id, name)
{          
    type = Element::eTYPE_GROUP;
}

Group::~Group ()
{
    clear();
}

void Group::clear()
{
    listElements.clear();    
}

void Group::addElement(Element& oElement)
{
    // when adding an element to the group, set the group id for the element
    oElement.setGroup(id);
    listElements.push_back(oElement);
}

std::string Group::toString()
{
    std::string text = "Group [" + Element::toString() + "]\n";
    for (Element& oElement : listElements)
    {
        text += oElement.toString() + "\n";        
    }
    
    return text;    
}

}




