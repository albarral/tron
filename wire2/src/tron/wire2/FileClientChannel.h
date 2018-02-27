#ifndef __TRON_WIRE2_FILECLIENTCHANNEL_H
#define __TRON_WIRE2_FILECLIENTCHANNEL_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "tron/wire2/FileCommunicator.h"
#include "tron/wire/channel/ClientChannel.h"
#include "tuly/utils/FileWriter.h"

namespace tron
{
// Implementation of tron wire ClientChannel class based in files.
class FileClientChannel : public ClientChannel, public FileCommunicator
{    
private:
    tuly::FileWriter oFileWriter;
    
public:
    FileClientChannel();
    FileClientChannel(int node, int channel);
    ~FileClientChannel();
        
    // open channel
    virtual bool open();
    // close channel
    virtual bool close();
    // send message to destination, returns false if nothing sent
    virtual bool sendMsg(std::string text);
};
}
#endif
