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
        eCAT_BODY_ARMMOVER,                  /*! arm mover category */
        eCAT_BODY_EXTRA,                        /*! extra category */
        eCAT_BODY_DIM
    };
    
    /*! arm mover category */
    enum eArmMover
    {
        eARMMOVER_TYPE,             /*! set movement type (integer) */
        eARMMOVER_ACTION,          /*! start/stop movement (boolean) */
        eARMMOVER_TURN,             /*! change movement orientation (degrees) */
        eARMMOVER_WIDER,            /*! change movement width (boolean) */
        eARMMOVER_TALLER,           /*! change movement height (boolean) */
        eARMMOVER_FASTER,           /*! change movement speed (boolean) */
        eARMMOVER_DIM
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
    // create concept categories
    void createArmMoverCategory();
    void createExtraCategory();    

};
}
#endif
