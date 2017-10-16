/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <sys/stat.h>

#include "comy/file/ComyFilePublisher.h"
#include "comy/ComyConfig.h"

namespace comy
{
log4cxx::LoggerPtr ComyFilePublisher::logger(log4cxx::Logger::getLogger("comy"));

ComyFilePublisher::ComyFilePublisher()
{    
    // get coms file path
    ComyConfig oComyConfig;    
    
    // create coms base folder (if it doesn't exist)
    mkdir(oComyConfig.getComsBasePath().c_str(), 0777);
    
    pathPubSubFile = oComyConfig.getPubSubComsPath();
}

ComyFilePublisher::~ComyFilePublisher()
{
    oFileWriter.close();    
}

void ComyFilePublisher::connect()
{
    // open coms file for writing
    if (!pathPubSubFile.empty())
    {
        if (oFileWriter.open(pathPubSubFile))
            bconnected = true;        
    }    
}

bool ComyFilePublisher::publishMessage(std::string rawMessage)
{
    if (oFileWriter.isOpen())        
    {
        // overwrite any previous info
        oFileWriter.writeFromTop();
        oFileWriter.writeFlush(rawMessage);
        //LOG4CXX_INFO(logger, "ComyFilePublisher: > " << sollMessage);        
        return true;
    }
    else
    {
        LOG4CXX_ERROR(logger, "ComyFilePublisher: can't publish info, coms file not open");                
        return false;
    }
}


}