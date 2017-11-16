/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <sys/stat.h>

#include "comy/file/ComyFileSubscriber.h"
#include "comy/ComyConfig.h"

namespace comy
{
log4cxx::LoggerPtr ComyFileSubscriber::logger(log4cxx::Logger::getLogger("comy"));

ComyFileSubscriber::ComyFileSubscriber()
{    
    // get coms file path 
    ComyConfig oComyConfig;    
    comsBasePath = oComyConfig.getComsBasePath();
    
    // create coms base folder (if it doesn't exist)
    if (!comsBasePath.empty())
        mkdir(comsBasePath.c_str(), 0777);
}

ComyFileSubscriber::~ComyFileSubscriber()
{
    if (oFileReader.isOpen())
        oFileReader.close();
}

void ComyFileSubscriber::connect(std::string topic, std::string category)
{
    // set communications channel
    setChannel(channelType, topic, category);

    if (oChannel.isInformed())
    {
        // open coms file for reading
        if (!comsBasePath.empty())
        {        

            pathComsFile = comsBasePath + "/" + oChannel.getName() + ComyConfig::comsFileExtension;
            bconnected = oFileReader.open(pathComsFile);   
        }
        else
            bconnected = false;    
    }
    else
    {
        bconnected = false;        
        LOG4CXX_WARN(logger, "ComyFileSubscriber: connection failed, coms channel needs to be defined");                        
    }        
    
}

bool ComyFileSubscriber::readMessage()
{
    bool brequest = false;  // default no request received

    if (oFileReader.isOpen())        
    {
        // read file from top
        oFileReader.goTop();
        // read message in file
        rawMessage = oFileReader.readLine();      

        // if request received, interpret it
        if (!rawMessage.empty())
            brequest = true;
    }
    else
    {
        LOG4CXX_ERROR(logger, "ComyFileSubscriber: could not open coms file " << pathComsFile);
    }
    
    return brequest;
}

}