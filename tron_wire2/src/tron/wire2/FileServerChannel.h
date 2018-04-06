#ifndef __TRON_WIRE2_FILESERVERCHANNEL_H
#define __TRON_WIRE2_FILESERVERCHANNEL_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <vector>

#include "tron/wire2/FileCommunicator.h"
#include "tron/wire/channel/ServerChannel.h"
#include "tron/tools/FileReader.h"

namespace tron
{
// Implementation of tron wire ServerChannel class based in files.
class FileServerChannel : public ServerChannel, public FileCommunicator
{    
private:
    FileReader oFileReader;     // file reader
    
public:
    FileServerChannel();
    FileServerChannel(int node, int channel);
    ~FileServerChannel();

    // open channel
    virtual bool open();
    // close channel
    virtual bool close();
    // clear info in channel
    virtual bool clearInfo();
    // receive messages from origin, returns false if nothing received
    virtual bool receiveMessages(std::vector<std::string>& listMessages);
};
}
#endif
