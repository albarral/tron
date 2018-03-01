#ifndef __TRON_ROBOT_ARMTOPICS_H
#define __TRON_ROBOT_ARMTOPICS_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "tuly/utils2/CodeMap.h"

namespace tron
{
// Definition of arm topics
 class ArmTopics 
{
public:
    /*! arm topics */
    enum eArmTopics
    {
        eARM_JOINT,                  /*! joint topic */
        eARM_AXIS,                   /*! axis topic  */
        eARM_CYCLIC,                /*! cyclic topic  */
        eARM_EXTRA,                 /*! extra topic  */
        eARM_DIM
    };

    /*! arm topic names */
    static const std::string ARM_JOINT;
    static const std::string ARM_AXIS;
    static const std::string ARM_CYCLIC;
    static const std::string ARM_EXTRA;

 private:         
     tuly::CodeMap oTopicsMap;                      /*! code map for arm topics */    

 public:     
     ArmTopics();
     
    // gets name for given topic code
    std::string getName4Topic(int topic);
    // gets code for given topic name
    int getCode4Topic(std::string topicName);
    
};
}
#endif
