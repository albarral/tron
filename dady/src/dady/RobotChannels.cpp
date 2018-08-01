/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "dady/RobotChannels.h"
#include "tron/topics/RobotNodes.h"
#include "tron/topics/Topic.h"
#include "amy/interface2/ArmNode.h"

namespace tron
{    
//RobotChannels::RobotChannels()
//{
//}

int RobotChannels::getCode4NodeSection(int node, std::string sectionName)
{
    switch (node)
    {
        case RobotNodes::eNODE_ARM: 
        {
            amy::ArmNode2 oArmNode;
            return oArmNode.getSection4Name(sectionName);
        }
            break;
            
        case RobotNodes::eNODE_BODYROLE: 
            // TO DO
            return -1;
            break;
        
        case RobotNodes::eNODE_VISION: 
            // TO DO
            return -1;
        break;
        
        // unknown nodes
        default: 
            return -1;
    }    
}

NodeSection* RobotChannels::getNodeSection(int node, int section)
{
    switch (node)
    {
        case RobotNodes::eNODE_ARM: 
        {
            amy::ArmNode2 oArmNode;
            return oArmNode.getSection(section);
        }
            break;
            
        case RobotNodes::eNODE_BODYROLE: 
            // TO DO
            return nullptr;
            break;
        
        case RobotNodes::eNODE_VISION: 
            // TO DO
            return nullptr;
        break;
        
        // unknown nodes
        default: 
            return nullptr;
    }    
}

int RobotChannels::getCode4NodeSectionChannel(int node, int section, std::string channelName)
{        
    // get specific node section
    NodeSection* pNodeSection = getNodeSection(node, section);
    if (pNodeSection != nullptr)
        return pNodeSection->getChannel4Name(channelName); 
    // if section not found, return invalid channel
    else
        return -1;
}

std::string RobotChannels::showAvailableSections4Node(int node)
{
    switch (node)
    {
        case RobotNodes::eNODE_ARM: 
        {
            amy::ArmNode2 oArmNode;
            return oArmNode.toString();
        }            
        break;
            
        case RobotNodes::eNODE_BODYROLE: 
            // TO DO
            return "";
            break;
        
        case RobotNodes::eNODE_VISION: 
            // TO DO
            return "";
        break;
        
        // unknown nodes
        default: 
            return "unknown node";
    }        
}

std::string RobotChannels::showAvailableChannels4NodeSection(int node, int section)
{
    // get specific node section
    NodeSection* pNodeSection = getNodeSection(node, section);
    // if found, return its description
    if (pNodeSection != nullptr)
        return pNodeSection->toString();
    // unknown section
    else
        return "unknown section";
}

std::string RobotChannels::getTopic4NodeSectionChannel(int node, int section, int channel)
{
    switch (node)
    {
        case RobotNodes::eNODE_ARM: 
        {
            amy::ArmNode2 oArmNode;   
            Topic oTopic;
            oTopic.set(node, section, channel, Topic::eTYPE_CONTROL);
            // try building control topic for specified node-section-channel
            if (oArmNode.buildTopic(oTopic))
                return oTopic.getTopicName();
            // if invalid combination return empty
            else
                return "";
        }            
        break;
            
        case RobotNodes::eNODE_BODYROLE: 
            // TO DO
            return "";
            break;
        
        case RobotNodes::eNODE_VISION: 
            // TO DO
            return "";
        break;
        
        // unknown nodes
        default: 
            return "";
    }            
}
}