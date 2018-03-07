#ifndef __TALKY2_BASICTALKER_H
#define __TALKY2_BASICTALKER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/talky2/Talker.h"

namespace tron
{
// Basic common Talker for all nodes
 class BasicTalker : public Talker
{
 public:
    /*! extra category  */
    enum eExtraCat
    {
        eEXTRA_ARM_STOP,                 /*! stop arm */
        eEXTRA_ARM_END,                   /*! end process */
        eEXTRA_DIM
    };

    /*! extra category names */
    const std::string EXTRA_ARM_STOP = "stop";                  /*! stop arm */
    const std::string EXTRA_AMY_END = "end";                    /*! end arm process */

 public:    
    BasicTalker(); 
    
 protected: 
    // fill maps with knowledge 
    virtual void buildKnowledge();      
    // complete talker name with topic word
    virtual void completeName();
    
};
}
#endif
