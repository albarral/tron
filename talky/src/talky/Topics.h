#ifndef __TALKY_TOPICS_H
#define __TALKY_TOPICS_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

namespace talky
{
/** 
 * Class used to define topics for communication (and their standard names).
 */
 class Topics
{
 public:     
    /*! topic ids */
    enum eTopics
    {
        eTOPIC_ARM,                  /*! arm topic */
        eTOPIC_HAND,                /*! hand topic */
        eTOPIC_VISION,              /*! vision topic */
        eTOPIC_HEAD,                /*! head topic */
        eTOPIC_WHEELS,            /*! wheels topic */  
        eTOPIC_DIM
    };
     
    // topic names
    static const std::string ARM_TOPIC;    
    static const std::string HAND_TOPIC;    
    static const std::string VISION_TOPIC;    
    static const std::string HEAD_TOPIC;    
    static const std::string WHEELS_TOPIC;    
    // auxiliary values
    static const int INVALID_VALUE = -1;
    static const std::string EMPTY_VALUE;  
    
    static std::string getTopicName(int topicId);
};
}
#endif
