/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/topics/RobotNodes.h"

namespace tron
{    
RobotNodes::RobotNodes()
{
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
    // return empty name if unknown code
    else
        return ""; 
}

int RobotNodes::getNode4Name(std::string name)
{
    int code;
    if (oNodesMap.getCode4Name(name, code))
        return code;
    // return invalid code if unknown name
    else 
        return -1;
}

std::string RobotNodes::toString()
{
    std::string desc = "RobotNodes: \n" + oNodesMap.toString();
    return desc;
}

}