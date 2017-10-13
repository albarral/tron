/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "comy/file/ComyFileClient.h"
#include "comy/ComyConfig.h"

namespace comy
{
log4cxx::LoggerPtr ComyFileClient::logger(log4cxx::Logger::getLogger("comy"));

ComyFileClient::ComyFileClient()
{    
    // get coms file name
    ComyConfig oComyConfig;    
    filePathCS = oComyConfig.getComsPathCS();
}

ComyFileClient::~ComyFileClient()
{
    if (oFileWriter.isOpen())                   
        oFileWriter.close();    
}

void ComyFileClient::connect()
{
    // open coms file for writing
    if (!filePathCS.empty())
    {        
        bconnected = oFileWriter.open(filePathCS);  
    }
    else
        bconnected = false;    
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
        LOG4CXX_INFO(logger, "ComyFileClient: command sent");        
        return true;
    }
    else
    {
        LOG4CXX_ERROR(logger, "ComyFileClient: send failed! coms file not open");                
        return false;
    }
}


}