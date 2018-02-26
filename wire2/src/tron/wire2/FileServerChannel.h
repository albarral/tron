#ifndef __TRON_WIRE2_FILESERVERCHANNEL_H
#define __TRON_WIRE2_FILESERVERCHANNEL_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <vector>
#include <log4cxx/logger.h>

#include "tron/wire/channel/ServerChannel.h"
#include "tuly/utils/FileReader.h"

namespace tron
{
// Implementation of tron wire ServerChannel class based in files.
class FileServerChannel : public ServerChannel
{    
private:
    static log4cxx::LoggerPtr logger;
    std::string comsBasePath;
    std::string pathComsFile;       // name of file used for coms
    tuly::FileReader oFileReader;     // file reader
    
public:
    FileServerChannel();
    FileServerChannel(int node, int channel);
    ~FileServerChannel();

    std::string getComsFile() {return pathComsFile;};
               
    // open channel
    virtual bool open();
    // close channel
    virtual bool close();
    // receive messages from origin, returns false if nothing received
    virtual bool receiveMessages(std::vector<std::string>& listMessages);
    
private:
    // force creation of coms file
    void createComsFile();
};
}
#endif
