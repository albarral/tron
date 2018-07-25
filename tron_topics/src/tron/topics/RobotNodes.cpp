/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/topics/RobotNodes.h"

namespace tron
{    
// node names
const std::string RobotNodes::ARM_NODE = "arm";    
const std::string RobotNodes::HAND_NODE = "hand";    
const std::string RobotNodes::VISION_NODE = "vision";    
const std::string RobotNodes::HEAD_NODE = "head";    
const std::string RobotNodes::WHEELS_NODE = "wheels";     
const std::string RobotNodes::BODYROLE_NODE = "body";     

std::string RobotNodes::getName4Node(int node)
{
    switch (node)
    {
        case eNODE_ARM:
            return ARM_NODE;
        case eNODE_HAND:
            return HAND_NODE;
        case eNODE_VISION:
            return VISION_NODE;
        case eNODE_HEAD:
            return HEAD_NODE;
        case eNODE_WHEELS:
            return WHEELS_NODE;
        case eNODE_BODYROLE:
            return BODYROLE_NODE;
            
        default: 
            return "undefined node";
    }
}

std::string RobotNodes::toString()
{
    std::string desc = "RobotNodes: \n"; 
    for (int i=0; i<eNODE_DIM; i++)
        desc += "node " + std::to_string(i) + ": " + getName4Node(i) + "\n";

    return desc;
}

}