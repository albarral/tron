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
//log4cxx::LoggerPtr ComyFileServer::logger(log4cxx::Logger::getLogger("comy"));

ComyFileServer::ComyFileServer()
{    
    // get coms configuration
    ComyConfig oComyConfig;    

    // create coms base folder (if it doesn't exist)
    mkdir(oComyConfig.getComsBasePath().c_str(), 0777);

    pathClientServerFile = oComyConfig.getClientServerComsPath();
}

ComyFileServer::~ComyFileServer()
{
    if (oFileReader.isOpen())
        oFileReader.close();
    
    if (oFileWriter.isOpen())
        oFileWriter.close();    
}

void ComyFileServer::connect()
{
    // open coms file for reading & writing
    if (!pathClientServerFile.empty())
    {
        bool bconnected1 = oFileReader.open(pathClientServerFile);   
        bool bconnected2 = oFileWriter.open(pathClientServerFile);   
        bconnected = bconnected1 && bconnected2;
    }
    else
        bconnected = false;    
}

bool ComyFileServer::readMessage()
{
    bool brequest = false;  // default no request received

    if (oFileReader.isOpen())        
    {
        // read file from top
        oFileReader.readFromTop();
        //LOG4CXX_INFO(logger, "ComyFileServer: read pos " << oFileReader.getPos());
        rawMessage = oFileReader.readLine();
        
        // and clear it
        oFileWriter.writeFromTop();
        oFileWriter.writeFlush("\n");

        // if request received, interpret it
        if (!rawMessage.empty())
            brequest = true;
    }
    else
    {
        //LOG4CXX_ERROR(logger, "ComyFileServer: could not open coms file " << filename);
    }
    
    return brequest;
}


}