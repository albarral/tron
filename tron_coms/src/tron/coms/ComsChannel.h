#ifndef __TRON_COMS_COMSCHANNEL_H
#define __TRON_COMS_COMSCHANNEL_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>
#include <ignition/transport.hh>

namespace tron
{
// Base class for communication channel classes.
// A channel is defined by 4 elements: node, section, type and channel.
// A channel can be of 3 types: control channel, sensor channel and parameters channel.
// Each channel will have an associated topic (an ignition transport concept) of the form: node/section/type/channel.
class ComsChannel 
{    
public:
    static const std::string CONTROL_CHANNEL;                 /*! control channel */
    static const std::string SENSOR_CHANNEL;                 /*! sensor channel */
    static const std::string PARAM_CHANNEL;                 /*! parameter channel */
        
    /*! channel types  */
    enum eTypes
    {
         eCHANNEL_UNDEFINED,                     /*! undefined channel */
         eCHANNEL_CONTROL,                     /*! control channel */
         eCHANNEL_SENSOR,                       /*! sensor channel */
         eCHANNEL_PARAM,                        /*! parameter channel */
         eCHANNEL_DIM
    };

protected:
    static log4cxx::LoggerPtr logger;
    int type;                       // channel type (one of eTypes)
    std::string nodeName;       
    std::string sectionName;    
    std::string channelName;   
    std::string topic;              // topic name
    bool bconnected;            // channel is connected (has a registered publisher or subscriber) 
        
public:
    ComsChannel();
    //~ComsChannel();
    
    // set channel elements
    void setChannel(std::string node, std::string section, std::string channel, int type);
    // connect channel
    virtual bool connect(ignition::transport::Node& oNode) = 0;
    bool isConnected() {return bconnected;};
    
    int getType() {return type;};
    std::string getNodeName() {return nodeName;};
    std::string getSectionName() {return sectionName;};
    std::string getChannelName() {return channelName;};
    std::string getTopic() {return topic;};
    
    static std::string getTypeName(int type);
};

}
#endif
