/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include<vector>

#include "dady/DadyCommander2.h"
#include "tuly/utils/StringUtil.h"
// arm talkers ...
#include "tron/talky2/arm/JointTalker.h"
#include "tron/talky2/arm/AxisTalker.h"
#include "tron/talky2/arm/CyclicTalker.h"
#include "tron/talky2/arm/BasicTalker.h"
#include "tron/wire2/FileWire.h"

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
    // get command parts 
    std::vector<std::string> listTokens = tuly::StringUtil::split(entry, COMMAND_SEPARATOR);
    
    // skip if bad command format
    if (listTokens.size() != NUM_WORDS)
    {
        LOG4CXX_WARN(logger, "DadyCommander2: invalid command size " << listTokens.size());    
        return false;         
    }

    std::string nodeName = listTokens.at(0);
    std::string topicName = listTokens.at(1);
    message = listTokens.at(2);
        
    targetNode = oRobotNodes.getCode4Node(nodeName);
    // check valid node
    if (targetNode == -1)
    {
        LOG4CXX_WARN(logger, "DadyCommander2: unknown node " << nodeName);    
        return false;
    }
    
    // check valid topic
    switch (targetNode)
    {
        case tron::RobotNodes::eNODE_ARM: 
            targetTopic = oArmTopics.getCode4Topic(topicName);
            break;
            
        default: 
            targetTopic = -1;
    }

    // check valid topic
    if (targetTopic == -1)
    {
        LOG4CXX_WARN(logger, "DadyCommander2: unknown topic " + topicName);    
        return false;
    }
    
    // check if message is correct
    if (checkCorrectMessage())
    {
        return true;
    }
    else
    {
        LOG4CXX_WARN(logger, "DadyCommander2: incorrect message " + message);            
        return false;
    }
}


bool DadyCommander2::checkCorrectMessage()
{    
    tron::Talker* pTalker;
    
    // create proper talker for target node & topic
    switch (targetNode)
    {
        case tron::RobotNodes::eNODE_ARM: 
            pTalker = createTalker4ArmTopic(targetTopic);
            break;

        default:
            pTalker = 0;            
    }
    
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

tron::Talker* DadyCommander2::createTalker4ArmTopic(int topic)
{
    // create proper talker for arm node topic
    switch (topic)
    {
        case tron::ArmTopics::eARM_JOINT: 
            return new tron::JointTalker();
            break;
            
        case tron::ArmTopics::eARM_AXIS: 
            return new tron::AxisTalker();
            break;
            
        case tron::ArmTopics::eARM_CYCLIC: 
            return new tron::CyclicTalker();
            break;
            
        case tron::ArmTopics::eARM_EXTRA: 
            return new tron::BasicTalker();
            break;
            
        default:
            return 0;
    }    
}

bool DadyCommander2::sendMessage()
{
    tron::FileWire oWire; // communications wire   
    
    return oWire.sendMsg(targetNode, targetTopic, message);
}

void DadyCommander2::showAvailableCommands()
{
    // TO DO ...
    //show known languages
    //oInterpreter.showKnowledge();    
}
}