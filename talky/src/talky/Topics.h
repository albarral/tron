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
        eTOPIC_ARM,                  /*! arm topic id */
        eTOPIC_HAND,                /*! hand topic id */
        eTOPIC_VISION,              /*! vision topic id */
        eTOPIC_HEAD,                /*! head topic id */
        eTOPIC_WHEELS,            /*! wheels topic id */  
        eTOPIC_DIM
    };
     
    // topic names
    static const std::string ARM_TOPIC;         /*! arm topic name */
    static const std::string HAND_TOPIC;        /*! hand topic name */
    static const std::string VISION_TOPIC;      /*! vision topic name */
    static const std::string HEAD_TOPIC;        /*! head topic name */
    static const std::string WHEELS_TOPIC;    /*! wheels topic name */
    // auxiliary values
    static const int INVALID_VALUE = -1;
    static const std::string EMPTY_VALUE;  
    static const std::string FIELD_SEPARATOR;      /*! character used to separate fields in messages */

    static std::string getTopicName(int topicId);
};
}
#endif
