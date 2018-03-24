/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/language/Theme.h"

namespace tron
{
Theme::Theme()
{
    category = -1;
//    id = -1;
    name = "?";
}

Theme::Theme(int category, std::string name)
{
    this->category = category;
//    this->id = id;
    this->name = name;
}

//Theme::~Theme()
//{
//}


std::string Theme::toString()
{
    return "Theme [name = " + name + ", category= " + std::to_string(category) + "] codes: \n" + tuly::CodeMap::toString();
}

}