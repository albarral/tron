#ifndef __COMY_FILESERVER_H
#define __COMY_FILESERVER_H

/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <vector>
#include <log4cxx/logger.h>

#include "comy/ComyServer.h"
#include "tuly/utils/FileReader.h"

namespace comy
{
// Implementation of ComyServer base class to allow external control of amy.
// The communication with the client is handled through a shared file.    
class ComyFileServer : public ComyServer
{    
private:
    static log4cxx::LoggerPtr logger;
    std::string comsBasePath;
    std::string pathComsFile;       // name of file used for coms
    tuly::FileReader oFileReader;     // file reader
    
public:
    ComyFileServer();
    ~ComyFileServer();

    std::string getComsFile() {return pathComsFile;};
               
    virtual void connect(std::string topic, std::string category);
   // read message from client, returns empty if nothing read
    virtual std::string readSingleMessage();    
    // get all new messages received
    virtual bool getNewMessages(std::vector<std::string>& listMessages); 
        
private:
    // force creation of coms file
    void createComsFile();
};
}
#endif
