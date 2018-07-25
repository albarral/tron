#ifndef __AMY_INTERFACE_AXESSECTION_H
#define __AMY_INTERFACE_AXESSECTION_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/topics/NodeSection.h"

namespace amy
{
// Definition of arm axes section
 class AxesSection : public tron::NodeSection
{
 public:
    /*! axes section channels  */
    enum eChannels
    {
         eAXES_PAN,                       /*! pan position (degrees) */
         eAXES_TILT,                       /*! tilt position (degrees) */
         eAXES_RAD,                       /*! radial position (cm) */
         eAXES_PAN_SPEED,                     /*! pan speed (degrees/s) */
         eAXES_TILT_SPEED,                     /*! tilt speed (degrees/s) */
         eAXES_RAD_SPEED,                     /*! radial speed (cm/s) */
         eAXES_KEEP_TILT,                       /*! keep the tilt position */         
         eAXES_DIM
    };

 private:
    /*! axes section channels names */
    const std::string AXES_PAN = "pan";                 /*! pan position (degrees) */
    const std::string AXES_TILT = "tilt";                   /*! tilt position (degrees) */
    const std::string AXES_RAD = "rad";                  /*! radial position (cm) */
    const std::string AXES_PAN_SPEED = "vpan";            /*! pan speed (degrees/s) */
    const std::string AXES_TILT_SPEED = "vtilt";              /*! tilt speed (degrees/s) */
    const std::string AXES_RAD_SPEED = "vrad";             /*! radial speed (cm/s) */
    const std::string AXES_KEEP_TILT = "keeptilt";               /*! keep the tilt position */

 public:    
    AxesSection(); 
    
};
}
#endif
