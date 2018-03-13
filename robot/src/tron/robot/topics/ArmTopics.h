#ifndef __TRON_ROBOT_ARMTOPICS_H
#define __TRON_ROBOT_ARMTOPICS_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/robot/topics/NodeTopics.h"

namespace tron
{
// Definition of arm topics
 class ArmTopics : public NodeTopics
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

 public:     
     ArmTopics();
     
protected:
     virtual void fillMap();
};
}
#endif
