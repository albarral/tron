/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "dady/DadyCommunicator.h"

using namespace log4cxx;

namespace dady
{
LoggerPtr DadyCommunicator::logger(Logger::getLogger("dady"));

// Constructor 
DadyCommunicator::DadyCommunicator()
{    
 }

bool DadyCommunicator::connect2Amy()
{
    // connection
    oComyClient.connect();
    
    if (oComyClient.isConnected())
        return true;
    else
    {
        LOG4CXX_ERROR(logger, "DadyCommunicator: comy client not connected!");                        
        return false;
    }    
}

// send command to amy process
bool DadyCommunicator::sendCommand(std::string message)
{
    if (!oComyClient.isConnected())
    {
        LOG4CXX_ERROR(logger, "DadyCommunicator: comy client not connected!");                        
        return false;
    }    

    // send message 
    bool bsent = oComyClient.sendMessage(message);
    
    if (!bsent)
    {
        LOG4CXX_WARN(logger, "DadyCommunicator: message not sent");                        
    }

    return bsent;
}

}