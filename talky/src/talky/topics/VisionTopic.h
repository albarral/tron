#ifndef __TALKY_VISIONTOPIC_H
#define __TALKY_VISIONTOPIC_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/


#include "talky/base/Topic.h"

namespace talky
{
// Definition of vision topic concepts
 class VisionTopic : public Topic
{
public:
    /*! categories of vision topic */
    enum eVisionCategories
    {
        eCAT_VISION_EXTRA,                        /*! extra category */
        eCAT_VISION_DIM
    };
    
    /*! extra category  */
    enum eExtraCat
    {
        eEXTRA_VISION_END,                   /*! end vision process */
        eEXTRA_DIM
    };
    
 public:    
    VisionTopic(); 
    // builds topic
    void build();

 private:    
    // create topic categories
    void createExtraCategory();    

};
}
#endif
