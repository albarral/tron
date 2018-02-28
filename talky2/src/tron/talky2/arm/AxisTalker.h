#ifndef __TALKY2_ARM_AXISTALKER_H
#define __TALKY2_ARM_AXISTALKER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/talky2/Talker.h"

namespace tron
{
// Talker for arm axis topic
 class AxisTalker : public Talker
{
 public:
    /*! axis category  */
    enum eAxisCat
    {
         eAXIS_PAN_POS,                       /*! pan position (degrees) */
         eAXIS_TILT_POS,                       /*! tilt position (degrees) */
         eAXIS_RAD_POS,                       /*! radial position (cm) */
         eAXIS_PAN_SPEED,                     /*! pan speed (degrees/s) */
         eAXIS_TILT_SPEED,                     /*! tilt speed (degrees/s) */
         eAXIS_RAD_SPEED,                     /*! radial speed (cm/s) */
         eAXIS_DIM
    };

    /*! axis category names */
    const std::string AXIS_PAN_POS = "pan";                 /*! pan position (degrees) */
    const std::string AXIS_TILT_POS = "tilt";                   /*! tilt position (degrees) */
    const std::string AXIS_RAD_POS = "rad";                  /*! radial position (cm) */
    const std::string AXIS_PAN_SPEED = "vpan";            /*! pan speed (degrees/s) */
    const std::string AXIS_TILT_SPEED = "vtilt";              /*! tilt speed (degrees/s) */
    const std::string AXIS_RAD_SPEED = "vrad";             /*! radial speed (cm/s) */

 public:    
    AxisTalker(); 
    
 protected: 
    // fill maps with knowledge 
    virtual void buildKnowledge();      
    // complete talker name with topic word
    virtual void completeName();
    
};
}
#endif
