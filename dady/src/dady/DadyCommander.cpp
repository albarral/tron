/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include<vector>

#include "dady/DadyCommander.h"
#include "dady/RobotChannels.h"
#include "tron/coms/ComsSender.h"
#include "tron/util/StringUtil.h"

using namespace log4cxx;

namespace tron
{
LoggerPtr DadyCommander::logger(Logger::getLogger("dady"));

const std::string DadyCommander::COMMAND_SEPARATOR = " ";

// Constructor 
DadyCommander::DadyCommander()
{ 
    targetNode = -1;
    targetSection = -1;
    targetChannel = -1;
}

bool DadyCommander::checkValidCommand(std::string entry)
{              
    bool bwellProcessed = false;
    std::string nodeName;
    std::string sectionName;
    std::string channelName;
    
    // if no command
    if (entry.empty())
    {
        // show available nodes
        showAvailableNodes();
        return false;        
    }
    
    // split command parts 
    std::vector<std::string> listTokens = tron::StringUtil::split(entry, COMMAND_SEPARATOR);
    
    // skip if excessive command parts
    if (listTokens.size() > eCOMMAND_DIM)
    {
        LOG4CXX_WARN(logger, "DadyCommander: command size exceeded " << listTokens.size());    
        return false;         
    }
    
    // INTERPRET NODE
    if (listTokens.size() > eCOMMAND_NODE)
    {
        // get code for entered node name
        nodeName = listTokens.at(eCOMMAND_NODE);
        targetNode = oRobotNodes.getNode4Name(nodeName);
        // and check its validity
        if (targetNode != -1)
            bwellProcessed = true;
        else
            LOG4CXX_WARN(logger, "DadyCommander: unknown node " << nodeName);    
    }
    else
        // show available nodes
        showAvailableNodes();
        
    // skip if invalid or missing node
    if (!bwellProcessed)
        return false;
        
    // INTERPRET SECTION
    bwellProcessed = false;
    if (listTokens.size() > eCOMMAND_SECTION)
    {
        // get code for entered section name
        sectionName = listTokens.at(eCOMMAND_SECTION);
        targetSection = RobotChannels::getCode4NodeSection(targetNode, sectionName);
        // and check its validity
        if (targetSection != -1)
            bwellProcessed = true;            
        else        
            LOG4CXX_WARN(logger, "DadyCommander: unknown section " + sectionName);    
    }
    else
        // show available sections for node
        showAvailableSections(targetNode);        
    
    // skip if invalid or missing section
    if (!bwellProcessed)
        return false;
        
    // INTERPRET CHANNEL
    bwellProcessed = false;
    if (listTokens.size() > eCOMMAND_CHANNEL)
    {
        // get code for entered channel name
        channelName = listTokens.at(eCOMMAND_CHANNEL);
        targetChannel = RobotChannels::getCode4NodeSectionChannel(targetNode, targetSection, channelName);
        // and check its validity
        if (targetChannel != -1)
            bwellProcessed = true;
        else
            LOG4CXX_WARN(logger, "DadyCommander: unknown channel " + channelName);    
    }
    else
        // show available channels for node and section
        showAvailableChannels(targetNode, targetSection);        

    // skip if invalid or missing channel
    if (!bwellProcessed)
        return false;

    // INTERPRET VALUE
    bwellProcessed = false;
    if (listTokens.size() > eCOMMAND_VALUE)
    {
        value = listTokens.at(eCOMMAND_VALUE);  
        int ival;
        float fval;
        // check its validity (a numeric form)
        if (StringUtil::convert2Integer(value, ival) || StringUtil::convert2Float(value, fval))
            bwellProcessed = true;
        else
            LOG4CXX_WARN(logger, "DadyCommander: invalid value (not a number) " + value);            
    }
    else
        LOG4CXX_WARN(logger, "DadyCommander: missing value");            

    return (bwellProcessed);
}

bool DadyCommander::sendMessage()
{
    bool bok; 
    // get topic for specified node-section-channel
    std::string topic = RobotChannels::getTopic4NodeSectionChannel(targetNode, targetSection, targetChannel);
    if (!topic.empty())
    {
        ComsSender oComsSender;
        oComsSender.addChannel(topic);
        // time needed for publisher to prepare
        usleep(100000);            
        bok = oComsSender.getChannel(0)->sendMessage(value);
        // time needed for publisher to stay alive
        usleep(1000000);            
        return bok;        
    }
    else
        return false;    
}

void DadyCommander::showAvailableNodes()
{
   LOG4CXX_INFO(logger, "available nodes: \n" + oRobotNodes.toString());   
}

void DadyCommander::showAvailableSections(int node)
{
    std::string desc = RobotChannels::showAvailableSections4Node(node);
    LOG4CXX_INFO(logger, "available sections: \n" + desc);      
}

void DadyCommander::showAvailableChannels(int node, int section)
{
    std::string desc = RobotChannels::showAvailableChannels4NodeSection(node, section);
    LOG4CXX_INFO(logger, "available channels: \n" + desc);
}
}
