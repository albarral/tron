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
    const char delimiter = '\n'; // newline used as delimiter for strings (default used by std::getline())
    std::string comsBasePath;
    std::string pathComsFile;       // file for broadcasting the info
    tuly::FileWriter oFileWriter;
    
public:
    ComyFilePublisher();
    ~ComyFilePublisher();

    std::string getComsFile() {return pathComsFile;};
        
    virtual void connect(std::string topic, std::string category);
    // starts a new publishing iteration
    virtual bool newPublishing();
   // info publishing method (writes data in file)
    virtual bool publishMessage(std::string text);
};
}
#endif
