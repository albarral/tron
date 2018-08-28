#ifndef __TRON_TOPICS_TOPIC_H
#define __TRON_TOPICS_TOPIC_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

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
    int type;                       // topic type (one of eTypes)
    std::string nodeName;       
    std::string sectionName;    
    std::string channelName;  
    bool built;
    std::string topicName;              // topic name (automatically built)
     
 public:     
    Topic();     
    
    void set(int node, int section, int channel, int type);

    int getNode() {return node;};
    int getSection() {return section;};
    int getChannel() {return channel;};
    int getType() {return type;};
    
    std::string getNodeName() {return nodeName;};
    std::string getSectionName() {return sectionName;};
    std::string getChannelName() {return channelName;};
    void setNodeName(std::string value) {nodeName = value;};
    void setSectionName(std::string value) {sectionName = value;};
    void setChannelName(std::string value) {channelName = value;};
    
    // build topic name
    void buildName();
    bool isBuilt() {return built;};
    std::string getTopicName() {return topicName;};

 private:
    std::string getTypeName(int type);

    //  return topic description
//    std::string toString();
};
}
#endif
