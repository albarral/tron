#ifndef __TALKY_ARMTOPIC_H
#define __TALKY_ARMTOPIC_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/


#include "talky/base/Topic.h"

namespace talky
{
// Definition of arm topic concepts
 class ArmTopic : public Topic
{
public:
    /*! arm topic categories */
    enum eArmCategories
    {
        eCAT_ARM_JOINT,                  /*! joint category */
        eCAT_ARM_AXIS,                   /*! axis category  */
        eCAT_ARM_CYCLIC,                /*! cyclic category  */
        eCAT_ARM_EXTRA,                 /*! extra category  */
        eCAT_ARM_DIM
    };
    
    /*! joint category */
    enum eJointCat
    {
         eJOINT_HS_POS,                         /*! horizontal shoulder position (degrees)*/
         eJOINT_VS_POS,                         /*! vertical shoulder position (degrees) */
         eJOINT_ELB_POS,                        /*! elbow position (degrees) */
         eJOINT_HWRI_POS,                      /*! horizontal wrist position (degrees) */
         eJOINT_VWRI_POS,                      /*! vertical wrist position (degrees) */
         eJOINT_HS_STATE,                      /*! horizontal shoulder state*/
         eJOINT_VS_STATE,                      /*! vertical shoulder state */
         eJOINT_ELB_STATE,                    /*! elbow state */
         eJOINT_HWRI_STATE,                   /*! horizontal wrist state */
         eJOINT_VWRI_STATE,                   /*! vertical wrist state */
         eJOINT_DIM
    };

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
 
    /*! cyclic category  */
    enum eCyclicCat
    {
         // FRONTAL CYCLER
         eCYCLIC_FRONT_FREQ,            /*! frequency of frontal cycler (Hz) */
         eCYCLIC_FRONT_AMP,             /*! amplitude of frontal cycler (degrees) */
         eCYCLIC_FRONT_ANGLE,          /*! orientation of frontal cycler (degrees) */
         eCYCLIC_FRONT_START,          /*! start frontal cycler movement */
         eCYCLIC_FRONT_STOP,           /*! stop frontal cycler movement */
         // ARM MOVER
         eCYCLIC_MOVER_TURN,         /*! turns cyclic movement (degrees) */
         eCYCLIC_MOVER_WIDER,        /*! makes cyclic movement wider (1) or narrower (0) */
         eCYCLIC_MOVER_TALLER,      /*! makes cyclic movement taller (1) or shorter (0) */     
         eCYCLIC_MOVER_FASTER,      /*! makes cyclic movement faster (1) or slower (0) */
         eCYCLIC_MOVER_LAUNCH,      /*! launch specified movement (type) */
         eCYCLIC_MOVER_STOP,         /*! stop cyclic movement */
         eCYCLIC_DIM
    };
      
    /*! extra category  */
    enum eExtraCat
    {
        eEXTRA_ARM_STOP,                 /*! stop arm */
        eEXTRA_KEEP_TILT,                  /*! keep the tilt position */
        eEXTRA_AMY_END,                   /*! end amy */
        eEXTRA_DIM
    };
    
 public:    
    ArmTopic(); 
    // builds topic
    void build();

 private:    
    // create concept categories
    void createJointCategory();
    void createAxisCategory();
    void createCyclicCategory();
    void createExtraCategory();    

};
}
#endif
