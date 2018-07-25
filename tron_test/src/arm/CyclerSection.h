#ifndef __AMY_INTERFACE_CYCLERSECTION_H
#define __AMY_INTERFACE_CYCLERSECTION_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/topics/NodeSection.h"

namespace amy
{
// Definition of arm cycler section
 class CyclerSection : public tron::NodeSection
{
 public:
    /*! cycler section channels  */
    enum eChannels
    {
         eCYCLER_MAIN_FREQ,            /*! frequency of main cyclic component (Hz) */
         eCYCLER_MAIN_AMP,             /*! amplitude of main cyclic component  (degrees) */
         eCYCLER_MAIN_ANGLE,          /*! orientation of main cyclic component (degrees) */
         eCYCLER_MAIN_PHASE,          /*! phase of main cyclic component (degrees) */
         eCYCLER_SEC_FREQ,            /*! frequency of secondary cyclic component (Hz) */
         eCYCLER_SEC_AMP,             /*! amplitude of secondary cyclic component (degrees) */
         eCYCLER_SEC_ANGLE,          /*! orientation of secondary cyclic component (degrees) */
         eCYCLER_SEC_PHASE,          /*! phase of secondary cyclic component (degrees) */
         eCYCLER_ACTION,                  /*! start/stop cycler movement */
         eCYCLER_DIM
    };

 
 private:
    /*! cycler section channels names */
    const std::string CYCLER_MAIN_FREQ = "freq";      /*! frequency of main cyclic component (Hz) */
    const std::string CYCLER_MAIN_AMP = "amp";        /*! amplitude of main cyclic component (degrees) */
    const std::string CYCLER_MAIN_ANGLE = "angle";      /*! orientation of main cyclic component (degrees) */
    const std::string CYCLER_MAIN_PHASE = "phase";  /*! phase of main cyclic component (degrees) */
    const std::string CYCLER_SEC_FREQ = "freq2";      /*! frequency of secondary cyclic component (Hz) */
    const std::string CYCLER_SEC_AMP = "amp2";        /*! amplitude of secondary cyclic component (degrees) */
    const std::string CYCLER_SEC_ANGLE = "angle2";      /*! orientation of secondary cyclic component (degrees) */
    const std::string CYCLER_SEC_PHASE = "phase2";  /*! phase of secondary cyclic component (degrees) */
    const std::string CYCLER_ACTION = "go";                  /*! start/stop cyclic movement */

 public:    
    CyclerSection(); 
    
};
}
#endif
