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
    std::string filename;       // name of file used for coms
    tuly::FileReader oFileReader;     // file reader
    
public:
    ComyFileSubscriber();
    ~ComyFileSubscriber();

    virtual void init();
    
    std::string getFilename() {return filename;};

private:
   // info reading method (read data from file)
    virtual bool readInfo();
    
};
}
#endif
