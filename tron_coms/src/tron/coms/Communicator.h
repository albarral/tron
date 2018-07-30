#ifndef __TRON_COMS_COMMUNICATOR_H
#define __TRON_COMS_COMMUNICATOR_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>
#include <ignition/transport.hh>

namespace tron
{
// Base communicator class based in ignition transport lib.
class Communicator
{    
 public:     
    /*! communicator types */
    enum eTypes
    {
        eTYPE_SENDER,                  /*! communication sender */
        eTYPE_RECEIVER,                /*! communication receiver */
    };

protected:
    static log4cxx::LoggerPtr logger;
    ignition::transport::Node oNode;   
    int type;           // communicator type (sender or receiver)
        
public:
    Communicator();
    //~Communicator();
    
    int getType() {return type;};
    
    virtual void addChannel(std::string topic) = 0;
    
    virtual std::string toString() = 0;
};

}
#endif
