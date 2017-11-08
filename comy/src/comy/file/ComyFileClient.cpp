/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <sys/stat.h>

#include "comy/file/ComyFileClient.h"
#include "comy/ComyConfig.h"

namespace comy
{
log4cxx::LoggerPtr ComyFileClient::logger(log4cxx::Logger::getLogger("comy"));

ComyFileClient::ComyFileClient()
{    
    // get coms configuration
    ComyConfig oComyConfig;    
    comsBasePath = oComyConfig.getComsBasePath();
    
    // create coms base folder (if it doesn't exist)
    if (!comsBasePath.empty())
        mkdir(comsBasePath.c_str(), 0777);
}

ComyFileClient::~ComyFileClient()
{
    if (oFileWriter.isOpen())                   
        oFileWriter.close();    
}

void ComyFileClient::connect(std::string topic, std::string category)
{
    // set communications channel
    setChannel(channelType, topic, category);

    if (oChannel.isInformed())
    {
        // open coms file for writing
        if (!comsBasePath.empty())
        {        

            pathComsFile = comsBasePath + "/" + oChannel.getName() + ComyConfig::comsFileExtension;
            bconnected = oFileWriter.open(pathComsFile);  
        }
        else
            bconnected = false;    
    }
    else
    {
        bconnected = false;        
        LOG4CXX_WARN(logger, "ComyFileClient: connection failed, coms channel needs to be defined");                        
    }
}

bool ComyFileClient::sendMessage(std::string text)
{
    if (oFileWriter.isOpen())        
    {
        // write command in coms file (newline added)
        std::string output = text + "\n";
        // overwriting any previous command
        oFileWriter.writeFromTop();
        oFileWriter.writeFlush(output);
        //LOG4CXX_INFO(logger, "ComyFileClient: command sent");        
        return true;
    }
    else
    {
        LOG4CXX_ERROR(logger, "ComyFileClient: send failed! coms file not open");                
        return false;
    }
}


}