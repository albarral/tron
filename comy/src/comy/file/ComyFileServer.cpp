/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <iostream>
#include <sys/stat.h>

#include "comy/file/ComyFileServer.h"
#include "comy/ComyConfig.h"

namespace comy
{
log4cxx::LoggerPtr ComyFileServer::logger(log4cxx::Logger::getLogger("comy"));

ComyFileServer::ComyFileServer()
{    
    // get coms configuration
    ComyConfig oComyConfig;    
    comsBasePath = oComyConfig.getComsBasePath();

    // create coms base folder (if it doesn't exist)
    if (!comsBasePath.empty())
        mkdir(comsBasePath.c_str(), 0777);
}

ComyFileServer::~ComyFileServer()
{
    if (oFileReader.isOpen())
        oFileReader.close();
}

void ComyFileServer::connect(std::string topic, std::string category)
{
    // set communications channel
    setChannel(channelType, topic, category);
    
    if (oChannel.isInformed())
    {
        // open coms file for reading & writing
        if (!comsBasePath.empty())
        {        
            pathComsFile = comsBasePath + "/" + oChannel.getName() + ComyConfig::comsFileExtension;
            bconnected = oFileReader.open(pathComsFile); 
            // first clean file
            if (bconnected)
                oFileReader.cleanFile();
        }
        else
            bconnected = false;    
    }
    else
    {
        bconnected = false;        
        LOG4CXX_WARN(logger, "ComyFileServer: connection failed, coms channel needs to be defined");                        
    }        
}

std::string ComyFileServer::readSingleMessage()
{
    std::string rawMessage = "";

    if (oFileReader.isOpen())        
        rawMessage = oFileReader.readLine();            
    else
    {
        LOG4CXX_ERROR(logger, "ComyFileServer: can't read message, file reader not open ");
    }
    
    return rawMessage;
}

bool ComyFileServer::getNewMessages(std::vector<std::string>& listMessages)
{
    bool bread = false;
    if (oFileReader.isOpen())        
        bread = oFileReader.readAllLines(listMessages);
    else
    {
        LOG4CXX_ERROR(logger, "ComyFileServer: can't read messages, file reader not open ");
    }
    
    return bread;
}

}