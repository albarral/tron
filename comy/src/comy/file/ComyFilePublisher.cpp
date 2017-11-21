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
    comsBasePath = oComyConfig.getComsBasePath();
  
    // create coms base folder (if it doesn't exist)
    if (!comsBasePath.empty())
        mkdir(comsBasePath.c_str(), 0777);
}

ComyFilePublisher::~ComyFilePublisher()
{
    oFileWriter.close();    
}

void ComyFilePublisher::connect(std::string topic, std::string category)
{        
    // set communications channel
    setChannel(channelType, topic, category);
    
    if (oChannel.isInformed())
    {
        // open coms file for writing
        if (!comsBasePath.empty())
        {        

            pathComsFile = comsBasePath + "/" + oChannel.getName() + ComyConfig::comsFileExtension;
            // writer opened not in append mode            
            bconnected = oFileWriter.open(pathComsFile, false);  
        }
        else
            bconnected = false;    
    }
    else
    {
        bconnected = false;        
        LOG4CXX_WARN(logger, "ComyFilePublisher: connection failed, coms channel needs to be defined");                        
    }    
}

bool ComyFilePublisher::newPublishing()
{
    if (oFileWriter.isOpen())        
    {
        // overwrite any previous info
        oFileWriter.goTop();
        return true;
    }
    else
    {
        LOG4CXX_ERROR(logger, "ComyFilePublisher: can't publish info, coms file not open");                
        return false;
    }   
}

bool ComyFilePublisher::publishMessage(std::string text)
{
    if (oFileWriter.isOpen())        
    {
        // write text in coms file with default string delimiter
        std::string output = text + delimiter;        
        oFileWriter.writeFlush(output);
        return true;
    }
    else
    {
        LOG4CXX_ERROR(logger, "ComyFilePublisher: can't publish info, coms file not open");                
        return false;
    }
}


}