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
//log4cxx::LoggerPtr ComyFileServer::logger(log4cxx::Logger::getLogger("comy.server"));

ComyFileServer::ComyFileServer()
{    
    // get coms file name
    ComyConfig oComyConfig;    

    // create coms folder (if it doesn't exist)
    mkdir(oComyConfig.getComsFolder().c_str(), 0777);

    filename = oComyConfig.getComsFilename1();
    // open coms file for reading & writing
    if (!filename.empty())
    {
        oFileReader.open(filename);   
        oFileWriter.open(filename);   
    }
}

ComyFileServer::~ComyFileServer()
{
    oFileReader.close();
    oFileWriter.close();    
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