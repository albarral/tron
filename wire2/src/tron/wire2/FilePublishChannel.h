#ifndef __TRON_WIRE2_FILEPUBLISHCHANNEL_H
#define __TRON_WIRE2_FILEPUBLISHCHANNEL_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>

#include "tron/wire/channel/PublishChannel.h"
#include "tuly/utils/FileWriter.h"

namespace tron
{
// Implementation of tron wire PublisChannel class based in files.
class FilePublishChannel : public PublishChannel
{    
private:
    static log4cxx::LoggerPtr logger;          
    const char delimiter = '\n'; // newline used as delimiter for strings (default used by std::getline())
    std::string comsBasePath;
    std::string pathComsFile;       // file for broadcasting the info
    tuly::FileWriter oFileWriter;
    
public:
    FilePublishChannel();
    FileServerChannel(int node, int channel);
    ~FilePublishChannel();

    std::string getComsFile() {return pathComsFile;};
        
    // open channel
    virtual bool open();
    // close channel
    virtual bool close();
    // send message to destination, returns false if nothing sent
    virtual bool sendMsg(std::string text);
    
    virtual bool newPublishing();
};
}
#endif
