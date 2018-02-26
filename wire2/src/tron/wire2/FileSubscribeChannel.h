#ifndef __TRON_WIRE2_FILESUSBSCRIBECHANNEL_H
#define __TRON_WIRE2_FILESUSBSCRIBECHANNEL_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <log4cxx/logger.h>

#include "tron/wire/channel/SubscribeChannel.h"
#include "tuly/utils/FileReader.h"

namespace tron
{
// Implementation of tron wire SubscribeChannel class based in files.
class FileSubscribeChannel : public SubscribeChannel
{    
private:
    static log4cxx::LoggerPtr logger;
    std::string comsBasePath;
    std::string pathComsFile;       // name of file used for coms
    tuly::FileReader oFileReader;     // file reader
    
public:
    FileSubscribeChannel();
    FileSubscribeChannel(int node, int channel);
    ~FileSubscribeChannel();

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
