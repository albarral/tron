/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "talky/languages/BodyLanguage.h"
#include "talky/base/Slang.h"
#include "talky/topics/BodyTopic.h"
#include "talky/Topics.h"

namespace talky
{

BodyLanguage::BodyLanguage() 
{
}

void BodyLanguage::build()
{
    reset();

    // set body role topic
    setTopic(Topics::eTOPIC_BODYROLE);
    // define topic categories
    defineArmMoverCategory();
    defineExtraCategory();
}

// create slang for arm mover category
void BodyLanguage::defineArmMoverCategory()
{
    int category = BodyTopic::eCAT_BODY_ARMMOVER;
    addCategory(category, BodyLanguage::CAT_BODY_ARMMOVER);

    Slang oSlang;    
    oSlang.setCategory(category);
    oSlang.addWord(BodyTopic::eARMMOVER_TYPE, BodyLanguage::ARMMOVER_TYPE);                        
    oSlang.addWord(BodyTopic::eARMMOVER_ACTION, BodyLanguage::ARMMOVER_ACTION);                        
    oSlang.addWord(BodyTopic::eARMMOVER_TURN, BodyLanguage::ARMMOVER_TURN);                        
    oSlang.addWord(BodyTopic::eARMMOVER_WIDER, BodyLanguage::ARMMOVER_WIDER);                        
    oSlang.addWord(BodyTopic::eARMMOVER_TALLER, BodyLanguage::ARMMOVER_TALLER);                        
    oSlang.addWord(BodyTopic::eARMMOVER_FASTER, BodyLanguage::ARMMOVER_FASTER);                        
    addSlang(category, oSlang);    
}


// create slang for extra category
void BodyLanguage::defineExtraCategory()
{
    int category = BodyTopic::eCAT_BODY_EXTRA;
    addCategory(category, BodyLanguage::CAT_BODY_EXTRA);

    Slang oSlang;    
    oSlang.setCategory(category);
    oSlang.addWord(BodyTopic::eEXTRA_BODY_END, BodyLanguage::EXTRA_BODY_END);                      
    addSlang(category, oSlang);    
}

}