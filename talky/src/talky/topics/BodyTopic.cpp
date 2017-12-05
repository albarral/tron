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
    createExpressiveCategory();
    createArtisticCategory();
    createExtraCategory();

    // build body role language and apply it to this topic
    BodyLanguage oBodyLanguage;            
    oBodyLanguage.build();
    applyLanguage(oBodyLanguage);                
}

// create expressive category
void BodyTopic::createExpressiveCategory()
{
    Category oCategory;
    oCategory.setTopicId(topic);
    oCategory.setId(BodyTopic::eCAT_BODY_EXPRESSIVE);

    Concept oConcept;
    // here the simple concepts that don't need a quantity
    std::vector<int> listSimpleConcepts{BodyTopic::eEXPRESS_HALT};
        
    for (int id=0; id<BodyTopic::eEXPRESS_DIM; id++)
    {
        oConcept.setMeaning(id);
        // simple concept
        if (Category::findValueInList(id, listSimpleConcepts))
            oConcept.setNeedsQuantity(false);
        // normal concept
        else
            oConcept.setNeedsQuantity(true);
        
        oCategory.addConcept(oConcept);
    }
    
    addCategory(oCategory);
}

// create artistic category
void BodyTopic::createArtisticCategory()
{
    Category oCategory;
    oCategory.setTopicId(topic);
    oCategory.setId(BodyTopic::eCAT_BODY_ARTISTIC);

    Concept oConcept;
    // here the simple concepts that don't need a quantity
    std::vector<int> listSimpleConcepts{BodyTopic::eARTISTIC_HALT};
        
    for (int id=0; id<BodyTopic::eARTISTIC_DIM; id++)
    {
        oConcept.setMeaning(id);
        // simple concept
        if (Category::findValueInList(id, listSimpleConcepts))
            oConcept.setNeedsQuantity(false);
        // normal concept
        else
            oConcept.setNeedsQuantity(true);

        oCategory.addConcept(oConcept);
    }
    
    addCategory(oCategory);
}

// create body extra category
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