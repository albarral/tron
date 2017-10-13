/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "comy/file/ComyFileSubscriber.h"
#include "comy/ComyConfig.h"

namespace comy
{
log4cxx::LoggerPtr ComyFileSubscriber::logger(log4cxx::Logger::getLogger("comy"));

ComyFileSubscriber::ComyFileSubscriber()
{    
    // get coms file path 
    ComyConfig oComyConfig;    
    filePathPS = oComyConfig.getComsPathPS();
}

ComyFileSubscriber::~ComyFileSubscriber()
{
    oFileReader.close();
}

void ComyFileSubscriber::init()
{
    // open coms file for reading 
    if (!filePathPS.empty())
    {
        if (oFileReader.open(filePathPS))
            benabled = true;        
    }    
}

bool ComyFileSubscriber::readInfo()
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
        LOG4CXX_ERROR(logger, "ComyFileSubscriber: could not open coms file " << filePathPS);
    }
    
    return brequest;
}

}