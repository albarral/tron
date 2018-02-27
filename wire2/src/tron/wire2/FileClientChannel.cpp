/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/wire2/FileClientChannel.h"

namespace tron
{
FileClientChannel::FileClientChannel()
{    
    setFullPath(name);    
}

FileClientChannel::FileClientChannel(int node, int channel) : ClientChannel(node, channel)
{
    setFullPath(name);    
}

FileClientChannel::~FileClientChannel()
{
    oFileWriter.close();        
}

bool FileClientChannel::open()
{
    // open file writer in append mode
    bopen = oFileWriter.open(fullPath, true);  

    if (bopen) 
    {
        LOG4CXX_INFO(logger, "FileClientChannel: channel opened ok - " + fullPath);                                
    }
    else
    {
        LOG4CXX_WARN(logger, "FileClientChannel: channel opening failed - " + fullPath);                                
    }
    
    return bopen;        
}

bool FileClientChannel::close()
{        
    if (bopen && oFileWriter.close())
    {
        LOG4CXX_INFO(logger, "FileClientChannel: channel closed ok - " + fullPath);                                
        return true;
    }
    else
    {
        LOG4CXX_WARN(logger, "FileClientChannel: channel closing failed - " + fullPath);                                
        return false;
    }
}

bool FileClientChannel::sendMsg(std::string text)
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
        LOG4CXX_ERROR(logger, "FileClientChannel: send failed! coms file not open");                
        return false;
    }
}


}