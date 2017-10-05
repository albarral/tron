/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <stdexcept>      // std::out_of_range

#include "talky/base/Language.h"

namespace talky
{
Language::Language()
{
}

Language::~Language()
{
    reset();
}

void Language::reset()
{
    topic = -1;
    mapCategories.clear();
    mapSlangs.clear();    
}

void Language::setTopic(int topic)
{
    this->topic = topic;    
}

std::string Language::getCategoryName(int category)
{      
    try 
    {
        return (mapCategories.at(category));
    }
    // if key not found, return empty name
    catch (const std::out_of_range& oor) 
    {
        return "";
    }
}

Slang& Language::getCategorySlang(int category)
{
    try 
    {
        return (mapSlangs.at(category));
    }
    // if key not found, return dummy slang 
    catch (const std::out_of_range& oor) 
    {
        // dummy slang creation in heap
        Slang* pDummySlang = new Slang();
        return *pDummySlang;
    }        
}

void Language::addCategory(int category, std::string name)
{
    mapCategories.emplace(category, name);
}

void Language::addSlang(int category, Slang& oSlang)
{
    mapSlangs.emplace(category, oSlang);
}

std::string Language::toString()
{
    std::string text = "[Language] topic " + std::to_string(topic) + "\n"; 
    
    // show category names
    for (auto& x: mapCategories) 
    {
        text += "category " + std::to_string(x.first) + ": " + x.second + "\n";
    }
    
    // and show all category slangs
    for (auto& y: mapSlangs) 
       text += y.second.toString() + "\n";
    
    return text;
}

}