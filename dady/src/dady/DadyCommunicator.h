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
    comy::ComyFileClient oComyClient;   // comy communications client

public:
    DadyCommunicator();
    //~DadyCommunicator();

    // connect to amy process
    bool connect2Amy();                
    // sends command to amy process
    bool sendCommand(std::string message);    
        
};
}		
#endif
