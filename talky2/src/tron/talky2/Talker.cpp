/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <stdexcept>      // std::out_of_range

#include "tron/talky2/Talker.h"
#include "tron/robot/RobotNodes.h"
#include "tuly/utils/StringUtil.h"

using namespace log4cxx;

namespace tron
{
LoggerPtr Talker::logger(Logger::getLogger("tron.talky2"));

const std::string Talker::EMPTY = "";        
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

Talker::~Talker()
{
    mapWords.clear();
    mapCodes.clear();
}

void Talker::addConcept(int code, std::string name)
{
    // add concept to maps
    mapWords.emplace(name, code);    
    mapCodes.emplace(code, name);    
}


bool Talker::buildMessage(int code, float value, std::string& message)
{
    // get concept name 
    std::string word = getWord4Code(code);

    // if known concept, build message
    if (!word.empty())
    {
        message = word + Talker::FIELD_SEPARATOR + std::to_string(value);
        return true;
    }
    // unknown concept
    else
    {
        message = Talker::EMPTY;
        LOG4CXX_WARN(logger, name + " Talker: message not built, unknown code " << code);
        return false;
    }
}

// expected message is code*value
bool Talker::interpretMessage(std::string message, int& code, float& value)
{           
    // get message parts
    std::vector<std::string> listTokens = tuly::StringUtil::split(message, Talker::FIELD_SEPARATOR); 

    // if right message size, interpret it
    if (listTokens.size() == Talker::MSG_FIELDS)
    {
        // interpret concept 
        code = getCode4Word(listTokens.at(0));
               
        // if known concept, interpret value 
        if (code != Talker::UNKNOWN_VALUE)
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


int Talker::getCode4Word(std::string word)
{
    try 
    {
        // search word in words map
        return mapWords.at(word);
    }
    // if word not found, return unknown code
    catch (const std::out_of_range& oor) 
    {                
        return Talker::UNKNOWN_VALUE;
    }            
}        

std::string Talker::getWord4Code(int code)
{
    try 
    {
        // search code in codes map
        return mapCodes.at(code);
    }
    // if code not found, return empty
    catch (const std::out_of_range& oor) 
    {                
        return Talker::EMPTY;
    }                
}

std::string Talker::showKnowledge()
{
    std::string text;
            
    // for each concept
    for (auto& x: mapCodes) 
    {
        text += std::to_string(x.first) + " - " + x.second + "\n";
    }    

    return text;
}

}