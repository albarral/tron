/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "talky/topics/VisionTopic.h"
#include "talky/languages/VisionLanguage.h"
#include "talky/Topics.h"

namespace talky
{

VisionTopic::VisionTopic() 
{
    setTopicId(Topics::eTOPIC_VISION);
}

void VisionTopic::build()
{
    reset();

    // create categories for visions topic
    createExtraCategory();

    // build vision language and apply it to this topic
    VisionLanguage oVisionLanguage;            
    oVisionLanguage.build();
    applyLanguage(oVisionLanguage);                
}


// create body extra category
void VisionTopic::createExtraCategory()
{
    Category oCategory;
    oCategory.setTopicId(topic);
    oCategory.setId(VisionTopic::eCAT_VISION_EXTRA);

    Concept oConcept;
    // no concepts here need a quantity
    oConcept.setNeedsQuantity(false);
        
    for (int id=0; id<VisionTopic::eEXTRA_DIM; id++)
    {
        oConcept.setMeaning(id);
        oCategory.addConcept(oConcept);
    }
    
    addCategory(oCategory);
}
}