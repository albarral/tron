#ifndef __TRON_DADY_COMMANDER_H
#define __TRON_DADY_COMMANDER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>

#include "tron/topics/RobotNodes.h"

namespace tron
{
// Class used to interpret user entered commands for robot communication.
// Commands format: ./dady <node> <section> <channel> <value>
class DadyCommander 
{
public:    
    static const std::string COMMAND_SEPARATOR;       // separator in dady commands
private: 
    /*! command fields */
    enum eCommand
    {
        eCOMMAND_NODE,
        eCOMMAND_SECTION,
        eCOMMAND_CHANNEL,
        eCOMMAND_VALUE,
        eCOMMAND_DIM
    };
    
    static log4cxx::LoggerPtr logger;    
    int targetNode;                          // target node (arm, vision, ...) 
    int targetSection;                      // target section
    int targetChannel;                     // target channel
    std::string value;                      // message value
    RobotNodes oRobotNodes;         // robot nodes

public:
    DadyCommander();
    //~DadyCommander();
    
    int getCommandSize() {return eCOMMAND_DIM;};
    
    bool checkValidCommand(std::string entry);
    bool sendMessage();
    
private:
    void showAvailableNodes();
    void showAvailableSections(int node);
    void showAvailableChannels(int node, int section);    
};
}		
#endif
