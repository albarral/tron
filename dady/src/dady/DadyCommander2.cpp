/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include<vector>

#include "dady/DadyCommander2.h"
#include "tuly/utils/StringUtil.h"
#include "tron/wire2/FileWire.h"
#include "tron/talky2/TalkyLanguages.h"
// common talkers
#include "tron/talky2/BasicTalker.h"
// arm talkers
#include "tron/talky2/arm/JointTalker.h"
#include "tron/talky2/arm/AxisTalker.h"
#include "tron/talky2/arm/CyclicTalker.h"
// body talkers
#include "tron/talky2/body/ExpressiveTalker.h"
#include "tron/talky2/body/ArtisticTalker.h"

using namespace log4cxx;

namespace dady
{
LoggerPtr DadyCommander2::logger(Logger::getLogger("dady"));

const std::string DadyCommander2::COMMAND_SEPARATOR = " ";

// Constructor 
DadyCommander2::DadyCommander2()
{    
}

bool DadyCommander2::checkValidCommand(std::string entry)
{              
    int processedElements = 0;
    int validElements = 0;
    std::string nodeName;
    std::string topicName;
    
    // if no command
    if (entry.empty())
    {
        // show available nodes
        showAvailableNodes();
        return false;        
    }
    
    // split command parts 
    std::vector<std::string> listTokens = tuly::StringUtil::split(entry, COMMAND_SEPARATOR);
    
    // skip if excessive command parts
    if (listTokens.size() > eCOMMAND_DIM)
    {
        LOG4CXX_WARN(logger, "DadyCommander2: command size exceeded " << listTokens.size());    
        return false;         
    }
    
    // if node informed
    if (listTokens.size() > eCOMMAND_NODE)
    {
        // interpret node
        nodeName = listTokens.at(eCOMMAND_NODE);
        targetNode = oRobotNodes.getCode4Node(nodeName);
        // and check its validity
        if (targetNode != -1)
            validElements++;
        else
            LOG4CXX_WARN(logger, "DadyCommander2: unknown node " << nodeName);    
    }
    else
        // show available nodes
        showAvailableNodes();
        
    processedElements++;
    // skip if node invalid or not informed
    if (processedElements != validElements)
        return false;
        
    // if topic informed
    if (listTokens.size() > eCOMMAND_TOPIC)
    {
        // interpret topic
        topicName = listTokens.at(eCOMMAND_TOPIC);
        targetTopic = interpretTopic(targetNode, topicName);    
        // and check its validity
        if (targetTopic != -1)
            validElements++;
        else
            LOG4CXX_WARN(logger, "DadyCommander2: unknown topic " + topicName);    
    }
    else
        // show available topics for node
        showAvailableTopics(targetNode);        
    
    processedElements++;
    // skip if topic invalid or not informed
    if (processedElements != validElements)
        return false;

    // if concept informed
    if (listTokens.size() > eCOMMAND_CONCEPT)
    {
        // interpret concept
        message = listTokens.at(eCOMMAND_CONCEPT);            
        if (checkCorrectMessage(targetNode, targetTopic, message))
            validElements++;
        else
            LOG4CXX_WARN(logger, "DadyCommander2: invalid concept " + message);            
    }
    else
        // show available concepts for node & topic
        showAvailableConcepts(targetNode, targetTopic);

    processedElements++;
    // return false if concept invalid or not informed
    return (processedElements == validElements);
}

int DadyCommander2::interpretTopic(int node, std::string topicName)
{
    int topic = -1;
    // check valid topic
    switch (node)
    {
        case tron::RobotNodes::eNODE_ARM: 
            topic = oArmTopics.getCode4Topic(topicName);
            break;
            
        case tron::RobotNodes::eNODE_BODYROLE: 
            topic = oBodyTopics.getCode4Topic(topicName);
            break;
    }
    return topic;
}

bool DadyCommander2::checkCorrectMessage(int node, int topic, std::string msg)
{    
    // create proper talker for target node & topic
    tron::Talker* pTalker = tron::TalkyLanguages::createTalker(node, topic);
        
    // if talker created
    if (pTalker != 0)
    {
        int code; 
        float value;
        // check if it can interpret the message
        bool bok = pTalker->interpretMessage(message, code, value);
        // release the talker
        delete(pTalker);
        return bok;        
    }
    // if no talker created, message can not be correct
    else
        return false;    
}

bool DadyCommander2::sendMessage()
{
    tron::FileWire oWire; // communications wire       
    return oWire.sendMsg(targetNode, targetTopic, message);
}

void DadyCommander2::showAvailableNodes()
{
   LOG4CXX_INFO(logger, "available nodes: \n" + oRobotNodes.getMapDescription());   
}

void DadyCommander2::showAvailableTopics(int node)
{
    std::string desc; 
    switch (node)
    {
        case tron::RobotNodes::eNODE_ARM: 
            desc = oArmTopics.getMapDescription();
            break;

        case tron::RobotNodes::eNODE_BODYROLE: 
            desc = oBodyTopics.getMapDescription();
            break;
    }   
    LOG4CXX_INFO(logger, "available topics: \n" + desc);      
}

void DadyCommander2::showAvailableConcepts(int node, int topic)
{
    // create proper talker for target node & topic
    tron::Talker* pTalker = tron::TalkyLanguages::createTalker(node, topic);
        
    // if talker created
    if (pTalker != 0)
    {        
        LOG4CXX_INFO(logger, "available concepts: \n" + pTalker->getMapDescription());
        // release the talker
        delete(pTalker);
    }
}
}