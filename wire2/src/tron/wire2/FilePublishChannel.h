#ifndef __TRON_WIRE2_FILEPUBLISHCHANNEL_H
#define __TRON_WIRE2_FILEPUBLISHCHANNEL_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "tron/wire2/FileCommunicator.h"
#include "tron/wire/channel/PublishChannel.h"
#include "tuly/utils/FileWriter.h"

namespace tron
{
// Implementation of tron wire PublisChannel class based in files.
class FilePublishChannel : public PublishChannel, public FileCommunicator
{    
private:
    tuly::FileWriter oFileWriter;
    
public:
    FilePublishChannel();
    FilePublishChannel(int node, int channel);
    ~FilePublishChannel();

    // open channel
    virtual bool open();
    // close channel
    virtual bool close();
    // clear info in channel
    virtual bool clearInfo();
    // send message to destination, returns false if nothing sent
    virtual bool sendMsg(std::string text);
};
}
#endif
