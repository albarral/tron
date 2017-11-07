#ifndef __COMY_FILECLIENT_H
#define __COMY_FILECLIENT_H

/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>

#include "comy/ComyClient.h"
#include "tuly/utils/FileWriter.h"

namespace comy
{
class ComyFileClient : public ComyClient
{    
private:
    static log4cxx::LoggerPtr logger;    
    std::string comsBasePath;
    std::string pathComsFile;
    tuly::FileWriter oFileWriter;
    
public:
    ComyFileClient();
    ~ComyFileClient();

    std::string getClientServerComsFile() {return pathComsFile;};
        
    virtual void connect(std::string topic, std::string category);
   // send message to server, returns false if nothing sent
    virtual bool sendMessage(std::string text);
};
}
#endif
