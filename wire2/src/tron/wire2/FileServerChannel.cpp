/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/wire2/FileServerChannel.h"

namespace tron
{
FileServerChannel::FileServerChannel()
{    
    setFullPath(name);    
}

FileServerChannel::FileServerChannel(int node, int channel) : ServerChannel(node, channel)
{
    setFullPath(name);    
}

FileServerChannel::~FileServerChannel()
{
    if (oFileReader.isOpen())
        oFileReader.close();
}

bool FileServerChannel::open()
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
        LOG4CXX_INFO(logger, "FileServerChannel: channel opened ok - " + fullPath);                                
    }
    else
    {
        LOG4CXX_WARN(logger, "FileServerChannel: channel opening failed - " + fullPath);                                
    }
    
    return bopen;        
}

bool FileServerChannel::close()
{        
    if (bopen && oFileReader.close())
    {
        LOG4CXX_INFO(logger, "FileServerChannel: channel closed ok - " + fullPath);                                
        return true;
    }
    else
    {
        LOG4CXX_WARN(logger, "FileServerChannel: channel closing failed - " + fullPath);                                
        return false;
    }
}

bool FileServerChannel::receiveMessages(std::vector<std::string>& listMessages)
{
    if (oFileReader.isOpen())        
        return oFileReader.readAllLines(listMessages);
    else
    {
        LOG4CXX_ERROR(logger, "FileServerChannel: can't read messages, file reader not open ");
        return false;
    }
}
}