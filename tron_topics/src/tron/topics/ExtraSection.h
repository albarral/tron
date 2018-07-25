#ifndef __TRON2_ROBOT2_COMMON_EXTRATOPIC_H
#define __TRON2_ROBOT2_COMMON_EXTRATOPIC_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron2/robot/Topic.h"

namespace tron2
{
// Concepts definition for the common extra topic
 class ExtraTopic : public Topic
{
 public:
    /*! extra concepts  */
    enum eConcepts
    {
         eEXTRA_STOP,                       /*! emergency stop */
         eEXTRA_END,                       /*! end control process */
         eEXTRA_DIM
    };

    /*! extra concepts names */
    const std::string EXTRA_STOP = "stop";                 /*! emergency stop */
    const std::string EXTRA_END = "end";                /*! end control process */

 public:    
    ExtraTopic(); 
    
 private: 
    virtual void fillConcepts();      
    
};
}
#endif
