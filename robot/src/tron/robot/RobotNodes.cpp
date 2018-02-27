/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/robot/RobotNodes.h"

namespace tron
{
// node names
const std::string RobotNodes::ARM_NODE = "arm";    
const std::string RobotNodes::HAND_NODE = "hand";    
const std::string RobotNodes::VISION_NODE = "vision";    
const std::string RobotNodes::HEAD_NODE = "head";    
const std::string RobotNodes::WHEELS_NODE = "wheels";     
const std::string RobotNodes::BODYROLE_NODE = "body";     

std::string RobotNodes::getNodeName(int nodeId)
{
    switch (nodeId)
    {
        case eNODE_ARM:
            return ARM_NODE;
            break;
            
        case eNODE_HAND:
            return HAND_NODE;
            break;

        case eNODE_VISION:
            return VISION_NODE;
            break;

        case eNODE_HEAD:
            return HEAD_NODE;
            break;

        case eNODE_WHEELS:
            return WHEELS_NODE;
            break;

        case eNODE_BODYROLE:
            return BODYROLE_NODE;
            break;

        default:
            // return empty name for undefined nodes
            return "";
    }    
}

}