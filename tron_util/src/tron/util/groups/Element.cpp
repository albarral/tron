/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/util/groups/Element.h"

namespace tron
{
Element::Element()
{          
    this->id = -1;
    this->name = "";
    type = Element::eTYPE_ELEMENT;
    group = -1;
}

Element::Element(int id, std::string name)
{          
    this->id = id;
    this->name = name;
    type = Element::eTYPE_ELEMENT;
    group = -1;
}

//Element::~Element ()
//{
//}

std::string Element::toString()
{
    std::string text = getTypeName(type) + " id=" + std::to_string(id)  + ", name=" + name + ", group=" + std::to_string(group);    
    return text;    
}

std::string Element::getTypeName(int type)
{
    switch (type)
    {
        case eTYPE_ELEMENT:
            return "element";
            break;
        case eTYPE_GROUP:
            return "group";
            break;
        case eTYPE_SUPERGROUP:
            return "supergroup";
            break;
        default: 
            return "invalid";
    }    
}

}




