#ifndef __TALKY_VISIONLANGUAGE_H
#define __TALKY_VISIONLANGUAGE_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "talky/base/Language.h"

namespace talky
{
// Class defining the language for the vision topic.
 class VisionLanguage: public Language
{
 public:
    /*! vision categories */
    const std::string CAT_VISION_EXTRA = "extra";    /*! extra category */

    /*! extra category */
    const std::string EXTRA_VISION_END = "end";         /*! end vision process */

 public:    
    VisionLanguage(); 
    // builds language
    virtual void build();

 private:    
    // create category slangs
    void defineExtraCategory();    
};
}
#endif
