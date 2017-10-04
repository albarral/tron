/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <stdexcept>      // std::out_of_range

#include "talky/language/Slang.h"

namespace talky
{
Slang::Slang()
{
}

Slang::~Slang()
{
    reset();
}

void Slang::reset()
{
    category = -1;
    mapWords.clear();
}

void Slang::setCategory(int category)
{
    this->category = category;    
}

std::string Slang::getConceptName(int concept)
{
    try 
    {
        return (mapWords.at(concept));
    }
    // if key not found, return empty name
    catch (const std::out_of_range& oor) 
    {
        return "";
    }    
    
}

void Slang::addWord(int concept, std::string name)
{
    mapWords.emplace(concept, name);
}

std::string Slang::toString()
{
    std::string text = "[Slang] " + std::to_string(category) + "\n"; 
    // show all words    
    for (auto& x: mapWords) 
    {
        text += "concept " + std::to_string(x.first) + ": " + x.second + "\n";
    }

    return text;
}

}