#ifndef __TALKY_BODYTOPIC_H
#define __TALKY_BODYTOPIC_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/


#include "talky/base/Topic.h"

namespace talky
{
// Definition of body role topic concepts
 class BodyTopic : public Topic
{
public:
    /*! categories of body role topic */
    enum eBodyCategories
    {
        eCAT_BODY_EXPRESSIVE,                /*! expressive category */
        eCAT_BODY_ARTISTIC,                     /*! artistic category */
        eCAT_BODY_EXTRA,                        /*! extra category */
        eCAT_BODY_DIM
    };
    
    /*! expressive category  */
    enum eExpressiveCat
    {
        eEXPRESS_FEELING,                   /*! express given feeling */
        eEXPRESS_HALT,                        /*! halt expressive action */
        eEXPRESS_DIM
    };
      
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

    /*! extra category  */
    enum eExtraCat
    {
        eEXTRA_BODY_END,                   /*! end body role process */
        eEXTRA_DIM
    };
    
 public:    
    BodyTopic(); 
    // builds topic
    void build();

 private:    
    // create topic categories
    void createExpressiveCategory();
    void createArtisticCategory();
    void createExtraCategory();    

};
}
#endif
