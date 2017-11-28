/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <algorithm>

#include "talky/topics/ArmTopic.h"
#include "talky/languages/ArmLanguage.h"
#include "talky/Topics.h"

namespace talky
{

ArmTopic::ArmTopic() 
{
    setTopicId(Topics::eTOPIC_ARM);
}

void ArmTopic::build()
{
    reset();

    // create all arm topic categories
    createJointCategory();
    createAxisCategory();
    createCyclicCategory();
    createExtraCategory();
    
    // build arm language and apply it to this topic
    ArmLanguage oArmLanguage;            
    oArmLanguage.build();
    applyLanguage(oArmLanguage);                
}

// create concepts of joint category
void ArmTopic::createJointCategory()
{
    Category oCategory;        
    oCategory.setTopicId(topic);
    oCategory.setId(ArmTopic::eCAT_ARM_JOINT);

    Concept oConcept;
    // all concepts in this category need a quantity
    oConcept.setNeedsQuantity(true);
        
    for (int id=0; id<ArmTopic::eJOINT_DIM; id++)
    {
        oConcept.setMeaning(id);
        oCategory.addConcept(oConcept);
    }
    
    addCategory(oCategory);
}

// create concepts of axis category
void ArmTopic::createAxisCategory()
{
    Category oCategory;
    oCategory.setTopicId(topic);
    oCategory.setId(ArmTopic::eCAT_ARM_AXIS);

    Concept oConcept;
    // all concepts in this category need a quantity
    oConcept.setNeedsQuantity(true);
        
    for (int id=0; id<ArmTopic::eAXIS_DIM; id++)
    {
        oConcept.setMeaning(id);
        oCategory.addConcept(oConcept);
    }
    
    addCategory(oCategory);
}

// create concepts of cyclic category
void ArmTopic::createCyclicCategory() 
{
    Category oCategory;
    oCategory.setTopicId(topic);
    oCategory.setId(ArmTopic::eCAT_ARM_CYCLIC);

    // list of special concepts, those who don't need a quantity
    std::vector<int> listSpecialConcepts{
        ArmTopic::eCYCLIC_FRONT_START, 
        ArmTopic::eCYCLIC_FRONT_STOP};
    
    Concept oConcept;
        
    for (int id=0; id<ArmTopic::eCYCLIC_DIM; id++)
    {
        oConcept.setMeaning(id);
        
        // check if concept is special, and so doesn't need a quantity
        auto result = std::find(std::begin(listSpecialConcepts), std::end(listSpecialConcepts), id);
        if (result == std::end(listSpecialConcepts)) 
            oConcept.setNeedsQuantity(true);
        else
            oConcept.setNeedsQuantity(false);
            
        oCategory.addConcept(oConcept);
    }
    
    addCategory(oCategory);
}

// create concepts of extra category
void ArmTopic::createExtraCategory()
{
    Category oCategory;
    oCategory.setTopicId(topic);
    oCategory.setId(ArmTopic::eCAT_ARM_EXTRA);

    Concept oConcept;
    // all concepts in this category don't need a quantity
    oConcept.setNeedsQuantity(false);
        
    for (int id=0; id<ArmTopic::eEXTRA_DIM; id++)
    {
        oConcept.setMeaning(id);
        oCategory.addConcept(oConcept);
    }
    
    addCategory(oCategory);
}
}