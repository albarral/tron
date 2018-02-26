/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <sys/stat.h>

#include "tron/wire2/FileSubscribeChannel.h"
#include "tron/wire2/Wire2Config.h"
#include "tuly/utils/FileWriter.h"

namespace tron
{
log4cxx::LoggerPtr FileSubscribeChannel::logger(log4cxx::Logger::getLogger("tron.comy"));

FileSubscribeChannel::FileSubscribeChannel()
{    
    // get coms file path 
    Wire2Config oComyConfig;    
    comsBasePath = oComyConfig.getComsBasePath();
    
    // create coms base folder (if it doesn't exist)
    if (!comsBasePath.empty())
        mkdir(comsBasePath.c_str(), 0777);
}

FileSubscribeChannel::~FileSubscribeChannel()
{
    if (oFileReader.isOpen())
        oFileReader.close();
}

void FileSubscribeChannel::connect(std::string topic, std::string category)
{
    // set communications channel
    setChannel(channelType, topic, category);

    if (oChannel.isInformed())
    {
        // open coms file for reading
        if (!comsBasePath.empty())
        {        

            pathComsFile = comsBasePath + "/" + oChannel.getName() + Wire2Config::comsFileExtension;
            bconnected = oFileReader.open(pathComsFile);   
            // if file reader not opened, create the coms file and reopen
            if (!bconnected)
            {
                createComsFile();
                bconnected = oFileReader.open(pathComsFile); 
            }
            // first clean file
            if (bconnected)
                oFileReader.cleanFile();
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

std::string FileSubscribeChannel::readSingleMessage()
{
    std::string rawMessage = "";

    if (oFileReader.isOpen())        
    {
        // read file from top
        oFileReader.goTop();
        rawMessage = oFileReader.readLine();            
    }
    else
    {
        LOG4CXX_ERROR(logger, "ComyFileSubscriber: can't read message, file reader not open ");
    }
    
    return rawMessage;
}

bool FileSubscribeChannel::getNewMessages(std::vector<std::string>& listMessages)
{
    bool bread = false;
    if (oFileReader.isOpen())   
    {
        // read file from top
        oFileReader.goTop();
        bread = oFileReader.readAllLines(listMessages);
    }
    else
    {
        LOG4CXX_ERROR(logger, "ComyFileSubscriber: can't read messages, file reader not open ");
    }
    
    return bread;
}

void FileSubscribeChannel::createComsFile()
{
    tuly::FileWriter oFileWriter;
    oFileWriter.open(pathComsFile, false);  
    
    if (oFileWriter.isOpen())                   
    {
        LOG4CXX_INFO(logger, "ComyFileServer: coms file created");                        
        oFileWriter.close();        
    }        
}

}