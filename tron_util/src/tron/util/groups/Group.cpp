/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/util/groups/Group.h"

namespace tron
{
Group::Group() : Group(-1, "", -1)
{          
}

Group::Group(int id) : Group(id, "", -1)
{          
}

Group::Group(int id, std::string name) : Group(id, name, -1)
{          
}

Group::Group(int id, std::string name, int nature) : Element(id, name, nature)
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




