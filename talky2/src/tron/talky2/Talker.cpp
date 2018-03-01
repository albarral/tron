/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/talky2/Talker.h"
#include "tron/robot/RobotNodes.h"
#include "tuly/utils/StringUtil.h"

using namespace log4cxx;

namespace tron
{
LoggerPtr Talker::logger(Logger::getLogger("tron.talky2"));

const std::string Talker::FIELD_SEPARATOR = "*";

Talker::Talker()
{
    node = -1;
    topic = -1;
    name = "?";
}

Talker::Talker(int node, int topic)
{
    this->node = node;
    this->topic = topic;
        
    // start talker name with node word
    RobotNodes oRobotNodes;
    name = oRobotNodes.getNodeName(node) + "-";    
}

//Talker::~Talker()
//{
//}

void Talker::addConcept(int code, std::string name)
{
    // add concept to code map
    oCodeMap.addCode(code, name);
}


bool Talker::buildMessage(int code, float value, std::string& message)
{
    std::string word;

    // if known concept, build message with the concept name
    if (oCodeMap.getName4Code(code, word))
    {
        message = word + Talker::FIELD_SEPARATOR + std::to_string(value);
        return true;
    }
    // otherwise return false
    else
    {
        message = "";
        LOG4CXX_WARN(logger, name + " Talker: message not built, unknown code " << code);
        return false;
    }
}

// expected message is code*value
bool Talker::interpretMessage(std::string message, int& code, float& value)
{           
    // get message parts (concept*value)
    std::vector<std::string> listTokens = tuly::StringUtil::split(message, Talker::FIELD_SEPARATOR); 

    // if right message size, interpret it
    if (listTokens.size() == Talker::MSG_FIELDS)
    {
        // if known concept, interpret value 
        if (oCodeMap.getCode4Name(listTokens.at(0), code))
        {
            if (tuly::StringUtil::convert2Float(listTokens.at(1), value))            
            {
                return true;
            }
            // invalid quantity
            else
            {
                LOG4CXX_WARN(logger, name + " Talker: invalid quantity " << message);          
            }
        }
        // unknown concept 
        else
        {
            LOG4CXX_WARN(logger, name + " Talker: unknown concept " << message);   
        }
    }
    // wrong message size
    else
    {
        LOG4CXX_WARN(logger, name + " Talker: message not interpreted (wrong size) " << message);    
    }
    
    // if program arrives here, interpretation failed
    return false;
}


void Talker::showKnowledge()
{
    LOG4CXX_INFO(logger, name + " Talker: knowledge ... \n" << oCodeMap.toString());
}

}