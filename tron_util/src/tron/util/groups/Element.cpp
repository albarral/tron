/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/util/groups/Element.h"

namespace tron
{
Element::Element() : Element(-1, "", -1)
{          
}

Element::Element(int id) : Element(id, "", -1)
{          
}

Element::Element(int id, std::string name) : Element(id, name, -1)
{          
}

Element::Element(int id, std::string name, int nature)
{          
    this->id = id;
    this->name = name;
    type = Element::eTYPE_ELEMENT;
    group = -1;
    this->nature = nature;
}

//Element::~Element ()
//{
//}

std::string Element::toString()
{
    std::string text = "Element: id=" + std::to_string(id)  + ", name=" + name + ", group=" + std::to_string(group) + ", nature=" + std::to_string(nature);    
    return text;    
}

}




