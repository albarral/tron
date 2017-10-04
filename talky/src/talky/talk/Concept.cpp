/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "talky/talk/Concept.h"

namespace talky
{
Concept::Concept(int topic, int category, int meaning, std::string name, bool bneedsValue)
{
    this->topic = topic;
    this->category = category; 
    this->meaning = meaning;
    this->name = name;
    this->bneedsValue = bneedsValue;
}

std::string Concept::toString()
{
    return "[Concept] " + name + ", topic: " + std::to_string(topic) + ", category: " + std::to_string(category) + 
            ", meaning: " + std::to_string(meaning) + ", needs value: " + std::to_string(bneedsValue);
}    
}