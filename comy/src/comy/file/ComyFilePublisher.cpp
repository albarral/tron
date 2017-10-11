/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "comy/file/ComyFilePublisher.h"
#include "comy/ComyConfig.h"

namespace comy
{
log4cxx::LoggerPtr ComyFilePublisher::logger(log4cxx::Logger::getLogger("comy.publisher"));

ComyFilePublisher::ComyFilePublisher()
{    
    // get coms file name
    ComyConfig oComyConfig;    
    filename = oComyConfig.getComsFilename2();
}

ComyFilePublisher::~ComyFilePublisher()
{
    oFileWriter.close();    
}

void ComyFilePublisher::init()
{
    // open coms file for writing
    if (!filename.empty())
    {
        if (oFileWriter.open(filename))
            benabled = true;        
    }    
}

void ComyFilePublisher::publishInfo(std::string rawMessage)
{
    if (oFileWriter.isOpen())        
    {
        // overwrite any previous info
        oFileWriter.writeFromTop();
        oFileWriter.writeFlush(rawMessage);
        //LOG4CXX_INFO(logger, "ComyFilePublisher: > " << sollMessage);        
    }
    else
        LOG4CXX_ERROR(logger, "ComyFilePublisher: can't publish info, coms file not open");                
}


}