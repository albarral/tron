#ifndef __TALKY2_BASICTALKER_H
#define __TALKY2_BASICTALKER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/talky2/Talker.h"

namespace tron
{
// Basic Talker for any node
 class BasicTalker : public Talker
{
 public:
    /*! basic category  */
    enum eBasicCat
    {
        eBASIC_FULL_STOP,                        /*! full stop (emergency) */
        eBASIC_CONTROL_END,                   /*! end control process */
        eBASIC_DIM
    };

    /*! extra category names */
    const std::string BASIC_FULL_STOP = "stop";                  /*! full stop (emergency) */
    const std::string BASIC_CONTROL_END = "end";                    /*! end control process */

 public:    
    BasicTalker(int node, int topic); 
    
 protected: 
    // fill maps with knowledge 
    virtual void buildKnowledge();      
    // complete talker name with topic word
    virtual void completeName();
    
};
}
#endif
