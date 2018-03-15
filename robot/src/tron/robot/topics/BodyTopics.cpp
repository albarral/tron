/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/robot/topics/BodyTopics.h"

namespace tron
{    
const std::string BodyTopics::BODY_COMFORTABLE = "comfort";
const std::string BodyTopics::BODY_EXPRESSIVE = "express";
const std::string BodyTopics::BODY_ARTISTIC = "art";
const std::string BodyTopics::BODY_EXTRA = "extra";    

BodyTopics::BodyTopics()
{
    fillMap();
}

void BodyTopics::fillMap()
{
    // build topics map
    //oTopicsMap.addCode(eBODY_COMFORTABLE, BODY_COMFORTABLE);  // uncontrollable behaviour
    oTopicsMap.addCode(eBODY_EXPRESSIVE, BODY_EXPRESSIVE);
    oTopicsMap.addCode(eBODY_ARTISTIC, BODY_ARTISTIC);
    oTopicsMap.addCode(eBODY_EXTRA, BODY_EXTRA);
}

}