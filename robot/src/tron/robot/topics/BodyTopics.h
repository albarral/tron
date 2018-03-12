#ifndef __TRON_ROBOT_BODYTOPICS_H
#define __TRON_ROBOT_BODYTOPICS_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "tuly/utils2/CodeMap.h"

namespace tron
{
// Definition of body topics
 class BodyTopics 
{
public:
    /*! body topics */
    enum eBodyTopics
    {
        eBODY_COMFORTABLE,            /*! comfortable category */
        eBODY_EXPRESSIVE,                /*! expressive category */
        eBODY_ARTISTIC,                     /*! artistic category */
        eBODY_EXTRA,                        /*! extra category */
        eBODY_DIM
    };

    /*! body topic names */
    static const std::string BODY_COMFORTABLE;
    static const std::string BODY_EXPRESSIVE;
    static const std::string BODY_ARTISTIC;
    static const std::string BODY_EXTRA;

 private:         
     tuly::CodeMap oTopicsMap;                      /*! code map for body topics */    

 public:     
     BodyTopics();
     
    // gets name for given topic code
    std::string getName4Topic(int topic);
    // gets code for given topic name
    int getCode4Topic(std::string topicName);
    
};
}
#endif
