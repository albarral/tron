#ifndef __TALKY2_BODY_ARTISTICTALKER_H
#define __TALKY2_BODY_ARTISTICTALKER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/talky2/Talker.h"

namespace tron
{
// Talker for the body artistic topic
 class ArtisticTalker : public Talker
{
 public:
    /*! artistic category */
    enum eArtistic
    {
        eARTISTIC_FIGURE,        // id of artistic figure to implement
        eARTISTIC_FREQ,       // frequency of cyclic figure (Hz) 
        eARTISTIC_SIZE,        // size of cyclic figure (degrees)
        eARTISTIC_ORIENTATION,  // orientation of cyclic figure (degrees)
        eARTISTIC_RELFACTOR,    // relative xy factor of cyclic figure 
        eARTISTIC_HALT,                // halt ongoing artistic movement
        eARTISTIC_DIM
    };

    /*! artistic category */    
    const std::string ARTISTIC_FIGURE = "figure";             /*! id of artistic figure to implement (integer) */
    const std::string ARTISTIC_FREQ = "freq";                  /*! frequency of cyclic figure (Hz) */
    const std::string ARTISTIC_SIZE = "size";                   /*! size of cyclic figure (degrees) */
    const std::string ARTISTIC_ORIENTATION = "angle";     /*! orientation of cyclic figure (degrees) */
    const std::string ARTISTIC_RELFACTOR = "factor";       /*! relative xy factor of cyclic figure */
    const std::string ARTISTIC_HALT = "halt";                   /*! halt ongoing artistic movement */

 public:    
    ArtisticTalker(); 
    
 protected: 
    // fill maps with knowledge 
    virtual void buildKnowledge();      
    // complete talker name with topic word
    virtual void completeName();
    
};
}
#endif
