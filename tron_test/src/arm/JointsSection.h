#ifndef __AMY_INTERFACE_JOINTSSECTION_H
#define __AMY_INTERFACE_JOINTSSECTION_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/topics/NodeSection.h"

namespace amy
{
// Definition of arm joints section
 class JointsSection : public tron::NodeSection
{
 public:
    /*! joints section channels */
    enum eChannels
    {
         eJOINTS_HS,                         /*! horizontal shoulder position (degrees)*/
         eJOINTS_VS,                         /*! vertical shoulder position (degrees) */
         eJOINTS_ELB,                        /*! elbow position (degrees) */
         eJOINTS_HWRI,                      /*! horizontal wrist position (degrees) */
         eJOINTS_VWRI,                      /*! vertical wrist position (degrees) */
         eJOINTS_DIM
    };

 private:
    /*! joints section channel names */
    const std::string JOINTS_HS = "hs";          /*! horizontal shoulder position */
    const std::string JOINTS_VS = "vs";          /*! vertical shoulder position  */
    const std::string JOINTS_ELB = "elb";        /*! elbow position  */
    const std::string JOINTS_HWRI = "hwri";     /*! horizontal wrist position */
    const std::string JOINTS_VWRI = "vwri";      /*! vertical wrist  position */

 public:    
    JointsSection(); 
};
}
#endif
