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
    std::string filename;
    tuly::FileWriter oFileWriter;
    
public:
    ComyFileClient();
    ~ComyFileClient();

    std::string getFilename() {return filename;};
        
private:
   // send message to server (specific for each ComyClient implementation)
    virtual void sendMessage(std::string text);
};
}
#endif
