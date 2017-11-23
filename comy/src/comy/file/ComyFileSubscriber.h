#ifndef __COMY_FILESUSBSCRIBER_H
#define __COMY_FILESUSBSCRIBER_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <log4cxx/logger.h>

#include "comy/ComySubscriber.h"
#include "tuly/utils/FileReader.h"

namespace comy
{
// Implementation of the ComySubscriber class based in broadcasting messages through a shared file.
class ComyFileSubscriber : public ComySubscriber
{    
private:
    static log4cxx::LoggerPtr logger;
    std::string comsBasePath;
    std::string pathComsFile;       // name of file used for coms
    tuly::FileReader oFileReader;     // file reader
    
public:
    ComyFileSubscriber();
    ~ComyFileSubscriber();

    std::string getComsFile() {return pathComsFile;};

    virtual void connect(std::string topic, std::string category);    
   // read message from client, returns empty if nothing read
    virtual std::string readSingleMessage();    
    // get all new messages received
    virtual bool getNewMessages(std::vector<std::string>& listMessages); 
};
}
#endif
