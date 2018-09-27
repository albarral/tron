#ifndef __TRON_TOPICS_EXTRASECTION_H
#define __TRON_TOPICS_EXTRASECTION_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/topics/NodeSection.h"

namespace tron
{
// Definition of channels for the extra section (common to all nodes)
 class ExtraSection : public NodeSection
{
 public:
    static const std::string EXTRA_SECTION;   /*! name of extra section */

    /*! extra channels  */
    enum eChannels
    {
         eEXTRA_STOP,                     /*! emergency stop channel */
         eEXTRA_END,                       /*! end node channel */
         eEXTRA_DIM
    };

    /*! names of extra channels */
    const std::string EXTRA_STOP = "stop";                 /*! emergency stop */
    const std::string EXTRA_END = "end";                /*! end control process */

 public:    
    ExtraSection(int sectionCode); 
    
};
}
#endif
