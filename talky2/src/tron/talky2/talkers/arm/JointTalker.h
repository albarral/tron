#ifndef __TALKY2_ARM_JOINTTALKER_H
#define __TALKY_ARM_JOINTTALKER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/talky2/Talker.h"

namespace tron
{
// Talker for arm joint topic
 class JointTalker : public Talker
{
 public:
    /*! joint category */
    enum eJointCat
    {
         eJOINT_HS_POS,                         /*! horizontal shoulder position (degrees)*/
         eJOINT_VS_POS,                         /*! vertical shoulder position (degrees) */
         eJOINT_ELB_POS,                        /*! elbow position (degrees) */
         eJOINT_HWRI_POS,                      /*! horizontal wrist position (degrees) */
         eJOINT_VWRI_POS,                      /*! vertical wrist position (degrees) */
         eJOINT_DIM
    };

    /*! joint category names */
    const std::string JOINT_HS_POS = "hs";          /*! horizontal shoulder position */
    const std::string JOINT_VS_POS = "vs";          /*! vertical shoulder position  */
    const std::string JOINT_ELB_POS = "elb";        /*! elbow position  */
    const std::string JOINT_HWRI_POS = "hwri";     /*! horizontal wrist position */
    const std::string JOINT_VWRI_POS = "vwri";      /*! vertical wrist  position */

 public:    
    JointTalker(); 
    
 protected: 
    // fill maps with knowledge 
    virtual void buildKnowledge();      
    // complete talker name with topic word
    virtual void completeName();
    
};
}
#endif
