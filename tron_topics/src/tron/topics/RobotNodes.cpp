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

RobotNodes::RobotNodes(int id, std::string name)
{
    this->ID = id;
    this->name = name;
}

std::string RobotNodes::getName4Node(int node)
{
    std::string tname;
    if (tron::CodeMap::getName4Code(node, tname))
        return tname;
    // return empty name if unknown node code
    else
        return ""; 
}

int RobotNodes::getCode4Node(std::string nodeName)
{
    int code;
    if (tron::CodeMap::getCode4Name(nodeName, code))
        return code;
    // return -1 if unknown node name
    else 
        return -1;
}

std::string RobotNodes::toString()
{
    return "RobotSystem: " + name + ", nodes:\n" + tron::CodeMap::toString();
}

}