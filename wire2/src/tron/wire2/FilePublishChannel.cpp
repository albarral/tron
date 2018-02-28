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

bool FilePublishChannel::sendMsg(std::string text)
{
    if (bopen && oFileWriter.isOpen())        
    {
        // write text in coms file with default string delimiter
        std::string output = text + delimiter;
        oFileWriter.writeFlush(output);
        return true;
    }
    else
    {
        LOG4CXX_ERROR(logger, "FilePublishChannel: send failed! coms file not open");                
        return false;
    }
}


bool FilePublishChannel::newPublishing()
{
    if (oFileWriter.isOpen())        
    {
        // overwrite any previous info
        oFileWriter.goTop();
        return true;
    }
    else
    {
        LOG4CXX_ERROR(logger, "FilePublishChannel: can't publish info, coms file not open");                
        return false;
    }   
}

}