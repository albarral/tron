#ifndef __TALKY2_ARM_CYCLICTALKER_H
#define __TALKY2_ARM_CYCLICTALKER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/talky2/Talker.h"

namespace tron
{
// Talker for arm cyclic topic
 class CyclicTalker : public Talker
{
 public:
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

    /*! cyclic category names */
    // FRONTAL CYCLER
    const std::string CYCLIC_FRONT1_FREQ = "freq1";      /*! frequency of frontal cycler component 1 (Hz) */
    const std::string CYCLIC_FRONT1_AMP = "amp1";        /*! amplitude of frontal cycler component 1 (degrees) */
    const std::string CYCLIC_FRONT1_ANGLE = "ang1";      /*! orientation of frontal cycler component 1 (degrees) */
    const std::string CYCLIC_FRONT2_FREQ = "freq2";      /*! frequency of frontal cycler component 2 (Hz) */
    const std::string CYCLIC_FRONT2_AMP = "amp2";        /*! amplitude of frontal cycler component 2 (degrees) */
    const std::string CYCLIC_FRONT2_ANGLE = "ang2";      /*! orientation of frontal cycler component 2 (degrees) */
    const std::string CYCLIC_FRONT_PHASE = "phase";          /*! phase difference of frontal cycler components (degrees) */
    const std::string CYCLIC_FRONT_ACTION = "front";           /*! start/stop frontal cycler movement */

 public:    
    CyclicTalker(); 
    
 protected: 
    // fill maps with knowledge 
    virtual void buildKnowledge();      
    // complete talker name with topic word
    virtual void completeName();
    
};
}
#endif
