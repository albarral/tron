/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <sys/stat.h>

#include "tron/wire2/FileClientChannel.h"
#include "tron/wire2/Wire2Config.h"

namespace tron
{
log4cxx::LoggerPtr FileClientChannel::logger(log4cxx::Logger::getLogger("tron.wire2"));

FileClientChannel::FileClientChannel()
{    
    // get coms configuration
    Wire2Config oComyConfig;    
    comsBasePath = oComyConfig.getComsBasePath();
    
    // create coms base folder (if it doesn't exist)
    if (!comsBasePath.empty())
        mkdir(comsBasePath.c_str(), 0777);
}

FileClientChannel::FileClientChannel(int node, int channel) : ClientChannel(node, channel)
{
    
}

FileClientChannel::~FileClientChannel()
{
    if (oFileWriter.isOpen())                   
        oFileWriter.close();    
}

void FileClientChannel::connect(std::string topic, std::string category)
{
    // set communications channel
    setChannel(channelType, topic, category);

    if (oChannel.isInformed())
    {
        // open coms file for writing
        if (!comsBasePath.empty())
        {        

            pathComsFile = comsBasePath + "/" + oChannel.getName() + Wire2Config::comsFileExtension;
            // writer opened in append mode
            bconnected = oFileWriter.open(pathComsFile, true);  
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

bool FileClientChannel::sendMessage(std::string text)
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
        LOG4CXX_ERROR(logger, "ComyFileClient: send failed! coms file not open");                
        return false;
    }
}


}