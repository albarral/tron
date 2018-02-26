#ifndef __TRON_WIRE2_FILECLIENTCHANNEL_H
#define __TRON_WIRE2_FILECLIENTCHANNEL_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>

#include "tron/wire/channel/ClientChannel.h"
#include "tuly/utils/FileWriter.h"

namespace tron
{
// Implementation of tron wire ClientChannel class based in files.
class FileClientChannel : public ClientChannel
{    
private:
    static log4cxx::LoggerPtr logger;    
    const char delimiter = '\n'; // newline used as delimiter for strings (default used by std::getline())
    std::string comsBasePath;
    std::string pathComsFile;
    tuly::FileWriter oFileWriter;
    
public:
    FileClientChannel();
    FileClientChannel(int node, int channel);
    ~FileClientChannel();

    std::string getClientServerComsFile() {return pathComsFile;};
        
    // open channel
    virtual bool open();
    // close channel
    virtual bool close();
    // send message to destination, returns false if nothing sent
    virtual bool sendMsg(std::string text);
};
}
#endif
