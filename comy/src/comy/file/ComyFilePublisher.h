#ifndef __COMY_FILEPUBLISHER_H
#define __COMY_FILEPUBLISHER_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>

#include "comy/ComyPublisher.h"
#include "tuly/utils/FileWriter.h"

namespace comy
{
// Implementation of the ComyPublisher class based in broadcasting messages through a shared file.
class ComyFilePublisher : public ComyPublisher
{    
private:
    static log4cxx::LoggerPtr logger;    
    std::string filePathPS;       // file for broadcasting the info
    tuly::FileWriter oFileWriter;
    
public:
    ComyFilePublisher();
    ~ComyFilePublisher();

    virtual void init();
    std::string getFilename() {return filePathPS;};
        
private:
   // info publishing method (writes data in file)
    virtual void publishInfo(std::string rawMessage);
};
}
#endif
