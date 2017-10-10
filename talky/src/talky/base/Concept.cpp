/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "talky/base/Concept.h"

namespace talky
{
std::string Concept::toString()
{
    return "[Concept] " + name + ", topic: " + std::to_string(topic) + ", category: " + std::to_string(category) + 
            ", meaning: " + std::to_string(meaning) + ", needs quantity: " + std::to_string(bneedsQuantity);
}    
}