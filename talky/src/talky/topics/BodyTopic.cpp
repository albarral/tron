/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "talky/topics/BodyTopic.h"
#include "talky/languages/BodyLanguage.h"
#include "talky/Topics.h"

namespace talky
{

BodyTopic::BodyTopic() 
{
    setTopicId(Topics::eTOPIC_BODYROLE);
}

void BodyTopic::build()
{
    reset();

    // create categories for body roles topic
    createArmMoverCategory();
    createExtraCategory();

    // build body role language and apply it to this topic
    BodyLanguage oBodyLanguage;            
    oBodyLanguage.build();
    applyLanguage(oBodyLanguage);                
}

// create concepts of joint category
void BodyTopic::createArmMoverCategory()
{
    Category oCategory;
    oCategory.setTopicId(topic);
    oCategory.setId(BodyTopic::eCAT_BODY_ARMMOVER);

    Concept oConcept;
    // all concepts here need a quantity
    oConcept.setNeedsQuantity(true);
        
    for (int id=0; id<BodyTopic::eARMMOVER_DIM; id++)
    {
        oConcept.setMeaning(id);
        oCategory.addConcept(oConcept);
    }
    
    addCategory(oCategory);
}


// create concepts of extra category
void BodyTopic::createExtraCategory()
{
    Category oCategory;
    oCategory.setTopicId(topic);
    oCategory.setId(BodyTopic::eCAT_BODY_EXTRA);

    Concept oConcept;
    // no concepts here need a quantity
    oConcept.setNeedsQuantity(false);
        
    for (int id=0; id<BodyTopic::eEXTRA_DIM; id++)
    {
        oConcept.setMeaning(id);
        oCategory.addConcept(oConcept);
    }
    
    addCategory(oCategory);
}
}