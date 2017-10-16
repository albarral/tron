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
    
    // create coms base folder (if it doesn't exist)
    mkdir(oComyConfig.getComsBasePath().c_str(), 0777);
    
    pathPubSubFile = oComyConfig.getPubSubComsPath();
}

ComyFileSubscriber::~ComyFileSubscriber()
{
    if (oFileReader.isOpen())
        oFileReader.close();
}

void ComyFileSubscriber::connect()
{
    // open coms file for reading 
    if (!pathPubSubFile.empty())
    {
        if (oFileReader.open(pathPubSubFile))
            bconnected = true;        
    }    
}

bool ComyFileSubscriber::readMessage()
{
    bool brequest = false;  // default no request received

    if (oFileReader.isOpen())        
    {
        // read file from top
        oFileReader.readFromTop();
        // read message in file
        rawMessage = oFileReader.readLine();      

        // if request received, interpret it
        if (!rawMessage.empty())
            brequest = true;
    }
    else
    {
        LOG4CXX_ERROR(logger, "ComyFileSubscriber: could not open coms file " << pathPubSubFile);
    }
    
    return brequest;
}

}