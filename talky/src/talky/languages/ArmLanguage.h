#ifndef __TALKY_ARMLANGUAGE_H
#define __TALKY_ARMLANGUAGE_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "talky/base/Language.h"

namespace talky
{
// Class defining the language for the arm topic.
 class ArmLanguage: public Language
{
 public:
    /*! arm topic categories (names) */
    const std::string CAT_ARM_JOINT = "joint";
    const std::string CAT_ARM_AXIS = "axis";
    const std::string CAT_ARM_CYCLIC = "cyclic";
    const std::string CAT_ARM_EXTRA = "extra";    
    /*! joint category names */
    const std::string JOINT_HS_POS = "hs";          /*! horizontal shoulder position */
    const std::string JOINT_VS_POS = "vs";          /*! vertical shoulder position  */
    const std::string JOINT_ELB_POS = "elb";        /*! elbow position  */
    const std::string JOINT_HWRI_POS = "hwri";     /*! horizontal wrist position */
    const std::string JOINT_VWRI_POS = "vwri";      /*! vertical wrist  position */
    const std::string JOINT_HS_STATE = "hs_state";          /*! horizontal shoulder state */
    const std::string JOINT_VS_STATE = "vs_state";          /*! vertical shoulder state  */
    const std::string JOINT_ELB_STATE = "elb_state";        /*! elbow state  */
    const std::string JOINT_HWRI_STATE = "hwri_state";     /*! horizontal wrist state */
    const std::string JOINT_VWRI_STATE = "vwri_state";      /*! vertical wrist state */
    /*! axis category names */
    const std::string AXIS_PAN_POS = "pan";                 /*! pan position (degrees) */
    const std::string AXIS_TILT_POS = "tilt";                   /*! tilt position (degrees) */
    const std::string AXIS_RAD_POS = "rad";                  /*! radial position (cm) */
    const std::string AXIS_PAN_SPEED = "vpan";            /*! pan speed (degrees/s) */
    const std::string AXIS_TILT_SPEED = "vtilt";              /*! tilt speed (degrees/s) */
    const std::string AXIS_RAD_SPEED = "vrad";             /*! radial speed (cm/s) */
    /*! cyclic category names */
    // FRONTAL CYCLER
    const std::string CYCLIC_FRONT_FREQ = "freq1";      /*! frequency of frontal cycler (Hz) */
    const std::string CYCLIC_FRONT_AMP = "amp1";        /*! amplitude of frontal cycler (degrees) */
    const std::string CYCLIC_FRONT_ANGLE = "ang1";      /*! orientation of frontal cycler (degrees) */
    const std::string CYCLIC_FRONT_START = "go1";       /*! start frontal cycler movement */
    const std::string CYCLIC_FRONT_STOP = "end1";       /*! stop frontal cycler movement */
    // ARM MOVER
    const std::string CYCLIC_MOVER_TURN = "turn";           /*! turns cyclic movement (degrees) */
    const std::string CYCLIC_MOVER_WIDER = "wider";         /*! makes cyclic movement wider (1) or narrower (0) */
    const std::string CYCLIC_MOVER_TALLER = "taller";       /*! makes cyclic movement taller (1) or shorter (0) */  
    const std::string CYCLIC_MOVER_FASTER = "faster";       /*! makes cyclic movement faster (1) or slower (0) */
    const std::string CYCLIC_MOVER_LAUNCH = "move";      /*! launch specified movement (type) */
    const std::string CYCLIC_MOVER_STOP = "stop";           /*! stop cyclic movement */
    /*! extra category names */
    const std::string EXTRA_ARM_STOP = "stop";                  /*! stop arm */
    const std::string EXTRA_KEEP_TILT = "keep";                   /*! keep the tilt position */
    const std::string EXTRA_AMY_END = "end";                    /*! end arm process */

 public:    
    ArmLanguage(); 
    // builds language
    virtual void build();

 private:    
    // create category slangs
    void defineJointCategory();
    void defineAxisCategory();
    void defineCyclicCategory();
    void defineExtraCategory();    
};
}
#endif
