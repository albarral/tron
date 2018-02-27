/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/wire2/FileSubscribeChannel.h"

namespace tron
{
FileSubscribeChannel::FileSubscribeChannel()
{    
    setFullPath(name);    
}

FileSubscribeChannel::FileSubscribeChannel(int node, int channel) : SubscribeChannel(node, channel)
{
    setFullPath(name);    
}

FileSubscribeChannel::~FileSubscribeChannel()
{
    close();
}

bool FileSubscribeChannel::open()
{
    // open file reader 
    bopen = oFileReader.open(fullPath);  

    // if file reader not opened, create the coms file and reopen
    if (!bopen)
    {
        createComsFile();
        bopen = oFileReader.open(fullPath);  
    }

    if (bopen) 
    {
        // first clean file
        oFileReader.cleanFile();
        LOG4CXX_INFO(logger, "FileSubscribeChannel: channel opened ok - " + fullPath);                                
    }
    else
    {
        LOG4CXX_WARN(logger, "FileSubscribeChannel: channel opening failed - " + fullPath);                                
    }
    
    return bopen;        
}

bool FileSubscribeChannel::close()
{        
    if (bopen && oFileReader.close())
    {
        LOG4CXX_INFO(logger, "FileSubscribeChannel: channel closed ok - " + fullPath);                                
        return true;
    }
    else
    {
        LOG4CXX_WARN(logger, "FileSubscribeChannel: channel closing failed - " + fullPath);                                
        return false;
    }
}

bool FileSubscribeChannel::receiveMessages(std::vector<std::string>& listMessages)
{
    if (oFileReader.isOpen())   
    {
        // read file from top
        oFileReader.goTop();
        return oFileReader.readAllLines(listMessages);
    }
    else
    {
        LOG4CXX_ERROR(logger, "FileSubscribeChannel: can't read messages, file reader not open ");
        return false;
    }
}


}