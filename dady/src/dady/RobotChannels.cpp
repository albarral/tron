/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "dady/RobotChannels.h"
#include "tron/topics/RobotNodes.h"
#include "tron/topics/Topic.h"
#include "amy/interface2/ArmNode.h"

using namespace log4cxx;

namespace tron
{    
LoggerPtr RobotChannels::logger(Logger::getLogger("dady"));

//RobotChannels::RobotChannels()
//{
//}

int RobotChannels::getCode4NodeSection(int node, std::string sectionName)
{
    // get specified node
    Node* pNode = getNode(node);
    // if found
    if (pNode != nullptr)
    {
        // get section code
        int sectionCode = pNode->getSection4Name(sectionName);
        delete(pNode);
        return sectionCode;
    }
    // return invalid section if node unknown
    else
        return -1;
}


int RobotChannels::getCode4NodeSectionChannel(int node, int section, std::string channelName)
{        
    // get specified node
    Node* pNode = getNode(node);
    // if found
    if (pNode != nullptr)
    {
        // get specific section
        NodeSection* pNodeSection = pNode->getSection(section);
        // get channel code, return invalid channel if section unknown
        int channelCode = (pNodeSection != nullptr) ? pNodeSection->getChannel4Name(channelName) : -1; 
        delete(pNode);
        return channelCode;
    }
    // return invalid channel if node unknown
    else
        return -1;    
}

std::string RobotChannels::showAvailableSections4Node(int node)
{
    // get specified node
    Node* pNode = getNode(node);
    // if found
    if (pNode != nullptr)
    {
        // get node description
        std::string desc = pNode->toString();
        delete(pNode);
        return desc;
    }
    // return empty if node unknown
    else
        return "";  
}

std::string RobotChannels::showAvailableChannels4NodeSection(int node, int section)
{
    // get specified node
    Node* pNode = getNode(node);
    // if found
    if (pNode != nullptr)
    {
        // get specific section
        NodeSection* pNodeSection = pNode->getSection(section);
        // get its description, return unknown if l if section unknown
        std::string desc = (pNodeSection != nullptr) ? pNodeSection->toString() : "unknown section"; 
        delete(pNode);
        return desc;
    }
    // return empty if node unknown
    else
        return "";  
}

std::string RobotChannels::getTopic4NodeSectionChannel(int node, int section, int channel)
{
    // get specified node
    Node* pNode = getNode(node);
    // if found
    if (pNode != nullptr)
    {
        // create proper topic
        Topic oTopic;
        oTopic.set(node, section, channel, Topic::eTYPE_CONTROL);
        std::string topicName = "";
        // try building control topic for specified node-section-channel
        if (pNode->buildTopicName(oTopic))
            topicName = oTopic.getTopicName();        
        delete(pNode);
        return topicName;
    }
    // return empty if node unknown
    else
        return "";  
}

Node* RobotChannels::getNode(int node)
{
    switch (node)
    {
        case RobotNodes::eNODE_ARM: 
            return new amy::ArmNode2();
            break;
            
        case RobotNodes::eNODE_BODYROLE: 
            LOG4CXX_WARN(logger, "RobotChannels: missing body node " << node);                
            return nullptr;
            break;
        
        case RobotNodes::eNODE_VISION: 
            LOG4CXX_WARN(logger, "RobotChannels: missing vision node " << node);                
            return nullptr;
        break;
        
        // unknown nodes
        default: 
            LOG4CXX_WARN(logger, "RobotChannels: unknown node " << node);                
            return nullptr;
    }    
}

}