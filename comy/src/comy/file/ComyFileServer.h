#ifndef __COMY_FILESERVER_H
#define __COMY_FILESERVER_H

/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>

#include "comy/ComyServer.h"
#include "tuly/utils/FileReader.h"
#include "tuly/utils/FileWriter.h"

namespace comy
{
// Implementation of ComyServer base class to allow external control of amy.
// The communication with the client is handled through a shared file.    
class ComyFileServer : public ComyServer
{    
private:
    static log4cxx::LoggerPtr logger;
    std::string comsBasePath;
    std::string pathClientServerFile;       // name of file used for coms
    tuly::FileReader oFileReader;     // file reader
    tuly::FileWriter oFileWriter;        // file writer
    
public:
    ComyFileServer();
    ~ComyFileServer();

    std::string getClientServerComsFile() {return pathClientServerFile;};
               
    virtual void connect();
   // read message from client, returns false if nothing read
    virtual bool readMessage();
        
};
}
#endif
