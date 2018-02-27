#ifndef __TRON_ROBOT_ARMTOPIC_H
#define __TRON_ROBOT_ARMTOPIC_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

namespace tron
{
// Definition of arm topic concepts
 class ArmTopic 
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

    static std::string getTopicName(int topicId);
};
}
#endif
