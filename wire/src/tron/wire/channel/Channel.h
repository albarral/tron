#ifndef __TRON_WIRE_CHANNEL_H
#define __TRON_WIRE_CHANNEL_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>

namespace tron
{
// Base class used to manage communications in a given channel.
// Multichannel coms: each channel is associated to a specific node & category.
class Channel
{        
 public:     
    /*! channel types */
    enum eTypes
    {
        eCHANNEL_UNICAST,           /*! unicast channel */
        eCHANNEL_BROADCAST,      /*! broadcast channel */
        eCHANNEL_DIM
    };    
    
protected:
    static log4cxx::LoggerPtr logger;    
    int type;                // channel type (one of eTypes)
    int node;               // associated node
    int channel;           // associated category 
    bool bopen;         // indicator of open channel
    std::string name;   // channel name
    
public:
    Channel();
    Channel(int node, int channel);

    int getType() {return type;};
    int getNode() {return node;};
    int getChannel() {return channel;};
    std::string getName() {return name;};
    
    // open channel
    virtual bool open() = 0;
    // close channel
    virtual bool close() = 0;
    
    bool isOpen() {return bopen;};
    
protected:
    // sets channel name
    void setName();
};
}
#endif
