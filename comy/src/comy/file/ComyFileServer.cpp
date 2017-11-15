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
    
    if (oFileWriter.isOpen())
        oFileWriter.close();    
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
            bool bconnected1 = oFileWriter.open(pathComsFile);   
            bool bconnected2 = oFileReader.open(pathComsFile); 
            if (bconnected2)
                oFileReader.readFromTop();
            bconnected = bconnected1 && bconnected2;
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

std::string ComyFileServer::readMessage()
{
    std::string rawMessage = "";

    if (oFileReader.isOpen())        
    {
        // read file from top (NO!)
        //oFileReader.readFromTop();
        //LOG4CXX_INFO(logger, "ComyFileServer: read pos " << oFileReader.getPos());
        rawMessage = oFileReader.readLine();
        
        // and clear it (NO!)
        //oFileWriter.writeFromTop();
        //oFileWriter.writeFlush("\n");
    }
    else
    {
        LOG4CXX_ERROR(logger, "ComyFileServer: can't read message, file reader not open ");
    }
    
    return rawMessage;
}


}