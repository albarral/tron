#ifndef __TALKY2_BODY_EXPRESSIVETALKER_H
#define __TALKY2_BODY_EXPRESSIVETALKER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/talky2/Talker.h"

namespace tron
{
// Talker for the body expressive topic
 class ExpressiveTalker : public Talker
{
 public:
    /*! expressive category  */
    enum eExpressiveCat
    {
        eEXPRESS_FEELING,                   /*! express given feeling */
        eEXPRESS_HALT,                        /*! halt expressive action */
        eEXPRESS_DIM
    };

    /*! expressive category */    
    const std::string EXPRESS_FEELING = "feel";      /*! set feeling to express (integer) */
    const std::string EXPRESS_HALT = "halt";          /*! halt expression */

 public:    
    ExpressiveTalker(); 
    
 protected: 
    // fill maps with knowledge 
    virtual void buildKnowledge();      
    // complete talker name with topic word
    virtual void completeName();
    
};
}
#endif
