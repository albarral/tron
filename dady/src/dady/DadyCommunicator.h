#ifndef __AMY_CONSOLE_DADYCOMMUNICATOR_H
#define __AMY_CONSOLE_DADYCOMMUNICATOR_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>

#include "comy/file/ComyFileClient.h"

namespace dady
{
// Class that sends requests to the amy process through a comy client.
class DadyCommunicator
{
private:
    static log4cxx::LoggerPtr logger;
    comy::ComyFileClient oComyClientJoints;   // communications client for joint category
    comy::ComyFileClient oComyClientAxis;   // communications client for axis category
    comy::ComyFileClient oComyClientCyclic;   // communications client for cyclic category
    comy::ComyFileClient oComyClientExtra;   // communications client for extra category

public:
    DadyCommunicator();
    //~DadyCommunicator();

    // connect to amy process
    bool connect2Amy();                
    // sends command to amy process
    bool sendCommand(std::string message, int topic, int category);    
    
private:
    //  sends command through specified channel
    bool sendCommand2Channel(comy::ComyFileClient& oComyClient, std::string message);
        
};
}		
#endif
