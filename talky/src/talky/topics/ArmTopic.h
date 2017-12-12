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
         eCYCLIC_FRONT1_FREQ,            /*! frequency of frontal cycler component 1 (Hz) */
         eCYCLIC_FRONT1_AMP,             /*! amplitude of frontal cycler component 1 (degrees) */
         eCYCLIC_FRONT1_ANGLE,          /*! orientation of frontal cycler component 1 (degrees) */
         eCYCLIC_FRONT2_FREQ,            /*! frequency of frontal cycler component 2 (Hz) */
         eCYCLIC_FRONT2_AMP,             /*! amplitude of frontal cycler component 2 (degrees) */
         eCYCLIC_FRONT2_ANGLE,          /*! orientation of frontal cycler component 2 (degrees) */
         eCYCLIC_FRONT_PHASE,          /*! phase difference of frontal cycler components (degrees) */
         eCYCLIC_FRONT_ACTION,          /*! start/stop frontal cycler movement */
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
