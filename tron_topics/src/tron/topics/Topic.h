#ifndef __TRON_TOPICS_TOPIC_H
#define __TRON_TOPICS_TOPIC_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "tron/topics/Node.h"

namespace tron
{
// A topic is the name associated to an IPC communications channel.
// It's defined by 4 elements: node, section, channel and type (control or sensor).
 class Topic
{    
 public:
    /*! topic types  */
    enum eTypes
    {
         eTYPE_CONTROL,                     /*! control channel */
         eTYPE_SENSOR,                       /*! sensor channel */
         eTYPE_DIM
    };

 private:
    std::string CONTROL_TYPE = "CO";    /*! control channel name */
    std::string SENSOR_TYPE = "SO";      /*! sensor channel name */
    int node;       
    int section;    
    int channel;   
    int type;                 // topic type (one of eTypes)
    std::string name;   // topic name (automatically built)
    bool built;
     
 public:     
    Topic();     
    
    void set(int node, int section, int channel, int type);

    int getNode() {return node;};
    int getSection() {return section;};
    int getChannel() {return channel;};
    int getType() {return type;};
    std::string getTopicName() {return name;};
    bool isBuilt() {return built;};
        
    // build topic name for given node
    std::string build4Node(Node& oNode);

 private:
    std::string getTypeName(int type);
};
}
#endif
