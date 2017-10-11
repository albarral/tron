/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "comy/file/ComyFileClient.h"
#include "comy/ComyConfig.h"

namespace comy
{
log4cxx::LoggerPtr ComyFileClient::logger(log4cxx::Logger::getLogger("comy.client"));

ComyFileClient::ComyFileClient()
{    
    // get coms file name
    ComyConfig oComyConfig;    
    filename = oComyConfig.getComsFilename1();
    // open coms file for writing
    if (!filename.empty())
    {
        oFileWriter.open(filename);  
    }
}

ComyFileClient::~ComyFileClient()
{
    oFileWriter.close();    
}

void ComyFileClient::sendMessage(std::string text)
{
    if (oFileWriter.isOpen())        
    {
        // write command in coms file (newline added)
        std::string output = text + "\n";
        // overwriting any previous command
        oFileWriter.writeFromTop();
        oFileWriter.writeFlush(output);
        LOG4CXX_INFO(logger, "ComyFileClient: command sent");        
    }
    else
        LOG4CXX_ERROR(logger, "ComyFileClient: send failed! coms file not open");                
}


}