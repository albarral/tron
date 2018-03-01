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

RobotNodes::RobotNodes()
{
    // build nodes map
    oNodesMap.addCode(eNODE_ARM, ARM_NODE);
    oNodesMap.addCode(eNODE_HAND, HAND_NODE);
    oNodesMap.addCode(eNODE_VISION, VISION_NODE);
    oNodesMap.addCode(eNODE_HEAD, HEAD_NODE);
    oNodesMap.addCode(eNODE_WHEELS, WHEELS_NODE);
    oNodesMap.addCode(eNODE_BODYROLE, BODYROLE_NODE);
}

std::string RobotNodes::getName4Node(int node)
{
    std::string name;
    if (oNodesMap.getName4Code(node, name))
        return name;
    // return empty name if unknown node
    else
        return ""; 
}

int RobotNodes::getCode4Node(std::string nodeName)
{
    int code;
    if (oNodesMap.getCode4Name(nodeName, code))
        return code;
    // return -1 if unknown node
    else 
        return -1;
}
}