/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron2/robot/common/ExtraTopic.h"
#include "tron2/robot/Node.h"

namespace tron2
{

ExtraTopic::ExtraTopic() : Topic(Node::eEXTRA_TOPIC, Node::EXTRA_TOPIC)
{
    fillConcepts();    
}

void ExtraTopic::fillConcepts()
{
    addCode(eEXTRA_STOP, EXTRA_STOP);
    addCode(eEXTRA_END, EXTRA_END);                         
}
}