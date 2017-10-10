/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "talky/base/Concept.h"

namespace talky
{
Concept::Concept(int topic, int category, int meaning, std::string name, bool bneedsQuantity)
{
    this->topic = topic;
    this->category = category; 
    this->meaning = meaning;
    this->name = name;
    this->bneedsQuantity = bneedsQuantity;
}

std::string Concept::toString()
{
    return "[Concept] " + name + ", topic: " + std::to_string(topic) + ", category: " + std::to_string(category) + 
            ", meaning: " + std::to_string(meaning) + ", needs quantity: " + std::to_string(bneedsQuantity);
}    
}