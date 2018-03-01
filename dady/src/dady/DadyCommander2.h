#ifndef __DADY_COMMANDER2_H
#define __DADY_COMMANDER2_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>

#include "tron/robot/RobotNodes.h"
#include "tron/robot/topics/ArmTopics.h"
#include "tron/talky2/Talker.h"

namespace dady
{
// Class used to interpret user entered commands in talky communication language.
class DadyCommander2 
{
public: 
    static const std::string COMMAND_SEPARATOR;       // separator in dady commands
    
private:
    static log4cxx::LoggerPtr logger;    
    const int NUM_WORDS = 3;            // words expected in dady commands
    int targetNode;                          // target node (arm, vision, ...) 
    int targetTopic;                          // target topic (for arm node: joints, axis, ...)
    std::string message;                 // message to send
    tron::RobotNodes oRobotNodes;
    tron::ArmTopics oArmTopics;
    

public:
    DadyCommander2();
    //~DadyCommander2();
    
    int getCommandSize() {return NUM_WORDS;};
    
    bool checkValidCommand(std::string entry);
    bool sendMessage();

    void showAvailableCommands();
    
private:
    bool checkCorrectMessage();
    tron::Talker* createTalker4ArmTopic(int topic);
    
};
}		
#endif
