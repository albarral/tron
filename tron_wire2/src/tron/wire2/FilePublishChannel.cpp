/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/wire2/FilePublishChannel.h"

namespace tron
{
FilePublishChannel::FilePublishChannel()
{    
    setFullPath(name);    
}

FilePublishChannel::FilePublishChannel(int node, int channel) : PublishChannel(node, channel)
{
    setFullPath(name);    
}

FilePublishChannel::~FilePublishChannel()
{
    close();
}

bool FilePublishChannel::open()
{
    // open file writer in no append mode
    bopen = oFileWriter.open(fullPath, false);  

    if (bopen) 
    {
        // on publisher wake up the channel is cleared (all existing messages are removed)
        LOG4CXX_INFO(logger, "FilePublishChannel: channel opened ok - " + fullPath);                                
    }
    else
    {
        LOG4CXX_WARN(logger, "FilePublishChannel: channel opening failed - " + fullPath);                                
    }
    
    return bopen;        
}

bool FilePublishChannel::close()
{        
    if (bopen && oFileWriter.close())
    {
        LOG4CXX_INFO(logger, "FilePublishChannel: channel closed ok - " + fullPath);                                
        return true;
    }
    else
    {
        LOG4CXX_WARN(logger, "FilePublishChannel: channel closing failed - " + fullPath);                                
        return false;
    }
}

bool FilePublishChannel::clearInfo()
{
    if (bopen && oFileWriter.isOpen())        
    {
        // overwrite any previous info
        oFileWriter.goTop();
        return true;
    }
    else
    {
        LOG4CXX_ERROR(logger, "FilePublishChannel: can't clear info, coms file not open");                
        return false;
    }   
}

bool FilePublishChannel::sendMsg(std::string message)
{
    if (bopen && oFileWriter.isOpen())        
    {
        // write message to coms file with default string delimiter
        oFileWriter.writeFlush(message + delimiter);
        return true;
    }
    else
    {
        LOG4CXX_ERROR(logger, "FilePublishChannel: send msg failed! coms file not open");                
        return false;
    }
}

bool FilePublishChannel::sendMessages(std::vector<std::string>& listMessages)
{
    if (bopen && oFileWriter.isOpen())        
    {
        // for each message
        for (std::string message : listMessages)
        {       
            // write message to coms file with default string delimiter
            oFileWriter.writeFlush(message + delimiter);
        }
        return true;
    }
    else
    {
        LOG4CXX_ERROR(logger, "FilePublishChannel: send messages failed! coms file not open");                
        return false;
    }    
}

}