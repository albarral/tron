/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "talky/languages/VisionLanguage.h"
#include "talky/base/Slang.h"
#include "talky/topics/VisionTopic.h"
#include "talky/Topics.h"

namespace talky
{

VisionLanguage::VisionLanguage() 
{
}

void VisionLanguage::build()
{
    reset();

    // set vision topic
    setTopic(Topics::eTOPIC_VISION);
    // define categories
    defineFocusCategory();
    defineExtraCategory();
}

// create slang for focus category
void VisionLanguage::defineFocusCategory()
{
    int category = VisionTopic::eCAT_VISION_FOCUS;
    addCategory(category, VisionLanguage::CAT_VISION_FOCUS);

    Slang oSlang;    
    oSlang.setCategory(category);
    oSlang.addWord(VisionTopic::eFOCUS_SHIFT, VisionLanguage::FOCUS_SHIFT);                      
    oSlang.addWord(VisionTopic::eFOCUS_MODE, VisionLanguage::FOCUS_MODE);                      
    addSlang(category, oSlang);    
}

// create slang for extra category
void VisionLanguage::defineExtraCategory()
{
    int category = VisionTopic::eCAT_VISION_EXTRA;
    addCategory(category, VisionLanguage::CAT_VISION_EXTRA);

    Slang oSlang;    
    oSlang.setCategory(category);
    oSlang.addWord(VisionTopic::eEXTRA_VISION_END, VisionLanguage::EXTRA_VISION_END);                      
    addSlang(category, oSlang);    
}

}